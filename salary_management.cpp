//
// Created by superuse on 2024/1/18.
//

#include "salary_management.h"
#include<fstream>
#include<iostream>

#define  data_file_path "A:/Clion/Clion_cpp_project/salary_manage_system/employee_information.txt"
//clion里面的文件路径千万不能用\反斜杠 而是/
static int number;

void myMenu() {
    cout << "====================================== 职工工资管理系统 =======================================" << endl;
    cout << "     1 增加职工记录           　 2 删除职工记录 (可恢复)      " << endl;
    cout << "     3 修改职工记录            　4 查找职工记录              " << endl;
    cout << "     5 删除职工记录 (不可恢复) 　 6 显示职工记录                " << endl;
    cout << "     7  统计职工工资             8 统计职工人数      " << endl;
    cout << "     0 退出系统                Designed By YZG     " << endl;
    cout << "===============================================================================================" << endl;
}

//覆盖模式
void save_revise_to_file(const std::string &filePath, std::vector<FormalWorker *> &pFormalWorker) {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "无法打开文件进行保存" << std::endl;
        return;
    }

    for (int j = 0; j < number; j++) {
        if (pFormalWorker[j]->flag) {
            // 在这里根据你的数据结构输出每个职工的信息到文件
            // 在这里根据你的数据结构输出每个职工的信息到文件
            outputFile << pFormalWorker[j]->getName() << " "
                       << pFormalWorker[j]->getBasicSalary() << " "
                       << pFormalWorker[j]->getSex() << " "
                       << pFormalWorker[j]->getDepartment() << " "
                       << pFormalWorker[j]->getID() << " "
                       << pFormalWorker[j]->getPhoneNumber() << std::endl;
        }
    }

    outputFile.close();
}

