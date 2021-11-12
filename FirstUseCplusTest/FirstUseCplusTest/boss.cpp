#include <iostream>
#include "Boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Boss::Show_Info()//显示个人信息
{
	cout << "老板编号: " << this->m_Id;
	cout << "\t老板姓名: " << this->m_Name;
	cout << "\t岗位: " << this->Get_DepName();
	cout << "\t岗位职责: 管理所有事物" << endl;
}

string Boss::Get_DepName()   //显示岗位名称
{
	return string("老板");
}