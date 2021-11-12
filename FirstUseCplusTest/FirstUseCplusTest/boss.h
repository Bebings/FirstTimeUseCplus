#pragma once
#include <iostream>
#include <string>
#include "Worker.h"

using namespace std;

class Boss : public Worker
{
public:

	Boss(int id, string name, int dId);

	virtual void Show_Info();//显示个人信息

	virtual string Get_DepName();//显示岗位名称

};
