//
// Created by superuse on 2024/1/18.
//

#include "salary_management.h"
#include<fstream>
#include<iostream>

#define  data_file_path "A:/Clion/Clion_cpp_project/salary_manage_system/employee_information.txt"
//clion������ļ�·��ǧ������\��б�� ����/
static int number;

void myMenu() {
    cout << "====================================== ְ�����ʹ���ϵͳ =======================================" << endl;
    cout << "     1 ����ְ����¼           �� 2 ɾ��ְ����¼ (�ɻָ�)      " << endl;
    cout << "     3 �޸�ְ����¼            ��4 ����ְ����¼              " << endl;
    cout << "     5 ɾ��ְ����¼ (���ɻָ�) �� 6 ��ʾְ����¼                " << endl;
    cout << "     7  ͳ��ְ������             8 ͳ��ְ������      " << endl;
    cout << "     0 �˳�ϵͳ                Designed By YZG     " << endl;
    cout << "===============================================================================================" << endl;
}

//����ģʽ
void save_revise_to_file(const std::string &filePath, std::vector<FormalWorker *> &pFormalWorker) {
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cerr << "�޷����ļ����б���" << std::endl;
        return;
    }

    for (int j = 0; j < number; j++) {
        if (pFormalWorker[j]->flag) {
            // ���������������ݽṹ���ÿ��ְ������Ϣ���ļ�
            // ���������������ݽṹ���ÿ��ְ������Ϣ���ļ�
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
    std::ofstream file(filename, std::ios::app);  // ʹ��׷��ģʽ����ֹ����ԭ������
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
}//׷��ģʽ

// ���ļ�����
void reloadFromFile(const std::string &filename, vector<FormalWorker *> &pFormalWorker) {
    std::ifstream file(filename);
    string name;
    int i, ID, phonenumber;
    string sex, department;
    double basicSalary;
    i = 0;
    if (file.is_open()) {
        while (file >> name >> basicSalary >> sex >> department >> ID >> phonenumber) {
            // ���� FormalWorker ������ӵ���Ӧ��������
            FormalWorker *PFormalWorker = new FormalWorker(name, basicSalary, sex, department, ID, phonenumber);
            pFormalWorker[i] = PFormalWorker;
            i++;
        }
        for (int j = 0; j < i; j++) {//��ֹԽ������, ��Ҫ��pFormalWorker.size()
            pFormalWorker[j]->flag = true;//
        }
        number = i;
        cout << "���ݵ���ɹ�" << endl;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

#include <cstdio>  // ����ɾ���ļ���ͷ�ļ�

const std::string backup_file_path = "backup_file.txt";

void backupFile(const std::string &sourcePath, const std::string &backupPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream backupFile(backupPath, std::ios::binary);

    if (sourceFile.is_open() && backupFile.is_open()) {
        backupFile << sourceFile.rdbuf();
        std::cout << "�ļ����ݳɹ�" << std::endl;
    } else {
        std::cerr << "�ļ�����ʧ��" << std::endl;
    }

    sourceFile.close();
    backupFile.close();
}

void deleteFile(const std::string &filePath) {
    if (std::remove(filePath.c_str()) == 0) {
        std::cout << "�ļ�ɾ���ɹ�" << std::endl;
    } else {
        std::cerr << "�ļ�ɾ��ʧ��" << std::endl;
    }
}

void restoreFile(const std::string &sourcePath, const std::string &destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream destinationFile(destinationPath, std::ios::binary);

    if (sourceFile.is_open() && destinationFile.is_open()) {
        destinationFile << sourceFile.rdbuf();
        std::cout << "�ļ��ָ��ɹ�" << std::endl;
    } else {
        std::cerr << "�ļ��ָ�ʧ��" << std::endl;
    }

    sourceFile.close();
    destinationFile.close();
}

/* ����ְ����Ϣ */
void
input(vector<FormalWorker *> &pFormalWorker)           // �൱��void input(FormalWorker* pFormalWorker[], int number)
{
    string name;        // ����
    double basicSalary; // ��������
    double tax;         // ����˰
    double bonus;       // ����
    char choice = 'f';
    string sex;
    string department;
    int id;
    int phone_number;
    if (true) {
        cout << "��������" << endl;
        cin >> name;
        cout << "�������н�� " << endl;
        cin >> basicSalary;
        cout << "�Ա�" << endl;
        cin >> sex;
        cout << "���ڲ���" << endl;
        cin >> department;
        cout << "ְ������" << endl;
        cin >> id;
        cout << "�绰����" << endl;
        cin >> phone_number;
        number = number + 1;
        //FormalWorker fFormalWorker(name, basicSalary, tax);
        //pFormalWorker[i] = &fFormalWorker;    // ����: ��ѭ���ڴ�������, ѭ��������������������, �޷�ͳ�Ƹ���
        pFormalWorker[number - 1] = new FormalWorker(name, basicSalary, sex, department, id,
                                                     phone_number); //���캯�����Զ������ͷ� ,��ҪNew����
        pFormalWorker[number - 1]->show();
    }
    pFormalWorker[number-1]->flag = true;   // ��ʾ���Է���
    save_revise_to_file(data_file_path,pFormalWorker );
}

/* ���ְ����Ϣ */
void output(vector<FormalWorker *> &pFormalWorker) {
    cout << "����  �������� �Ա�  ����  ����  �绰����" << endl;
    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->flag)                            // ------------------------------------------------
        {
            pFormalWorker[i]->show();
            cout << endl;                     // (������������)
//            FormalWorker* p1 = dynamic_cast<FormalWorker*>(pFormalWorker[i]); //��̬����ת��
//            //TempFormalWorker* p2 = dynamic_cast<TempFormalWorker*>(pFormalWorker[i]);
//            if (p1 != NULL && p1 == NULL)                //?ת���ɹ�, ��FormalWorker����(��ʽְ��)
//            {
//                //cout << *(FormalWorker)pFormalWorker[i];     // ��, ����Ҫǿ������ת����?    Ŷ, �Һ���֪����?
//                 cout << *p1;
//            }
//            else if (p1 == NULL && p1 != NULL)           //?ת���ɹ�, ��TempFormalWorker����  (��ʱ��)
//            {
//                cout << *p1;
//            }

        } else {
            cout << "OUTPUT ERROR!!!" << endl;
            exit(1);
        }
    }
}

/* ��������������ְ����Ϣ */
void queryFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n������Ҫ��ѯ��ְ��������: " << endl;
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
            cout << "����  �������� �Ա�  ����  ����  �绰����" << endl;
            pFormalWorker[i]->show();
            cout << endl << pFormalWorker[i]->getName() << "��˰ǰ����н��: " << pFormalWorker[i]->get_basic_salary()
                 << endl;
            if (b < 1100) {
                allowance = 1000;
                auto a = pFormalWorker[i]->get_basic_salary() + allowance;
                cout << "��������˰Ϊ0\t�۳�н��0" << "\t��������1000\t" << "������: " << a << endl;
            } else if (b >= 1100 && b <= 1600) {
                allowance = 2000;
                auto c = b * 0.05;
                deduction_salary = 100;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else if (b > 1600 && b <= 2600) {
                allowance = 3000;
                auto c = b * 0.1;
                deduction_salary = 200;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else if (b > 2600 && b <= 3600) {

                allowance = 2500;
                auto c = b * 0.15;
                deduction_salary = 300;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else {
                allowance = 4000;
                auto c = b * 0.2;
                deduction_salary = 500;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            }

            return; // ���ҳɹ�
        }

    }
    cout << "����ʧ�� !!!" << endl;
}

#include<limits>

/* �����������޸�ְ����Ϣ: (��ע, ����ֻ�޸�������, ��������Բ����޸İ� (�ѩn��) */
void modifyFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName, newName;
    cout << "\n������Ҫ�޸ĵ�ְ��������: " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName && pFormalWorker[i]->flag)              // ���ҳɹ�
        {
            f:
            cout << "�������޸ĵ���Ϣѡ��-- 1.����н�� 2.�Ա� 3.���� 4.���� 5.�绰���� " << endl;
            int choice;;
            cin >> choice; //cin.fall() ������벻���������ж�true
            if (cin.fail()) {
                cout << "��ʽ����,����������" << endl;
                std::cin.clear();  // ��������־
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // �������뻺�����е���Ч�ַ�
                goto f;
            }
            switch (choice) {
                case 1: {
                    cout << "�������µĻ���н��" << endl;
                    double salary;
                    cin >> salary;
                    pFormalWorker[i]->set_basic_salary(salary);
                    break;
                }
                case 2: {
                    cout << "�������µ��Ա�" << endl;
                    string sex;
                    cin >> sex;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    pFormalWorker[i]->set_sex(sex);
                    break;
                }
                case 3: {
                    cout << "�������µĲ���" << endl;
                    string department;
                    cin >> department;
                    pFormalWorker[i]->set_department(department);
                    break;
                }
                case 4: {
                    cout << "�������µĹ���" << endl;
                    int id;
                    cin >> id;
                    pFormalWorker[i]->set_ID(id);
                    break;
                }
                case 5: {
                    cout << "�������µĵ绰����" << endl;
                    int number;
                    cin >> number;
                    pFormalWorker[i]->set_phone_number(number);
                    break;
                }
                default :
                    break;
            }
            save_revise_to_file(data_file_path, pFormalWorker);
            return; // ���ҳɹ�, ����
        }
    }

    cout << "����ʧ��, �����޷��޸�!" << endl;
}

