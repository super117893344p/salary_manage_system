#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
// 职工信息结构体
/* 该系统在磁盘上存储了某单位全体职工的工资信息。对于每位职工存储以下信息：职工编号、基本工资、津贴、岗贴、补贴、应发数、个人所得税、应扣数、实发数。
 * 个人所得税计算方法设为：工资少于1100元的部分为0，1100—1600元部分为5%，1600—2600部分为10%，
2600—3600部分为15%，5600元以上部分为20%。
 系统功能要求如下：
创建存储职工工资信息的存储文件。添加某职工的工资信息。删除某职工的工资信息。
 修改某职工的部分工资信息（当月开始增加或减少某些项工资或扣款数变化）
 。输出指定编号职工的工资信息（查询用）。
 输出全体职工的工资信息（发工资用）。  增删改查
 * */
/*定义职工（employee ）类，其中至少包括姓名、性别、工号、电话、所在科室和工资。*/
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
using namespace std;
//菜单函数
#include "salary_management.h"
#define employee_information "A:/Clion/Clion_cpp_project/salary_manage_system/employee_information.txt"
int main()
{
    int num=1000;
    vector<FormalWorker*> pFormalWorker(num);   // 相当于Worker* pFormalWorker[num];
    pFormalWorker.resize(num);      // 将pFormalWorker的现有元素个数调至num个, 多则删, 少则补, 其值为0
   // input(pFormalWorker, num);
    reloadFromFile(employee_information, pFormalWorker  );
    int choice;
    while (true) {
        menu: myMenu();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n请输入您的选择(0-8) ";
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
                cout << "成功退出系统。byebye" << endl;exit(0);
                return 0;  // 退出程序
            default:
                cout << "您的输入有误, 请重新输入0-8之间的数。" << endl;
                break;
        }
          system("pause");
		  system("cls");
    }
     return 0 ;
}