#include <iostream>
#include "WorkManager.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
#include <fstream>
using namespace std;


WorkerManager::WorkerManager()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
	//	cout << "文件不存在"<< endl;	
		this->m_EmpNum = 0;	
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
	//	cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	int num = this->Get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();



}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "*************************************" << endl;
	cout << "******** 欢迎使用职工管理系统 *******" << endl;
	cout << "*********** 0.退出管理系统 **********" << endl;
	cout << "*********** 1.增加职工信息 **********" << endl;
	cout << "*********** 2.显示职工信息 **********" << endl;
	cout << "*********** 3.删除离职职工 **********" << endl;
	cout << "*********** 4.修改职工信息 **********" << endl;
	cout << "*********** 5.查找职工信息 **********" << endl;
	cout << "*********** 6.按照编号排序 **********" << endl;
	cout << "*********** 7.清空所有文档 **********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System()
{
	cout << "欢迎下次再次使用!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量:" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;  //原来记录的人数+新加入的人数

		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择岗位" << endl;
			cout << "1.职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> dSelect;

			while (dSelect > 3)
			{
				cout << "请重新输入岗位" << endl;
				cin >> dSelect;
				if (dSelect <= 3) break;
			}

			Worker* worker = NULL;

			switch (dSelect)
			{
				case 1:
					worker = new Employee(id, name, dSelect);
					break;
				case 2:
					worker = new Manager(id, name, dSelect);
					break;
				case 3:
					worker = new Boss(id, name, dSelect);
					break;
				default:
					break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}
		 
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout << "成功添加了" << addnum<< "个职工！" << endl;

		this->Save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("Pause");
	system("cls");
}


void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}

	ofs.close();

}

int WorkerManager::Get_EmpNum()//统计文件中的人数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >>dId)
	{
		num++;
	}

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int Index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[Index] = worker;
		Index++;
	}

	ifs.close();

}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->Show_Info();
		}
	}

	system("Pause");
	system("cls");

}

int WorkerManager::IsExit_Emp(int id)  //判断职工是否存在职工
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp()  //删除职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空!" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit_Emp(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->Save();
			cout << "删除成功了：" << endl;
		}
		else
		{
			cout << "要删除的职工编号不存在" << endl;
		}

	}
	system("Pause");
	system("cls");
}


void WorkerManager::Mod_Emp()  //修改职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit_Emp(id);
		if (index != -1)
		{
			cout << "查找到"<<id<<"号职工了" << endl;

			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dSelect;

			cout << "请输入新的职工编号" << endl;
			cin >> newId;
			cout << "请输入新的职工姓名" << endl;
			cin >> newName;

			cout << "请选择岗位" << endl;
			cout << "1.职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			while (dSelect > 3)
			{
				cout << "请重新输入岗位" << endl;
				cin >> dSelect;
				if (dSelect <= 3) break;
			}

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			this->Save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败" << endl;
			cout << "要修改的职工不存在" << endl;
		}
	}
		system("Pause");
		system("cls");	
}



void WorkerManager::NameFind_Emp() //找到职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入差找的方式：" << endl;
		cout << "1.按职工编号查找：" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入职工编号：" << endl;
			int id = 0;
			cin >> id;
			int index = this->IsExit_Emp(id);
			if (index != -1)
			{
				cout << "查找到" << id << "号职工了" << endl;
				this->m_EmpArray[index]->Show_Info();

			}
			else
			{
				cout << "查无此人" << endl;
			}

		}
		else if(select == 2)
		{
			int flag = 0;
			string name;
			cout << "请输入姓名：" << endl;
			cin >> name;
			
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功" << endl;
					this->m_EmpArray[i]->Show_Info();
					flag = 1;

				}
			}

			if (flag == 0)
			{
				cout << "查无此人" << endl;
			}

		}
		else
		{
			cout << "输入有误" << endl;
		}

	}
	system("Pause");
	system("cls");
}


void WorkerManager::Sort_Emp() //修改职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("Pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1.按职工编号升序排：" << endl;
		cout << "2.按职工编号降序排" << endl;
		int select = -1;
		int minOrMax = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}


	}

	cout << "排序成功！排序后的结果为：" << endl;
	this->Save();
	this->Show_Emp();
	
}


void WorkerManager::Clr_Emp()  //修改职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("Pause");
		system("cls");
	}
	else
	{
		cout << "确认清空？：" << endl;
		cout << "1.确认：" << endl;
		cout << "2.返回" << endl;
		int select = -1;
		cin >> select;

		if (select == 1) //确认
		{
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);
			ofs.close();
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}

				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
				cout << "清除成功" << endl;
			}

			system("Pause");
			system("cls");

		}
		else
		{
			system("cls");
		}
	}
}