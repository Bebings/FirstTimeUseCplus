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

	virtual void Show_Info();//��ʾ������Ϣ

	virtual string Get_DepName();//��ʾ��λ����

};