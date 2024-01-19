//
// Created by superuse on 2024/1/18.
//

#ifndef SALARY_MANAGE_SYSTEM_EMPLOYEE_H
#define SALARY_MANAGE_SYSTEM_EMPLOYEE_H
#pragma once
#include "worker.h"
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
class FormalWorker : public Worker
{
private:
    string name;         // ����
    string sex ; //�Ա�
    int ID; //����
    int phone_number ; //�绰����
    string departme; // ���ڿ���
    double basicSalary;  // ����ְ����
    double tax;                 // ����˰
    double deduction_salary;  //�۳��Ĺ���
    double realSalary;          // ʵ������
    double allowance ;//����
    static int formalCount;     // ��̬��������: ��ʽְ��������   (ֻ������, ���⻹��Ҫ��cpp�ļ��ж��� !!!)
    static double totalSalary;  // ��̬��������: ��ʽְ���ܹ��ʡ�ƽ������
public:
    FormalWorker();
    FormalWorker(string name, double basicSalary, string sex, string department , int ID ,int phone_number);
    ~FormalWorker() override;
    string getName(); double get_basic_salary();
    double getTax();string getSex(); string getDepartment();
    double getRealSalary();  int getID() const; int getPhoneNumber() const;
    string set_name(string name) {
        this->name=name;
        return 0;
    }

    double set_basic_salary(double salary) {
        this->basicSalary=salary;
        return 0 ;
    }
    string set_sex(string sex ) {
        this->sex=sex;
        return 0;
    }

    string  set_department(string department) {
this->departme=department;
    }

    int set_ID(int id) {
        this->ID=id;
        return 0;
    }

    int set_phone_number(int number) {
        this->phone_number=number;
        return 0;
    }

    void show();                // �����ʽְ�����������������ʡ�����˰��ʵ������
     void showCount()  override;    // �����ʽְ��������  ��̬����������д�麯��
     void showSalary() override;   // �����ʽְ�����ܹ��ʡ�ƽ������
};

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, FormalWorker& f);
class employee {

};


#endif //SALARY_MANAGE_SYSTEM_EMPLOYEE_H
