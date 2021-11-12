#include <iostream>
#include "manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Manager::Show_Info()//显示个人信息
{
	cout << "经理编号: " << this->m_Id;
	cout << "\t经理姓名: " << this->m_Name;
	cout << "\t岗位: " << this->Get_DepName();
	cout << "\t岗位职责:完成老板交的职责，下发任务 " << endl;
}

string Manager::Get_DepName()   //显示岗位名称
{
	return string("经理");
}