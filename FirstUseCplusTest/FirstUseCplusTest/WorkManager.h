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
	

	int m_EmpNum;//记录职工人数

	bool m_FileIsEmpty;

	Worker** m_EmpArray;

	WorkerManager();//构造函数

	~WorkerManager();//析构函数

	void Show_Menu();//显示菜单

	void Exit_System();//退出程序

	void Add_Emp();//添加员工

	void Save();//保存数据

    int Get_EmpNum();//统计文件中的人数

	void init_Emp();

	void Show_Emp();  //显示职工

	int IsExit_Emp(int id);  //判断职工是否存在职工

	void Del_Emp();  //删除职工

	void Mod_Emp();  //修改职工

	void NameFind_Emp();  //修改职工

	void Sort_Emp();  //修改职工

	void Clr_Emp();  //修改职工


};

