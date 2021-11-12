#include <iostream>
#include "Worker.h"
#include "WorkManager.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"

using namespace std;
int main()
{

	WorkerManager WM;

	int Change_Flag =0 ;
	while (1)
	{
		WM.Show_Menu();
		cout << "请输入数值: " << endl;
		cin >> Change_Flag;

		switch (Change_Flag)
		{
		case 0:			//退出管理系统
			WM.Exit_System();
			break;
		case 1:			//增加职工信息
			WM.Add_Emp();
		    break;
		case 2:			//显示职工信息
			WM.Show_Emp();
			break;
		case 3:			//删除离职职工
			WM.Del_Emp();
			break;
		case 4:			//修改职工信息
			WM.Mod_Emp();
			break;
		case 5:			//查找职工信息
			WM.NameFind_Emp();
			break;
		case 6:			//按照编号排序
			WM.Sort_Emp();
			break;
		case 7:			//清空所有文档
			WM.Clr_Emp();
			break;
		default:
			system("cls");
			break;
		}

	}//while
	system("pause");

	return 0;
}
