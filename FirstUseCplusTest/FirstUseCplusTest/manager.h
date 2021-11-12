#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
#include "manager.h"
using namespace std;

class Manager : public Worker
{
public:

	Manager(int id, string name, int dId);

	virtual void Show_Info();//显示个人信息

	virtual string Get_DepName();//显示岗位名称

};