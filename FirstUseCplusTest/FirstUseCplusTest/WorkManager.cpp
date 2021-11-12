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
	//	cout << "�ļ�������"<< endl;	
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
	//	cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	int num = this->Get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
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
	cout << "******** ��ӭʹ��ְ������ϵͳ *******" << endl;
	cout << "*********** 0.�˳�����ϵͳ **********" << endl;
	cout << "*********** 1.����ְ����Ϣ **********" << endl;
	cout << "*********** 2.��ʾְ����Ϣ **********" << endl;
	cout << "*********** 3.ɾ����ְְ�� **********" << endl;
	cout << "*********** 4.�޸�ְ����Ϣ **********" << endl;
	cout << "*********** 5.����ְ����Ϣ **********" << endl;
	cout << "*********** 6.���ձ������ **********" << endl;
	cout << "*********** 7.��������ĵ� **********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System()
{
	cout << "��ӭ�´��ٴ�ʹ��!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;  //ԭ����¼������+�¼��������

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
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���λ" << endl;
			cout << "1.ְ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

			cin >> dSelect;

			while (dSelect > 3)
			{
				cout << "�����������λ" << endl;
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

		cout << "�ɹ������" << addnum<< "��ְ����" << endl;

		this->Save();
	}
	else
	{
		cout << "��������" << endl;
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

int WorkerManager::Get_EmpNum()//ͳ���ļ��е�����
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
		cout << "�ļ������ڻ���Ϊ��!" << endl;
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

int WorkerManager::IsExit_Emp(int id)  //�ж�ְ���Ƿ����ְ��
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

void WorkerManager::Del_Emp()  //ɾ��ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��!" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
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
			cout << "ɾ���ɹ��ˣ�" << endl;
		}
		else
		{
			cout << "Ҫɾ����ְ����Ų�����" << endl;
		}

	}
	system("Pause");
	system("cls");
}


void WorkerManager::Mod_Emp()  //�޸�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit_Emp(id);
		if (index != -1)
		{
			cout << "���ҵ�"<<id<<"��ְ����" << endl;

			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dSelect;

			cout << "�������µ�ְ�����" << endl;
			cin >> newId;
			cout << "�������µ�ְ������" << endl;
			cin >> newName;

			cout << "��ѡ���λ" << endl;
			cout << "1.ְ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			while (dSelect > 3)
			{
				cout << "�����������λ" << endl;
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
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ��" << endl;
			cout << "Ҫ�޸ĵ�ְ��������" << endl;
		}
	}
		system("Pause");
		system("cls");	
}



void WorkerManager::NameFind_Emp() //�ҵ�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų��ң�" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int index = this->IsExit_Emp(id);
			if (index != -1)
			{
				cout << "���ҵ�" << id << "��ְ����" << endl;
				this->m_EmpArray[index]->Show_Info();

			}
			else
			{
				cout << "���޴���" << endl;
			}

		}
		else if(select == 2)
		{
			int flag = 0;
			string name;
			cout << "������������" << endl;
			cin >> name;
			
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�" << endl;
					this->m_EmpArray[i]->Show_Info();
					flag = 1;

				}
			}

			if (flag == 0)
			{
				cout << "���޴���" << endl;
			}

		}
		else
		{
			cout << "��������" << endl;
		}

	}
	system("Pause");
	system("cls");
}


void WorkerManager::Sort_Emp() //�޸�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("Pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1.��ְ����������ţ�" << endl;
		cout << "2.��ְ����Ž�����" << endl;
		int select = -1;
		int minOrMax = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //����
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

	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->Save();
	this->Show_Emp();
	
}


void WorkerManager::Clr_Emp()  //�޸�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("Pause");
		system("cls");
	}
	else
	{
		cout << "ȷ����գ���" << endl;
		cout << "1.ȷ�ϣ�" << endl;
		cout << "2.����" << endl;
		int select = -1;
		cin >> select;

		if (select == 1) //ȷ��
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
				cout << "����ɹ�" << endl;
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