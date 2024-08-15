#include "speechManager.h"

SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->creatSpeaker();
	this->loadRecord();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exit_System()
{
	cout << "Thx for your using!" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->speakList.clear();
	this->com_Index = 1;
	this->m_Record.clear();
}

void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "Speaker ";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = 0.0;
		sp.m_Score[1] = 0.0;

		this->v1.push_back(i + 10001);
		this->speakList.insert(make_pair(v1[i], sp));
		//this->speakList.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::startSpeech() 
{
	speechDraw();

	speechContest();

	showScore();

	this->com_Index++;

	speechDraw();

	speechContest();

	showScore();

	saveRecord();

	this->initSpeech();

	this->creatSpeaker();

	this->loadRecord();

	cout << "This contest is finished!" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "The round " << this->com_Index << " Speaker choosing their order." << endl;
	cout << "The result sequence is the following list:" << endl;
	if (this->com_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
	//system("pause");
	cout << endl;

}

//void SpeechManager::testPrint(double d)
//{
//	cout << d << " ";
//}

void SpeechManager::speechContest()
{
	cout << "The round " << this->com_Index << " Contest starts." << endl;

	//��ʱ��������key�����Ͷ�Ӧ��ѡ�ֱ�ţ�����map���Զ�������ص�
	multimap<double, int, greater<double>> temp_groupScore;

	int num = 0; //��¼��Ա����6��Ϊ1��

	vector <int>v_Src;   //��������Ա����
	if (this->com_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it!=v_Src.end(); it++)
	{
		num++;

		deque<double> scores;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end(), greater<double>());
		scores.pop_front();
		scores.pop_back();
		/*for_each(scores.begin(), scores.end(), [this](double score) {
			this->testPrint(score);
			});
		cout << endl;*/

		double sum = accumulate(scores.begin(), scores.end(), 0.0f);
		double avg = sum / (double)scores.size();

		this->speakList[*it].m_Score[this->com_Index - 1] = avg;

		temp_groupScore.insert(make_pair(avg, *it));

		if (num%6 == 0)
		{
			cout << "The Number " << num / 6 << " group's sequece is:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = temp_groupScore.begin(); it!= temp_groupScore.end(); it++)
			{
				cout << "Number: " << it->second << " Name: " << this->speakList[it->second].m_Name << " Score: " << it->first << endl;
			}
			
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it =  temp_groupScore.begin(); it != temp_groupScore.end() && count < 3; it++, count++)
			{
				if (this->com_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					v3.push_back(it->second);
				}
			}

			temp_groupScore.clear();
			cout << endl;
		}
	}
	
	cout << "The contest round " << this->com_Index << " have finished." << endl;
	cout << endl;

}

void SpeechManager::showScore()
{
	cout << "----- The " << this->com_Index << " round winner for next round are:" << endl;
	vector<int> temp_v;
	if (this->com_Index == 1)
	{
		temp_v = v2;
	}
	else
	{
		temp_v = v3;
	}

	for (vector<int>::iterator it = temp_v.begin(); it != temp_v.end(); it++)
	{
		cout << "Number: " << *it << " Name: " << this->speakList[*it].m_Name << " Score: " << this->speakList[*it].m_Score[this->com_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ","
			<< speakList[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;

	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "File does not exist." << endl;
		ifs.close();
		return;
	}

	//��Ҫ�ȶ�һ��һ���ַ���ifs����֪���Ƿ������β�ˡ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		cout << "File is empty." << endl;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;
	ifs.putback(ch); // ������������ַ��ٶ�����

	string data;
	int index = 0;

	while (ifs >> data)
	{
		vector<string> temp_v;
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			temp_v.push_back(temp);
			start = pos + 1;

		}
		this->m_Record.insert(make_pair(index, temp_v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "File does not exist, or the record is empty." << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "The " << i + 1 << ". Speech Contest " <<
				"1st Number: " << this->m_Record[i][0] << " Score:" << this->m_Record[i][1] << " " <<
				"2nd Number: " << this->m_Record[i][2] << " Score:" << this->m_Record[i][3] << " " <<
				"3rd Number: " << this->m_Record[i][4] << " Score:" << this->m_Record[i][5] << endl;
		}
	}

	

	system("pause");
	system("cls");
}

void SpeechManager::cleanRecord()
{
	cout << "Are you sure to clean record?" << endl;
	cout << "1. Sure" << endl;
	cout << "2. Cancel" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{	//ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->creatSpeaker();

		this->loadRecord();

		cout << "Clearing is successful." << endl;
	}

	system("pause");
	system("cls");
}