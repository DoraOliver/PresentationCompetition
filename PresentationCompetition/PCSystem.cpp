#include <iostream>
#include "speechManager.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	int choice = 0;

	for (map<int, Speaker>::iterator it = sm.speakList.begin(); it != sm.speakList.end() ; it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << " Name:" << it->second.m_Name << " Score:" << it->second.m_Score[0] << endl;
	}

	while (true)
	{
		sm.Show_Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1:  //��ʼ����
			sm.startSpeech();
			break;
		case 2:  //�鿴��¼
			sm.showRecord();
			break;
		case 3:  //��ռ�¼
			sm.cleanRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.exit_System();
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	system("pause");

	return 0;
}