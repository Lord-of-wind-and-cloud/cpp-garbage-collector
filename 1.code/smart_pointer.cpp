/********************************************************
	智能指针类的实现
 ********************************************************/

#include<iostream>
#include<mutex>
#include"smart_pointer.h"
using namespace std;
 
/* 子类参构造函数&带参数构造函数 */
template<typename T>
inline smart_pointer<T>::smart_pointer(T *ptr)
{
    if(ptr){
        cout<<"子类默认构造"<<endl;
        _ptr = ptr;
        this->Increase();
    }
}   
 
/* 子类析构函数 */
template<typename T>
smart_pointer<T>::~smart_pointer()
{
    /* 指针非空才析构 */
    if(this->_ptr){
        cout<<"子类析构,计数减1"<<endl;
        if(this->Get_Reference())
            this->Decrease();
        if(!(this->Get_Reference()) ){
            cout<<"(((子类析构,主内存被释放)))"<<endl;
            delete _ptr;
            _ptr = NULL;
        }
    }
}
 
/* 得到引用计数值 */
template<typename T>
inline size_t smart_pointer<T>::use_count()
{
    return this->Get_Reference();
}
 
/* 拷贝构造 */
template<typename T>
inline smart_pointer<T>::smart_pointer(smart_pointer<T> &sp)
{
    cout<<"子类拷贝构造"<<endl;
 
    /* 防止自己对自己的拷贝 */
    if(this != &sp){
        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    
}
/* 赋值构造 */
template<typename T>
inline smart_pointer<T> &smart_pointer<T>::operator=(smart_pointer<T> &sp)
{
 
    /* 防止自己对自己的赋值以及指向相同内存单元的赋值 */
    if(this != &sp){
 
        cout<<"赋值构造"<<endl;
 
        /* 如果不是构造一个新智能指针并且两个只能指针不是指向同一内存单元 */
        /* =左边引用计数减1,=右边引用计数加1 */
        if(this->_ptr && this->_ptr != sp._ptr){
            this->Decrease();
 
            /* 引用计数为0时 */
            if(!this->Get_Reference()){
                cout<<"引用计数为0,主动调用析构"<<endl;
                this->~smart_pointer();
                //this->~Sp_counter();
                cout<<"调用完毕"<<endl;
            }
        }
 
        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    return *this;
}
 
/* 重载解引用*运算符 */
template<typename T>
inline T &smart_pointer<T>::operator*()
{
    return *(this->_ptr);
}
template<typename T>
inline T *smart_pointer<T>::operator->(void)
{
    return this->_ptr;
}