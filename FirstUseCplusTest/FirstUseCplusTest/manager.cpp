#include <iostream>
#include "manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Manager::Show_Info()//��ʾ������Ϣ
{
	cout << "������: " << this->m_Id;
	cout << "\t��������: " << this->m_Name;
	cout << "\t��λ: " << this->Get_DepName();
	cout << "\t��λְ��:����ϰ彻��ְ���·����� " << endl;
}

string Manager::Get_DepName()   //��ʾ��λ����
{
	return string("����");
}