/* ����������ɾ��ְ����Ϣ (�ɻָ�) */
void deleteFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n������Ҫɾ����ְ��������(�ɻָ�): " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName)  // ���ҳɹ�
        {
            backupFile(data_file_path, backup_file_path); //�����ļ�
            save_revise_to_file(data_file_path, pFormalWorker);
            //Ҫ�ָ��ļ�
            // restoreFile(backup_file_path, data_file_path);
            return;                              // ���ҳɹ�, ����
        }
    }

    cout << "���޴���, �޷�ɾ��!" << endl;
}

/* ����������ɾ��ְ����Ϣ (���ɻָ�) */
void clearFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n������Ҫɾ����ְ��������(���ɻָ�): " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName)    // ���ҳɹ�
        {
            // delete pFormalWorker[i];                     // ���ͷŸ�Ԫ�ؿռ� (ԭ��:����Ҫ��erase֮ǰ����delete��)
            // pFormalWorker.erase(pFormalWorker.begin() + i);    // ɾ��pFormalWorker[i]Ԫ��
            for (int j = i; j < number; ++j) {
                pFormalWorker[i] = pFormalWorker[i + 1];
            }

            number--;
            save_revise_to_file(data_file_path, pFormalWorker);
            cout << "ɾ���ɹ�" << endl;
            return;                                // ���ҳɹ�, ����
        }
    }

    cout << "���޴���, �޷�ɾ��!" << endl;
}

