/********************************************************
	计数基类的实现
 ********************************************************/

#include<iostream>
#include<mutex>
#include"Sp_counter.h"
using namespace std;

/* 引用计数基类 */
Sp_counter :: Sp_counter() {
    cout<<"父类构造,分配counter内存"<<endl;
    _count = new size_t(0);
}

Sp_counter :: ~Sp_counter() {
    if(_count && !(*_count) ){
        cout<<"父类析构"<<endl;
        cout<<"[释放counter内存]"<<endl;
        delete _count;
        _count = NULL;
    }
}

Sp_counter& Sp_counter :: operator = (Sp_counter &spc) {
    cout<<"父类重载="<<endl;
    cout<<"[释放counter内存]"<<endl;
    delete _count;
    this->_count = spc._count;
    return *this;
}

Sp_counter& Sp_counter :: GetCounter() {
    return *this;
}

Sp_counter :: Sp_counter() {
    cout<<"父类构造,分配counter内存"<<endl;
    _count = new size_t(0);
}

size_t Sp_counter :: Get_Reference() {
    return *_count;
}

void Sp_counter :: Increase() {
    mt.lock();
    (*_count)++;
    //cout<<"_count++:"<<*_count<<endl;
    mt.unlock();
}

void Sp_counter :: Decrease() {
    mt.lock();
    (*_count)--;
    //cout<<"_count--:"<<*_count<<endl;
    mt.unlock();
}