#include <iostream>
#include <string>
using namespace std;

#define MAX  1000

//��ϵ�˽ṹ��

struct Person
{
    string m_Name;
    //�Ա� 1 �� 2 Ů
    int m_Sex;
    // ����
    int m_Age;
    // �绰
    string m_Phone;
    // ��ַ
    string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(struct Addressbooks * abs)
{
    // �ж�ͨѶ¼�Ƿ�����
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�����������޷����";
        return;
    }
    else
    {
        // ��Ӿ�����ϵ��

        //����
        string name;
        cout << "������������ " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //�Ա�
        int sex = 0;
        cout << "�������Ա� " << endl;
        cout << "1 ---- �У� " << endl;
        cout << "2 ---- Ů�� " << endl;


        while(true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "��������������1����2" << endl;
            }
        }

        // ����

        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //�绰

        cout << "������绰��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //סַ

        cout << "������סַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //����ͨѶ¼����

        ++abs->m_Size;

        cout << "��ӳɹ�,"<< "Ŀǰ����" << abs->m_Size << "λ��ϵ��"<< endl;

        system("pause");
        system("cls");
    }
}


void showPerson(struct Addressbooks * abs)
{
    // �ж����ͨѶ¼����Ϊ0����ʾ��¼Ϊ��
    // ���������Ϊ0����ʾ��¼����ϵ��

    if(abs->m_Size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;

    }
    else
    {
        for (int i=0; i< abs->m_Size; ++i)
        {
            cout << "��" << i+1 << "λ��ϵ�ˣ�" << endl;
            cout << "\t������ " << abs->personArray[i].m_Name << "\t";
            cout << "\t�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
            cout << "\t���䣺 " << abs->personArray[i].m_Age << "\t";
            cout << "\t�绰�� " << abs->personArray[i].m_Phone << "\t";
            cout << "\tסַ�� " << abs->personArray[i].m_Addr << endl;

        }
    }
    system("pause");
    system("cls");
}


//�����ϵ���Ƿ���ڣ�������ڷ�����λ�ã���������ڷ���-1

int isExist(struct Addressbooks * abs, string name)
{
    for (int i =0; i < abs->m_Size; ++i)
    {
        //����ҵ�������
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }

    return -1; //���û�ҵ�
}

void deletePerson(struct Addressbooks * abs)
{
    cout << "������Ҫɾ������ϵ��������" << endl;

    string name;
    cin >> name;

    // ret == -1 δ�ҵ�
    // ret != -1 �ҵ���

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i+1];
        }
        --abs->m_Size; //ͨѶ¼����������1
        cout << "ɾ���ɹ�," <<"Ŀǰʣ��" << abs->m_Size << "λ��ϵ��"<< endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void findPerson(struct Addressbooks * abs)
{
    cout << "������Ҫ���ҵ���ϵ��������" << endl;

    string name;
    cin >> name;

    // ret == -1 δ�ҵ�
    // ret != -1 �ҵ���

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "\t������ " << abs->personArray[ret].m_Name << "\t";
        cout << "\t�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
        cout << "\t���䣺 " << abs->personArray[ret].m_Age << "\t";
        cout << "\t�绰�� " << abs->personArray[ret].m_Phone << "\t";
        cout << "\tסַ�� " << abs->personArray[ret].m_Addr << endl;

    }
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void modifyPerson(struct Addressbooks * abs)
{
    cout << "������Ҫ�޸ĵ���ϵ��������" << endl;

    string name;
    cin >> name;

    // ret == -1 δ�ҵ�
    // ret != -1 �ҵ���

    int ret = isExist(abs, name);

    if(ret != -1)
    {
        //����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        //�Ա�
        int sex = 0;
        cout << "�������Ա�" << endl;
        cout << "1 ---- ��" << endl;
        cout << "2 ---- Ů" << endl;
        cin >> sex;

        while(true)
        {
            if (sex ==1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;

            }
            else
            {
                cout << "�������������1��2" << endl;
            }
        }

        // ����

        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //�绰

        cout << "������绰��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //סַ

        cout << "������סַ��" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;


        cout << "�޸ĳɹ�"<< endl;



    }
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void cleanPerson(struct Addressbooks * abs)
{

    cout << "ͨѶ¼���� " << abs->m_Size << " �� "<< endl;
    cout << "1 ---- �� \n2 ---- ��" << endl;
    int flag = 0;
    cin >> flag;

    if(flag == 1)
    {
        abs->m_Size = 0; //����ǰ��ϵ�˵��������㣬���߼����

        cout << "ͨѶ¼�����" << endl;

    }
    else
    {
        cout << "��ղ�����ȡ��" << endl;
    }

    system("pause");
    system("cls");
}

void recoverPerson(struct Addressbooks * abs)
{
    // �����ϵ�˶��ǻ����߼���յ�

    int size = 0;
    cout << "���������ǰͨѶ¼������" << endl;
    cin >> size;

    abs->m_Size = size;

    cout << "�ָ��ɹ�" << endl;
    system("pause");
    system("cls");
}

void showMenu()
{
    cout << "********************************" << endl;
    cout << "*\t1. �����ϵ��          *" << endl;
    cout << "*\t2. ��ʾ��ϵ��          *" << endl;
    cout << "*\t3. ɾ����ϵ��          *" << endl;
    cout << "*\t4. ������ϵ��          *" << endl;
    cout << "*\t5. �޸���ϵ��          *" << endl;
    cout << "*\t6. �����ϵ��          *" << endl;
    cout << "*\t0. �˳�ͨѶ¼          *" << endl;
    cout << "********************************" << endl;
}





int main()
{

    //����ͨѶ¼�ṹ�����
    struct Addressbooks abs;
    //��ʼ��ͨѶ¼����
    abs.m_Size = 0;
    cout << "��ӭʹ��ͨѶ¼\n"<< "Ŀǰ���� " << (&abs)->m_Size << " λ��ϵ��"<< endl;
    cout << "���������� 0-6 ���в�����\n" << endl;



    //�û��������
    int select = 0;
    while (true)
    {
        //��ʾ�˵�
        showMenu();


        cin >> select;

        switch (select)
        {
        case 1: //�����ϵ��
            addPerson(&abs);
            break;
        case 2: //��ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3: //ɾ����ϵ��
            deletePerson(&abs);
            break;
        case 4: //������ϵ��
            findPerson(&abs);
            break;
        case 5: //�޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6: //�˳�ͨѶ¼
            cleanPerson(&abs);
            break;
        case 0: //�˳�ϵͳ
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        case 10086: //���ع���,�ָ�����
            recoverPerson(&abs);
            break;
        default:
            cout << "����ָ������" << endl;
            system("pause");
            system("cls");
            break;

        }
    }



}