/* �����������ָ�һ��ְ����Ϣ */
void recoverFormalWorkerByName(vector<FormalWorker *> &pFormalWorker) {
    string queryName;
    cout << "\n������Ҫ�ָ���ְ��������: " << endl;
    cin >> queryName;

    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->getName() == queryName && pFormalWorker[i]->flag == false) {
            pFormalWorker[i]->flag = true;
            cout << "�ָ��ɹ�: " << endl;
            return;            // ���ҳɹ�, ����
        }
    }

    cout << "���޴���, �ָ�ʧ��!" << endl;
}

#include <unordered_set>

/* 9.��ʾ����ְ������ */
void showFormalWorkerNum(vector<FormalWorker *> &pFormalWorker) {
    /*
    TempFormalWorker::showCount();    // �������Ҫ��showCount��������Ϊ��̬����, ������static�ؼ���
    FormalWorker::showCount();  // �ؼ�����: �ɻָ�ɾ��(δdelete)���¾�̬������û�б仯 !!!!!!!!!!!!!!!!!
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
        cout << element << "������Ϊ: " << a << endl;
    }
}

#include <algorithm>

/* ��ʾְ���ܵ�ʵ�����ʡ�ƽ��ʵ������ */
void showFormalWorkerSalary(vector<FormalWorker *> &pFormalWorker) {
    /*
    TempFormalWorker::showSalary();    // �������Ҫ��showCount��������Ϊ��̬����, ������static�ؼ���
    FormalWorker::showSalary();  // �ؼ�����: �ɻָ�ɾ��(δdelete)���¾�̬������û�б仯 !!!!!!!!!!!!!!!!!
    */
    //ƽ�� ��λ�� ��� ��С  ˰ǰн�ʻ���н��  ˰��н�� ��������˰ �۳�н�� ��������
// ��������˰���㷽����Ϊ����������1100Ԫ�Ĳ���Ϊ0��1100��1600Ԫ����Ϊ5%��1600��2600����Ϊ10%��
// 2600��3600����Ϊ15%��3600Ԫ���ϲ���Ϊ20%��
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
    cout << "ƽ��н��: " << average_salary << endl << "��λ��н��: " << median_salary << endl
         << "���н��: " << max_salary << "\t" << "��͹���: " << min_salary << endl;
    for (int i = 0; i < number; i++) {
        if (pFormalWorker[i]->flag) {
            auto b = pFormalWorker[i]->get_basic_salary();
            cout << pFormalWorker[i]->getName() << "��˰ǰ����н��: " << pFormalWorker[i]->get_basic_salary() << endl;
            if (b < 1100) {
                allowance = 1000;
                auto a = pFormalWorker[i]->get_basic_salary() + allowance;
                cout << "��������˰Ϊ0\t�۳�н��0" << "\t��������1000\t" << "������: " << a << endl;
            } else if (b >= 1100 && b <= 1600) {
                allowance = 2000;
                auto c = b * 0.05;
                deduction_salary = 100;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else if (b > 1600 && b <= 2600) {
                allowance = 3000;
                auto c = b * 0.1;
                deduction_salary = 200;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else if (b > 2600 && b <= 3600) {
                allowance = 2500;
                auto c = b * 0.15;
                deduction_salary = 300;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            } else {
                allowance = 4000;
                auto c = b * 0.2;
                deduction_salary = 500;
                auto a = b + allowance - c - deduction_salary;
                cout << "��������˰Ϊ\t" << c << "\t�۳�н��\t" << deduction_salary << "\t��������\t" << allowance
                     << "\t������\t " << a << endl;
            }
        }
    }
}


/* ��ѭ����ɾ��ָ������ (new��delete����Ҫͬʱʹ��) */
void deleteAllFormalWorker(vector<FormalWorker *> &pFormalWorker) {
    for (int i = 0; i < number; i++) {
        delete pFormalWorker[i];
    }
}

/*
��������:
10
f С�� 10000 900
F ���� 3000 800
f ���� 4000 700
f ���� 5000 600
F ���� 6000 500
T AAA 10000 900
t BBB 3000 800
T CCC 4000 700
t DDD 5000 600
t EEE 6000 500
4
����
7
3
С��
С��
7
8
5
����
7
2
BBB
7
6
����
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