void saveToFile(const std::string &filename, vector<FormalWorker *> &pFormalWorker) {
    std::ofstream file(filename, std::ios::app);  // 使用追加模式，防止覆盖原有内容
    if (file.is_open()) {
        for (int i = 0; i < number; ++i) {
            file << pFormalWorker[i]->getName() << " " << pFormalWorker[i]->getBasicSalary() << " "
                 << pFormalWorker[i]->getSex() << " "
                 << pFormalWorker[i]->getDepartment() << " " << pFormalWorker[i]->getID() << " "
                 << pFormalWorker[i]->getPhoneNumber() << endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}//追加模式

// 从文件加载
void reloadFromFile(const std::string &filename, vector<FormalWorker *> &pFormalWorker) {
    std::ifstream file(filename);
    string name;
    int i, ID, phonenumber;
    string sex, department;
    double basicSalary;
    i = 0;
    if (file.is_open()) {
        while (file >> name >> basicSalary >> sex >> department >> ID >> phonenumber) {
            // 创建 FormalWorker 对象并添加到相应的容器中
            FormalWorker *PFormalWorker = new FormalWorker(name, basicSalary, sex, department, ID, phonenumber);
            pFormalWorker[i] = PFormalWorker;
            i++;
        }
        for (int j = 0; j < i; j++) {//防止越界问题, 不要用pFormalWorker.size()
            pFormalWorker[j]->flag = true;//
        }
        number = i;
        cout << "数据导入成功" << endl;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

#include <cstdio>  // 用于删除文件的头文件

const std::string backup_file_path = "backup_file.txt";

void backupFile(const std::string &sourcePath, const std::string &backupPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream backupFile(backupPath, std::ios::binary);

    if (sourceFile.is_open() && backupFile.is_open()) {
        backupFile << sourceFile.rdbuf();
        std::cout << "文件备份成功" << std::endl;
    } else {
        std::cerr << "文件备份失败" << std::endl;
    }

    sourceFile.close();
    backupFile.close();
}

void deleteFile(const std::string &filePath) {
    if (std::remove(filePath.c_str()) == 0) {
        std::cout << "文件删除成功" << std::endl;
    } else {
        std::cerr << "文件删除失败" << std::endl;
    }
}

void restoreFile(const std::string &sourcePath, const std::string &destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream destinationFile(destinationPath, std::ios::binary);

    if (sourceFile.is_open() && destinationFile.is_open()) {
        destinationFile << sourceFile.rdbuf();
        std::cout << "文件恢复成功" << std::endl;
    } else {
        std::cerr << "文件恢复失败" << std::endl;
    }

    sourceFile.close();
    destinationFile.close();
}

/* 输入职工信息 */
void
input(vector<FormalWorker *> &pFormalWorker)           // 相当于void input(FormalWorker* pFormalWorker[], int number)
{
    string name;        // 姓名
    double basicSalary; // 基本工资
    double tax;         // 所得税
    double bonus;       // 奖金
    char choice = 'f';
    string sex;
    string department;
    int id;
    int phone_number;
    if (true) {
        cout << "输入名字" << endl;
        cin >> name;
        cout << "输入基础薪资 " << endl;
        cin >> basicSalary;
        cout << "性别" << endl;
        cin >> sex;
        cout << "所在部门" << endl;
        cin >> department;
        cout << "职工工号" << endl;
        cin >> id;
        cout << "电话号码" << endl;
        cin >> phone_number;
        number = number + 1;
        //FormalWorker fFormalWorker(name, basicSalary, tax);
        //pFormalWorker[i] = &fFormalWorker;    // 不行: 在循环内创建对象, 循环结束后会调用析构函数, 无法统计个数
        pFormalWorker[number - 1] = new FormalWorker(name, basicSalary, sex, department, id,
                                                     phone_number); //构造函数会自动析构释放 ,需要New对象
        pFormalWorker[number - 1]->show();
    }
    pFormalWorker[number-1]->flag = true;   // 表示可以访问
    save_revise_to_file(data_file_path,pFormalWorker );
}

/* 输出职工信息 */
void output(vector<FormalWorker *> &pFormalWorker) {
    cout << "姓名  基本工资 性别  部门  工号  电话号码" << endl;
    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->flag)                            // ------------------------------------------------
        {
            pFormalWorker[i]->show();
            cout << endl;                     // (可以正常运行)
//            FormalWorker* p1 = dynamic_cast<FormalWorker*>(pFormalWorker[i]); //动态类型转换
//            //TempFormalWorker* p2 = dynamic_cast<TempFormalWorker*>(pFormalWorker[i]);
//            if (p1 != NULL && p1 == NULL)                //?转换成功, 是FormalWorker对象(正式职工)
//            {
//                //cout << *(FormalWorker)pFormalWorker[i];     // 咦, 不需要强制类型转换吗?    哦, 我好像知道了?
//                 cout << *p1;
//            }
//            else if (p1 == NULL && p1 != NULL)           //?转换成功, 是TempFormalWorker对象  (临时工)
//            {
//                cout << *p1;
//            }

        } else {
            cout << "OUTPUT ERROR!!!" << endl;
            exit(1);
        }
    }
}

/* 根据姓名来查找职工信息 */
void queryFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n请输入要查询的职工的姓名: " << endl;
    cin >> queryName;
    double salary_sumary = 0;
    double average_salary;
    double median_salary;
    double max_salary, min_salary;
    double deduction_salary;
    double allowance;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName && pFormalWorker[i]->flag) {
            auto b = pFormalWorker[i]->get_basic_salary();
            cout << "姓名  基本工资 性别  部门  工号  电话号码" << endl;
            pFormalWorker[i]->show();
            cout << endl << pFormalWorker[i]->getName() << "的税前基本薪资: " << pFormalWorker[i]->get_basic_salary()
                 << endl;
            if (b < 1100) {
                allowance = 1000;
                auto a = pFormalWorker[i]->get_basic_salary() + allowance;
                cout << "个人所得税为0\t扣除薪资0" << "\t津贴奖金1000\t" << "净工资: " << a << endl;
            } else if (b >= 1100 && b <= 1600) {
                allowance = 2000;
                auto c = b * 0.05;
                deduction_salary = 100;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else if (b > 1600 && b <= 2600) {
                allowance = 3000;
                auto c = b * 0.1;
                deduction_salary = 200;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else if (b > 2600 && b <= 3600) {

                allowance = 2500;
                auto c = b * 0.15;
                deduction_salary = 300;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else {
                allowance = 4000;
                auto c = b * 0.2;
                deduction_salary = 500;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            }

            return; // 查找成功
        }

    }
    cout << "查找失败 !!!" << endl;
}

#include<limits>

/* 根据姓名来修改职工信息: (备注, 这里只修改了姓名, 其余的属性不好修改啊 (⊙﹏⊙) */
void modifyFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName, newName;
    cout << "\n请输入要修改的职工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName && pFormalWorker[i]->flag)              // 查找成功
        {
            f:
            cout << "请输入修改的信息选项-- 1.基本薪资 2.性别 3.部门 4.工号 5.电话号码 " << endl;
            int choice;;
            cin >> choice; //cin.fall() 如果输入不是整形则判断true
            if (cin.fail()) {
                cout << "格式不对,请重新输入" << endl;
                std::cin.clear();  // 清除错误标志
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略输入缓冲区中的无效字符
                goto f;
            }
            switch (choice) {
                case 1: {
                    cout << "请输入新的基本薪资" << endl;
                    double salary;
                    cin >> salary;
                    pFormalWorker[i]->set_basic_salary(salary);
                    break;
                }
                case 2: {
                    cout << "请输入新的性别" << endl;
                    string sex;
                    cin >> sex;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    pFormalWorker[i]->set_sex(sex);
                    break;
                }
                case 3: {
                    cout << "请输入新的部门" << endl;
                    string department;
                    cin >> department;
                    pFormalWorker[i]->set_department(department);
                    break;
                }
                case 4: {
                    cout << "请输入新的工号" << endl;
                    int id;
                    cin >> id;
                    pFormalWorker[i]->set_ID(id);
                    break;
                }
                case 5: {
                    cout << "请输入新的电话号码" << endl;
                    int number;
                    cin >> number;
                    pFormalWorker[i]->set_phone_number(number);
                    break;
                }
                default :
                    break;
            }
            save_revise_to_file(data_file_path, pFormalWorker);
            return; // 查找成功, 返回
        }
    }

    cout << "查找失败, 姓名无法修改!" << endl;
}

