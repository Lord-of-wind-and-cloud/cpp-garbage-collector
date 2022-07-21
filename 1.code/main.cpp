/*************************************************************************
	测试
 ************************************************************************/
 
#include<iostream>
#include<mutex>
#include<string>
#include"smart_pointer.h"
#include"Sp_counter.h"
using namespace std;

int main() {
    int *a = new int(10);
    int *b = new int(20);
    cout<<"-------------默认构造测试----------------->"<<endl;
    cout<<"构造sp"<<endl;
    smart_pointer<int> sp(a);
    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    {
        cout<<"-------------拷贝构造测试----------------->"<<endl;
        cout<<"构造sp1  :sp1(sp)"<<endl;
        smart_pointer<int> sp1(sp);
        cout<<"构造sp2  :sp2(sp)"<<endl;
        smart_pointer<int> sp2(sp1);
        cout<<"sp1和sp2引用计数为3才是正确的"<<endl;
        cout<<"sp1.use_count:"<<sp1.use_count()<<endl;
        cout<<"sp2.use_count:"<<sp2.use_count()<<endl;
        cout<<"------------------------------------------>"<<endl<<endl;
        cout<<"调用析构释放sp1,sp2"<<endl;
    }
    cout<<"-------------析构函数测试----------------->"<<endl;
    cout<<"此处sp.use_count应该为1才是正确的"<<endl;
    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    cout<<"-------------赋值构造测试----------------->"<<endl;
    cout<<"构造sp3  :sp3(b)"<<endl;
    smart_pointer<int> sp3(b);
    cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    cout<<"sp3 = sp"<<endl;
    sp3 = sp;
    cout<<"sp3先被释放,然后sp3引用计数为2才正确,sp的引用计数为2才正确"<<endl;
    cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    cout<<"sp.use_count :"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    cout<<"-------------解引用测试----------------->"<<endl;
    cout<<"*sp3:"<<*sp3<<endl;
    cout<<"*sp3 = 100"<<endl;
    *sp3 = 100;
    cout<<"*sp3:"<<*sp3<<endl;
    cout<<"------------------------------------------>"<<endl;
 
    // cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    //cout<<"sp.use_count:"<<sp.use_count()<<endl;
 
    cout<<"===================end main===================="<<endl;
    return 0;
}