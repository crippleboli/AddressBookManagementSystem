#include "iostream"
#include "string"
#define MAX 1000   // 通讯录用户最大个数
using namespace std;


//联系人结构体
struct Person {
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

//通讯录结构体
struct Addressbooks {
    struct Person personarray[MAX];  // 结构体数组
    int m_size;
};



// 添加联系人函数
void addPerson(Addressbooks *abs) {

    if (abs->m_size == MAX) {
        cout<<"通讯录已满，无法添加！";
    }else {
        //姓名
        string name;            //临时姓名变量
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[abs->m_size].m_Name  = name;

        //性别
        int sex;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        cin >> sex;
        while (1) {
            if (sex == 1|| sex == 2) {
                abs->personarray[abs->m_size].m_Sex = sex;
                break;
            }else{
                cout << "性别非法输入,请重新输入！"<<endl;
                cin >> sex;
            }
        }

        //年龄
        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        while (1) {
            if (age>0 && age <= 150) {
                abs->personarray[abs->m_size].m_Age = age;
                break;
            }else {
                cout << "年龄非法输入,请重新输入！"<<endl;
                cin>>age;
            }
        }

        //电话
        string phone;
        cout << "请输入电话：" << endl;
        cin>>phone;
        abs->personarray[abs->m_size].m_Phone = phone;

        //住址
        string addr;
        cout << "请输入住址：" << endl;
        cin>>addr;
        abs->personarray[abs->m_size].m_Addr = addr;


        //人数增加
        abs->m_size ++;

        cout << "添加成功！"<<endl;
        //system("clear"); system("cls");       mac非窗口运行
    }
}


// 显示联系人函数
void showPerson(Addressbooks *abs) {
    if (abs->m_size==0) {
        cout<<"当前记录为空！"<<endl;
    }else {
        for (int i = 0; i < abs->m_size; i++) {
            cout<<"姓名："<<abs->personarray[i].m_Name<<"\t";
            cout<<"性别："<< (abs->personarray[i].m_Sex == 1? "男":"女") <<"\t";
            cout<<"年龄："<< abs->personarray[i].m_Age<<"\t";
            cout<<"电话："<<abs->personarray[i].m_Phone<<"\t";
            cout<<"地址："<< abs->personarray[i].m_Addr<<endl;
        }
    }
}


// 展示菜单函数
void showMenu() {
    cout <<"*********************"<<endl;
    cout << "*****1.添加联系人*****"<<endl;
    cout << "*****2.显示联系人*****"<<endl;
    cout << "*****3.删除联系人*****"<<endl;
    cout << "*****4.查找联系人*****"<<endl;
    cout << "*****5.修改联系人*****"<<endl;
    cout << "*****6.清空联系人*****"<<endl;
    cout << "*****0.退出通讯录*****"<<endl;
    cout <<"*********************"<<endl;
}

// 查找联系人下标函数 输入：联系人姓名 输出：数组位置 不存在为-1
int isExist(Addressbooks * abs,string name) {
    for (int i=0;i<abs->m_size;i++) {
        if (abs->personarray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}

// 删除联系人函数
void deletePerson(Addressbooks *abs) {
    cout << "请输入需要删除的联系人姓名！"<<endl;
    string name;
    cin>> name;

    int ret = isExist(abs,name);
    if (ret == -1) {
        cout <<"查无此人！"<<endl;
    }else {
        for (int i= ret;i<abs->m_size-1;i++) {
            abs->personarray[i] = abs->personarray[i+1];    // 数据迁移覆盖
        }
        abs->m_size --;     // 总人数减少
        cout<< "成功删除"<< name <<"!"<<endl;
    }
}

// 查找联系人函数
void findPerson(Addressbooks *abs) {
    cout << "请输入您要查找的联系人！"<<endl;

    string name;
    cin >> name;

    int ret= isExist(abs,name);
    if (ret ==-1) {
        cout << "查无此人！"<<endl;
    }else {
        cout << "姓名：" << abs->personarray[ret].m_Name << endl;
        cout << "性别：" << (abs->personarray[ret].m_Sex == 1? "男":"女") << endl;
        cout << "年龄：" << abs->personarray[ret].m_Age << endl;
        cout << "电话：" << abs->personarray[ret].m_Phone << endl;
        cout << "住址：" << abs->personarray[ret].m_Addr << endl;
    }
}

// 修改联系人
void modifyPerson(Addressbooks *abs){
    cout << "请输入需要修改的联系人姓名" <<endl;
    string name;
    cin >> name;

    int ret = isExist(abs,name);
    if (ret ==-1) {
        cout << "查无此人！"<<endl;
    }else {
        cout << "请重新输入姓名：" << endl;
        string name;
        cin >>name;
        abs->personarray[ret].m_Name =name;

        cout << "请重新输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        while (1) {
            cin >> sex;
            if (sex == 1||sex ==2) {
                abs->personarray[ret].m_Sex =sex;
                break;
            }
            cout << "性别输入有误！请重新输入"<<endl;
        }


        cout << "请重新输入年龄：" << endl;
        int age;
        cin >>age;
        abs->personarray[ret].m_Age = age;

        cout << "请重新输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personarray[ret].m_Phone = phone;

        cout << "请重新输入住址：" << endl;
        string address;
        cin >> address;
        abs->personarray[ret].m_Addr = address;

        cout << "修改成功！"<<endl;
        cout << "修改后的信息为"<<endl;
        cout << "姓名：" << abs->personarray[ret].m_Name << endl;
        cout << "性别：" << abs->personarray[ret].m_Sex << endl;
        cout << "年龄：" << abs->personarray[ret].m_Age << endl;
        cout << "电话：" << abs->personarray[ret].m_Phone << endl;
        cout << "住址：" << abs->personarray[ret].m_Addr << endl;

     }
}

// 清空联系人信息
void cleanPerson(Addressbooks *abs) {
    abs->m_size = 0;
    cout << "通讯录已清空！"<<endl;
}


// 主函数
int main() {

    Addressbooks abs;      //创建并初始化通讯录变量
    abs.m_size = 0;

    int select = 0;        //用户选择功能

    while (1) {

        showMenu();        //菜单调用
        cin >> select;     //获取用户功能选择

        switch (select) {
            case 1:        //增加联系人
                addPerson(&abs); //地址传递 对变量进行修改
                break;
            case 2:        //显示联系人
                showPerson(&abs);
                break;
            case 3:        //删除联系人
                deletePerson(&abs);
                break;
            case 4:        //查找联系人
                findPerson(& abs);
                break;
            case 5:        //修改联系人
                modifyPerson(& abs);
                break;
            case 6:        //清空联系人
                cleanPerson(& abs);
                break;
            case 0:
                cout << "欢迎下次使用！" << endl;
                return 0;
                break;
            default:
                break;
        }

    }

}