/* 根据姓名来删除职工信息 (可恢复) */
void deleteFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n请输入要删除的职工的姓名(可恢复): " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName)  // 查找成功
        {
            backupFile(data_file_path, backup_file_path); //备份文件
            save_revise_to_file(data_file_path, pFormalWorker);
            //要恢复文件
            // restoreFile(backup_file_path, data_file_path);
            return;                              // 查找成功, 返回
        }
    }

    cout << "查无此人, 无法删除!" << endl;
}

/* 根据姓名来删除职工信息 (不可恢复) */
void clearFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n请输入要删除的职工的姓名(不可恢复): " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName)    // 查找成功
        {
            // delete pFormalWorker[i];                     // 先释放该元素空间 (原因:必须要在erase之前将其delete掉)
            // pFormalWorker.erase(pFormalWorker.begin() + i);    // 删除pFormalWorker[i]元素
            for (int j = i; j < number; ++j) {
                pFormalWorker[i] = pFormalWorker[i + 1];
            }

            number--;
            save_revise_to_file(data_file_path, pFormalWorker);
            cout << "删除成功" << endl;
            return;                                // 查找成功, 返回
        }
    }

    cout << "查无此人, 无法删除!" << endl;
}

/* 根据姓名来恢复一个职工信息 */
void recoverFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n请输入要恢复的职工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName && pFormalWorker[i]->flag == false) {
            pFormalWorker[i]->flag = true;
            cout << "恢复成功: " << endl;
            return;            // 查找成功, 返回
        }
    }

    cout << "查无此人, 恢复失败!" << endl;
}

#include <unordered_set>

/* 9.显示各种职工人数 */
void showFormalWorkerNum(vector<FormalWorker *> &pFormalWorker) {
    /*
    TempFormalWorker::showCount();    // 这里必须要将showCount函数定义为静态函数, 即加上static关键字
    FormalWorker::showCount();  // 关键问题: 可恢复删除(未delete)导致静态的人数没有变化 !!!!!!!!!!!!!!!!!
    */
    unordered_set<string> str;
    int quantity1 = 1;
    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->flag) {
            str.insert(pFormalWorker[i]->getDepartment());
        }
    }
    for (const auto &element: str) {
        int a = 0;
        for (int i = 0; i < number; ++i) {
            if (element == pFormalWorker[i]->getDepartment()) {
                a++;
            }
        }
        cout << element << "的人数为: " << a << endl;
    }
}

