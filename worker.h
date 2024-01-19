//
// Created by superuse on 2024/1/18.
//

#ifndef SALARY_MANAGE_SYSTEM_WORKER_H
#define SALARY_MANAGE_SYSTEM_WORKER_H

#pragma once         // ��ֹͷ�ļ��ظ�����
#include <string>
using namespace std;

class Worker
{
private:
    string name;         // ����
    double basicSalary;  // ����ְ����
public:
    bool flag;           // 0��ʾ���ɷ���, 1��ʾ�ɷ���

    Worker();
    Worker(string name, double basicSalary);
    virtual ~Worker();

    double getBasicSalary();
    string getName();
    void setName(string name);
    //void setBasicSalary(double basicSalary);

    virtual void show();
    virtual void showCount();    // ���ﲻ�ܼ���static, ��Ϊ: ���Ǿ�̬��Ա�����ǿ��������
    virtual void showSalary();   // ���ﲻ�ܼ���static, ��Ϊ: ���Ǿ�̬��Ա�����ǿ��������
};

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, Worker& w);

#endif //SALARY_MANAGE_SYSTEM_WORKER_H
