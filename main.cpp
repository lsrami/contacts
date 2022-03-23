#include <iostream>
#include <string>
using namespace std;

#define MAX  1000

//联系人结构体

struct Person
{
    string m_Name;
    //性别 1 男 2 女
    int m_Sex;
    // 年龄
    int m_Age;
    // 电话
    string m_Phone;
    // 地址
    string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(struct Addressbooks * abs)
{
    // 判断通讯录是否满了
    if (abs->m_Size == MAX)
    {
        cout << "通讯录容量已满，无法添加";
        return;
    }
    else
    {
        // 添加具体联系人

        //姓名
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        int sex = 0;
        cout << "请输入性别： " << endl;
        cout << "1 ---- 男： " << endl;
        cout << "2 ---- 女： " << endl;


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
                cout << "输入有误，请输入1或者2" << endl;
            }
        }

        // 年龄

        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话

        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //住址

        cout << "请输入住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //更新通讯录人数

        ++abs->m_Size;

        cout << "添加成功,"<< "目前共有" << abs->m_Size << "位联系人"<< endl;

        system("pause");
        system("cls");
    }
}


void showPerson(struct Addressbooks * abs)
{
    // 判断如果通讯录人数为0，提示记录为空
    // 如果人数不为0，显示记录的联系人

    if(abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;

    }
    else
    {
        for (int i=0; i< abs->m_Size; ++i)
        {
            cout << "第" << i+1 << "位联系人：" << endl;
            cout << "\t姓名： " << abs->personArray[i].m_Name << "\t";
            cout << "\t性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "\t年龄： " << abs->personArray[i].m_Age << "\t";
            cout << "\t电话： " << abs->personArray[i].m_Phone << "\t";
            cout << "\t住址： " << abs->personArray[i].m_Addr << endl;

        }
    }
    system("pause");
    system("cls");
}


//检测联系人是否存在，如果存在返回其位置，如果不存在返回-1

int isExist(struct Addressbooks * abs, string name)
{
    for (int i =0; i < abs->m_Size; ++i)
    {
        //如果找到该姓名
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }

    return -1; //如果没找到
}

void deletePerson(struct Addressbooks * abs)
{
    cout << "请输入要删除的联系人姓名：" << endl;

    string name;
    cin >> name;

    // ret == -1 未找到
    // ret != -1 找到了

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i+1];
        }
        --abs->m_Size; //通讯录中总人数减1
        cout << "删除成功," <<"目前剩余" << abs->m_Size << "位联系人"<< endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void findPerson(struct Addressbooks * abs)
{
    cout << "请输入要查找的联系人姓名：" << endl;

    string name;
    cin >> name;

    // ret == -1 未找到
    // ret != -1 找到了

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "\t姓名： " << abs->personArray[ret].m_Name << "\t";
        cout << "\t性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "\t年龄： " << abs->personArray[ret].m_Age << "\t";
        cout << "\t电话： " << abs->personArray[ret].m_Phone << "\t";
        cout << "\t住址： " << abs->personArray[ret].m_Addr << endl;

    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void modifyPerson(struct Addressbooks * abs)
{
    cout << "请输入要修改的联系人姓名：" << endl;

    string name;
    cin >> name;

    // ret == -1 未找到
    // ret != -1 找到了

    int ret = isExist(abs, name);

    if(ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        //性别
        int sex = 0;
        cout << "请输入性别" << endl;
        cout << "1 ---- 男" << endl;
        cout << "2 ---- 女" << endl;
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
                cout << "输入错误，请输入1或2" << endl;
            }
        }

        // 年龄

        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //电话

        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //住址

        cout << "请输入住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;


        cout << "修改成功"<< endl;



    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void cleanPerson(struct Addressbooks * abs)
{

    cout << "通讯录共有 " << abs->m_Size << " 人 "<< endl;
    cout << "1 ---- 是 \n2 ---- 否" << endl;
    int flag = 0;
    cin >> flag;

    if(flag == 1)
    {
        abs->m_Size = 0; //将当前联系人的数量置零，做逻辑清空

        cout << "通讯录已清空" << endl;

    }
    else
    {
        cout << "清空操作已取消" << endl;
    }

    system("pause");
    system("cls");
}

void recoverPerson(struct Addressbooks * abs)
{
    // 清空联系人都是基于逻辑清空的

    int size = 0;
    cout << "请输入清空前通讯录总人数" << endl;
    cin >> size;

    abs->m_Size = size;

    cout << "恢复成功" << endl;
    system("pause");
    system("cls");
}

void showMenu()
{
    cout << "********************************" << endl;
    cout << "*\t1. 添加联系人          *" << endl;
    cout << "*\t2. 显示联系人          *" << endl;
    cout << "*\t3. 删除联系人          *" << endl;
    cout << "*\t4. 查找联系人          *" << endl;
    cout << "*\t5. 修改联系人          *" << endl;
    cout << "*\t6. 清空联系人          *" << endl;
    cout << "*\t0. 退出通讯录          *" << endl;
    cout << "********************************" << endl;
}





int main()
{

    //创建通讯录结构体变量
    struct Addressbooks abs;
    //初始化通讯录人数
    abs.m_Size = 0;
    cout << "欢迎使用通讯录\n"<< "目前共有 " << (&abs)->m_Size << " 位联系人"<< endl;
    cout << "请输入数字 0-6 进行操作：\n" << endl;



    //用户输出变量
    int select = 0;
    while (true)
    {
        //显示菜单
        showMenu();


        cin >> select;

        switch (select)
        {
        case 1: //添加联系人
            addPerson(&abs);
            break;
        case 2: //显示联系人
            showPerson(&abs);
            break;
        case 3: //删除联系人
            deletePerson(&abs);
            break;
        case 4: //查找联系人
            findPerson(&abs);
            break;
        case 5: //修改联系人
            modifyPerson(&abs);
            break;
        case 6: //退出通讯录
            cleanPerson(&abs);
            break;
        case 0: //退出系统
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        case 10086: //隐藏功能,恢复数据
            recoverPerson(&abs);
            break;
        default:
            cout << "输入指令有误" << endl;
            system("pause");
            system("cls");
            break;

        }
    }



}
