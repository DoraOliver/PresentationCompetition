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
		cout << "选手编号：" << it->first << " Name:" << it->second.m_Name << " Score:" << it->second.m_Score[0] << endl;
	}

	while (true)
	{
		sm.Show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice)
		{
		case 1:  //开始比赛
			sm.startSpeech();
			break;
		case 2:  //查看记录
			sm.showRecord();
			break;
		case 3:  //清空记录
			sm.cleanRecord();
			break;
		case 0:  //退出系统
			sm.exit_System();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	system("pause");

	return 0;
}