#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
// ְ����Ϣ�ṹ��
/* ��ϵͳ�ڴ����ϴ洢��ĳ��λȫ��ְ���Ĺ�����Ϣ������ÿλְ���洢������Ϣ��ְ����š��������ʡ�������������������Ӧ��������������˰��Ӧ������ʵ������
 * ��������˰���㷽����Ϊ����������1100Ԫ�Ĳ���Ϊ0��1100��1600Ԫ����Ϊ5%��1600��2600����Ϊ10%��
2600��3600����Ϊ15%��5600Ԫ���ϲ���Ϊ20%��
 ϵͳ����Ҫ�����£�
�����洢ְ��������Ϣ�Ĵ洢�ļ������ĳְ���Ĺ�����Ϣ��ɾ��ĳְ���Ĺ�����Ϣ��
 �޸�ĳְ���Ĳ��ֹ�����Ϣ�����¿�ʼ���ӻ����ĳЩ��ʻ�ۿ����仯��
 �����ָ�����ְ���Ĺ�����Ϣ����ѯ�ã���
 ���ȫ��ְ���Ĺ�����Ϣ���������ã���  ��ɾ�Ĳ�
 * */
/*����ְ����employee ���࣬�������ٰ����������Ա𡢹��š��绰�����ڿ��Һ͹��ʡ�*/
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
using namespace std;
//�˵�����
#include "salary_management.h"
#define employee_information "A:/Clion/Clion_cpp_project/salary_manage_system/employee_information.txt"
int main()
{
    int num=1000;
    vector<FormalWorker*> pFormalWorker(num);   // �൱��Worker* pFormalWorker[num];
    pFormalWorker.resize(num);      // ��pFormalWorker������Ԫ�ظ�������num��, ����ɾ, ����, ��ֵΪ0
   // input(pFormalWorker, num);
    reloadFromFile(employee_information, pFormalWorker  );
    int choice;
    while (true) {
        menu: myMenu();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n����������ѡ��(0-8) ";
        cin >> choice;
        switch (choice) {
            case 100:
                goto menu;break;
            case 1:
                input(pFormalWorker);
                break;
            case 2:
                deleteFormalWorkerByName(pFormalWorker);
                break;
            case 3:
                modifyFormalWorkerByName(pFormalWorker);
                break;
            case 4:
                queryFormalWorkerByName(pFormalWorker);
                break;
            case 5:
                clearFormalWorkerByName(pFormalWorker);
                break;
            case 6:
                output(pFormalWorker);
                break;
            case 7:
                showFormalWorkerSalary(pFormalWorker);
                break;
            case 8:
                showFormalWorkerNum ( pFormalWorker);
                break;
            case 0:
                deleteAllFormalWorker(pFormalWorker);
                cout << "�ɹ��˳�ϵͳ��byebye" << endl;exit(0);
                return 0;  // �˳�����
            default:
                cout << "������������, ����������0-8֮�������" << endl;
                break;
        }
          system("pause");
		  system("cls");
    }
     return 0 ;
}