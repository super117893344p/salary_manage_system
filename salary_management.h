//
// Created by superuse on 2024/1/18.
//

#ifndef SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H
#define SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "worker.h"  //  Windows环境下 include不区分文件名大小写 而Linux环境下区分
#include "employee.h"
using namespace std;

const int MAX_SIZE = 100;                                     // 职工的最大人数

void myMenu();                                                // 提示菜单
void input(vector<FormalWorker*>& pFormalFormalWorker);                // 输入职工信息          (一定要记得加引用&符号)
void output(vector<FormalWorker*>& pFormalFormalWorker );               // 输出职工信息
void queryFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorke);    // 根据姓名来查找职工信息
void modifyFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // 根据姓名来修改职工信息
void deleteFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // 根据姓名来删除职工信息 (可恢复)
void clearFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // 根据姓名来删除职工信息 (不可恢复)
void recoverFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);  // 根据姓名来恢复一个职工信息
void deleteAllFormalWorker(vector<FormalWorker*>& pFormalFormalWorker);      // 用循环来删除指针数组
void showFormalWorkerNum(vector<FormalWorker*>& pFormalFormalWorker);        // 显示各种职工的人数
void showFormalWorkerSalary(vector<FormalWorker*>& pFormalFormalWorker);     // 显示职工总的实发工资、平均实发工资
void saveToFile(const string& filename, vector<FormalWorker*> &FormalWorker);
void reloadFromFile(const string& filename,vector<FormalWorker*> &FormalWorker);
class salary_management {

};


#endif //SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H
