#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee(int id , string name , int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Employee::Show_Info()//��ʾ������Ϣ
{
	cout << "ְ�����: " << this->m_Id;
	cout << "\tְ������: " << this->m_Name;
	cout << "\t��λ: " << this->Get_DepName();
	cout << "\t��λְ��:��ɾ��������� " << endl;
}

string Employee::Get_DepName()   //��ʾ��λ����
{
	return string("Ա��");
}