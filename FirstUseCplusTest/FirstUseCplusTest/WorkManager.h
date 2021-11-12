#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
#include "employee.h"
#include "Boss.h"
#include "manager.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager 
{
public:
	

	int m_EmpNum;//��¼ְ������

	bool m_FileIsEmpty;

	Worker** m_EmpArray;

	WorkerManager();//���캯��

	~WorkerManager();//��������

	void Show_Menu();//��ʾ�˵�

	void Exit_System();//�˳�����

	void Add_Emp();//���Ա��

	void Save();//��������

    int Get_EmpNum();//ͳ���ļ��е�����

	void init_Emp();

	void Show_Emp();  //��ʾְ��

	int IsExit_Emp(int id);  //�ж�ְ���Ƿ����ְ��

	void Del_Emp();  //ɾ��ְ��

	void Mod_Emp();  //�޸�ְ��

	void NameFind_Emp();  //�޸�ְ��

	void Sort_Emp();  //�޸�ְ��

	void Clr_Emp();  //�޸�ְ��


};

