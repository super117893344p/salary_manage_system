//
// Created by superuse on 2024/1/18.
//

#ifndef SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H
#define SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "worker.h"  //  Windows������ include�������ļ�����Сд ��Linux����������
#include "employee.h"
using namespace std;

const int MAX_SIZE = 100;                                     // ְ�����������

void myMenu();                                                // ��ʾ�˵�
void input(vector<FormalWorker*>& pFormalFormalWorker);                // ����ְ����Ϣ          (һ��Ҫ�ǵü�����&����)
void output(vector<FormalWorker*>& pFormalFormalWorker );               // ���ְ����Ϣ
void queryFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorke);    // ��������������ְ����Ϣ
void modifyFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // �����������޸�ְ����Ϣ
void deleteFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // ����������ɾ��ְ����Ϣ (�ɻָ�)
void clearFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);   // ����������ɾ��ְ����Ϣ (���ɻָ�)
void recoverFormalWorkerByName(vector<FormalWorker*>& pFormalFormalWorker);  // �����������ָ�һ��ְ����Ϣ
void deleteAllFormalWorker(vector<FormalWorker*>& pFormalFormalWorker);      // ��ѭ����ɾ��ָ������
void showFormalWorkerNum(vector<FormalWorker*>& pFormalFormalWorker);        // ��ʾ����ְ��������
void showFormalWorkerSalary(vector<FormalWorker*>& pFormalFormalWorker);     // ��ʾְ���ܵ�ʵ�����ʡ�ƽ��ʵ������
void saveToFile(const string& filename, vector<FormalWorker*> &FormalWorker);
void reloadFromFile(const string& filename,vector<FormalWorker*> &FormalWorker);
class salary_management {

};


#endif //SALARY_MANAGE_SYSTEM_SALARY_MANAGEMENT_H
