#pragma once
#include <iostream>
#include <string>

using namespace std;

class Speaker
{
public:
	Speaker();
	~Speaker();
	
	string m_Name;
	double m_Score[2];
};