#include <algorithm>

/* 显示职工总的实发工资、平均实发工资 */
void showFormalWorkerSalary(vector<FormalWorker *> &pFormalWorker) {
    /*
    TempFormalWorker::showSalary();    // 这里必须要将showCount函数定义为静态函数, 即加上static关键字
    FormalWorker::showSalary();  // 关键问题: 可恢复删除(未delete)导致静态的人数没有变化 !!!!!!!!!!!!!!!!!
    */
    //平均 中位数 最大 最小  税前薪资基本薪资  税后薪资 个人所得税 扣除薪资 津贴奖金
// 个人所得税计算方法设为：工资少于1100元的部分为0，1100—1600元部分为5%，1600—2600部分为10%，
// 2600—3600部分为15%，3600元以上部分为20%。
    double salary_sumary = 0;
    double average_salary;
    double median_salary;
    double max_salary, min_salary;
    double deduction_salary;
    double allowance;
    for (int i = 0; i < number; ++i) {
        salary_sumary = pFormalWorker[i]->get_basic_salary() + salary_sumary;
    }
    average_salary = salary_sumary / number;
    vector<int> myVector;
    for (int i = 0; i < number; ++i) {
        myVector.push_back(pFormalWorker[i]->get_basic_salary());
    }
    auto max = max_element(myVector.begin(), myVector.end());
    auto min = min_element(myVector.begin(), myVector.end());
    max_salary = *max;
    min_salary = *min;
    if ((number + 1) % 2 == 0) {
        int a = (number + 1) / 2;
        median_salary = pFormalWorker[a - 1]->get_basic_salary() + pFormalWorker[a]->get_basic_salary();
    }
    cout << "平均薪资: " << average_salary << endl << "中位数薪资: " << median_salary << endl
         << "最高薪资: " << max_salary << "\t" << "最低工资: " << min_salary << endl;
    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->flag) {
            auto b = pFormalWorker[i]->get_basic_salary();
            cout << pFormalWorker[i]->getName() << "的税前基本薪资: " << pFormalWorker[i]->get_basic_salary() << endl;
            if (b < 1100) {
                allowance = 1000;
                auto a = pFormalWorker[i]->get_basic_salary() + allowance;
                cout << "个人所得税为0\t扣除薪资0" << "\t津贴奖金1000\t" << "净工资: " << a << endl;
            } else if (b >= 1100 && b <= 1600) {
                allowance = 2000;
                auto c = b * 0.05;
                deduction_salary = 100;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else if (b > 1600 && b <= 2600) {
                allowance = 3000;
                auto c = b * 0.1;
                deduction_salary = 200;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else if (b > 2600 && b <= 3600) {
                allowance = 2500;
                auto c = b * 0.15;
                deduction_salary = 300;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            } else {
                allowance = 4000;
                auto c = b * 0.2;
                deduction_salary = 500;
                auto a = b + allowance - c - deduction_salary;
                cout << "个人所得税为\t" << c << "\t扣除薪资\t" << deduction_salary << "\t津贴奖金\t" << allowance
                     << "\t净工资\t " << a << endl;
            }
        }
    }
}


/* 用循环来删除指针数组 (new和delete必须要同时使用) */
void deleteAllFormalWorker(vector<FormalWorker *> &pFormalWorker) {
    for (int i = 0; i < number; i++) {
        delete pFormalWorker[i];
    }
}

/*
测试数据:
10
f 小明 10000 900
F 张三 3000 800
f 李四 4000 700
f 王五 5000 600
F 赵六 6000 500
T AAA 10000 900
t BBB 3000 800
T CCC 4000 700
t DDD 5000 600
t EEE 6000 500
4
王五
7
3
小明
小二
7
8
5
赵六
7
2
BBB
7
6
赵六
6
BBB
7
9
8
2
DD
2
DDD
7
9
10
0
*/