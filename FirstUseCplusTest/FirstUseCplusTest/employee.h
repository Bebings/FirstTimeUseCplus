#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:

	Employee(int id, string name, int dId);

	virtual void Show_Info();//��ʾ������Ϣ

	virtual string Get_DepName();//��ʾ��λ����

};