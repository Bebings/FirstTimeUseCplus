#pragma once
#include <iostream>
#include <string>


using namespace std;

class Worker
{
public:


	virtual void Show_Info() = 0;//显示个人信息

	virtual string Get_DepName() = 0;//显示岗位名称
	
	int m_Id;  //职工编号
	string m_Name;//职工名字
	int m_DepId;//部门编号

};


//Worker* worker = NULL;
//worker = new Employee(1, "张三", 1);
//worker->Show_Info();
//delete worker;
//
//worker = new Manager(1, "李四", 2);
//worker->Show_Info();
//delete worker;
//
//worker = new Boss(1, "王五", 3);
//worker->Show_Info();
//delete worker;