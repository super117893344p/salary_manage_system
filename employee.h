//
// Created by superuse on 2024/1/18.
//

#ifndef SALARY_MANAGE_SYSTEM_EMPLOYEE_H
#define SALARY_MANAGE_SYSTEM_EMPLOYEE_H
#pragma once
#include "worker.h"
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
class FormalWorker : public Worker
{
private:
    string name;         // 姓名
    string sex ; //性别
    int ID; //工号
    int phone_number ; //电话号码
    string departme; // 所在科室
    double basicSalary;  // 基本职务工资
    double tax;                 // 所得税
    double deduction_salary;  //扣除的工资
    double realSalary;          // 实发工资
    double allowance ;//津贴
    static int formalCount;     // 静态数据类型: 正式职工总人数   (只是声明, 另外还需要在cpp文件中定义 !!!)
    static double totalSalary;  // 静态数据类型: 正式职工总工资、平均工资
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

    void show();                // 输出正式职工的姓名、基本工资、所得税、实发工资
     void showCount()  override;    // 输出正式职工的总数  静态函数不能重写虚函数
     void showSalary() override;   // 输出正式职工的总工资、平均工资
};

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, FormalWorker& f);
class employee {

};


#endif //SALARY_MANAGE_SYSTEM_EMPLOYEE_H
