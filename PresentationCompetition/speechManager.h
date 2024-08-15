#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>

using namespace std;

class SpeechManager
{
public:

	SpeechManager();

	~SpeechManager();

	void Show_Menu();

	void exit_System();

	void initSpeech();

	void creatSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void cleanRecord();

	//void testPrint(double d);

	//Memeber
	vector<int> v1;

	vector<int> v2;

	vector<int> v3;

	map<int, Speaker> speakList;

	int com_Index;

	bool fileIsEmpty;

	map<int, vector<string>> m_Record;

private:
	
};