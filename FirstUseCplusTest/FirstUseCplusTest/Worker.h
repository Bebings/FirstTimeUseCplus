#pragma once
#include <iostream>
#include <string>


using namespace std;

class Worker
{
public:


	virtual void Show_Info() = 0;//��ʾ������Ϣ

	virtual string Get_DepName() = 0;//��ʾ��λ����
	
	int m_Id;  //ְ�����
	string m_Name;//ְ������
	int m_DepId;//���ű��

};


//Worker* worker = NULL;
//worker = new Employee(1, "����", 1);
//worker->Show_Info();
//delete worker;
//
//worker = new Manager(1, "����", 2);
//worker->Show_Info();
//delete worker;
//
//worker = new Boss(1, "����", 3);
//worker->Show_Info();
//delete worker;