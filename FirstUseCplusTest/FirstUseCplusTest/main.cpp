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
		cout << "��������ֵ: " << endl;
		cin >> Change_Flag;

		switch (Change_Flag)
		{
		case 0:			//�˳�����ϵͳ
			WM.Exit_System();
			break;
		case 1:			//����ְ����Ϣ
			WM.Add_Emp();
		    break;
		case 2:			//��ʾְ����Ϣ
			WM.Show_Emp();
			break;
		case 3:			//ɾ����ְְ��
			WM.Del_Emp();
			break;
		case 4:			//�޸�ְ����Ϣ
			WM.Mod_Emp();
			break;
		case 5:			//����ְ����Ϣ
			WM.NameFind_Emp();
			break;
		case 6:			//���ձ������
			WM.Sort_Emp();
			break;
		case 7:			//��������ĵ�
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
