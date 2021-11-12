#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee(int id , string name , int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void Employee::Show_Info()//显示个人信息
{
	cout << "职工编号: " << this->m_Id;
	cout << "\t职工姓名: " << this->m_Name;
	cout << "\t岗位: " << this->Get_DepName();
	cout << "\t岗位职责:完成经理交代任务 " << endl;
}

string Employee::Get_DepName()   //显示岗位名称
{
	return string("员工");
}