//
// Created by superuse on 2024/1/18.
//

#include "employee.h"
#include <iostream>
using namespace std;

/**
 * 静态成员变量必须要在类内声明, 在类外初始化
 */

/* 临时工的人数赋初值为0 (定义) !!! */
int FormalWorker::formalCount = 0;

/* 临时工的总工资赋初值为0 (定义) */
double FormalWorker::totalSalary = 0;

FormalWorker::FormalWorker()
{
    this->tax = 0;
    this->realSalary = getBasicSalary();
    formalCount++;
    totalSalary += 0;
}

/* 注意: 子类的有参构造函数中, 一定要给父类的属性赋值 */
FormalWorker::FormalWorker(string name, double basicSalary, string sex, string department,int ID, int phone_number ) : Worker(name, basicSalary)
{
    this->tax = tax; this->sex=sex; this->departme=department; this->ID=ID;this->phone_number=phone_number;
    this->realSalary = getBasicSalary() - tax; this->name=name; this->basicSalary=basicSalary;
    formalCount++;
    totalSalary += realSalary;
}

FormalWorker::~FormalWorker()
{
    formalCount--;
    totalSalary -= realSalary;
}

double FormalWorker::getRealSalary()
{
    return realSalary;
}

double FormalWorker::getTax()
{
    return tax;
}

/* 输出正式职工的姓名、基本工资、所得税、实发工资 */
void FormalWorker::show()
{
    if(this->name.length()==4){
        cout << getName() << "\t\t" << get_basic_salary() << "\t" << getSex() << "\t" << getDepartment()
    << "\t"<<getID()<<"\t"<<getPhoneNumber();
    }
    else{cout << getName() << "\t" << get_basic_salary() << "\t" << getSex() << "\t" << getDepartment()
    << "\t"<<getID()<<"\t"<<getPhoneNumber();}
}

/* 输出正式职工的总数 */
void FormalWorker::showCount()
{
    cout << "正式职工的总人数为: " << formalCount << endl;
}

/* 输出正式职工的总工资、平均工资 */
void FormalWorker::showSalary()
{
    cout << "正式职工的总工资为: " << totalSalary << endl;
    cout << "正式职工的平均工资为: " << totalSalary / formalCount << endl << endl;
}

string FormalWorker::getSex() {
    return sex;
}

string FormalWorker::getDepartment()   {
    return std::string(departme);
}

int FormalWorker::getID() const {
    return ID;
}

int FormalWorker::getPhoneNumber() const {
    return phone_number;
}

string FormalWorker::getName() {
    return name;
}

double FormalWorker::get_basic_salary() {
    return basicSalary;getBasicSalary();
}

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, FormalWorker& f)
{
    cout << f.getName() << "\t" << f.getBasicSalary() << "\t"
         << f.getTax()  << "\t" << f.getRealSalary()  << endl;
    return cout;
}