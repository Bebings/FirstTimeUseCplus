#include <iostream>
#include "Boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Boss::Show_Info()//��ʾ������Ϣ
{
	cout << "�ϰ���: " << this->m_Id;
	cout << "\t�ϰ�����: " << this->m_Name;
	cout << "\t��λ: " << this->Get_DepName();
	cout << "\t��λְ��: ������������" << endl;
}

string Boss::Get_DepName()   //��ʾ��λ����
{
	return string("�ϰ�");
}