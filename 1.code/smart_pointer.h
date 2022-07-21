/********************************************************
	智能指针类声明
 ********************************************************/

#include<iostream>
#include<mutex>
#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__
#include "Sp_counter.h"
using namespace std;

template<typename T>
class smart_pointer : public Sp_counter {
private :
    T *_ptr;
public:
    smart_pointer(T *ptr = NULL);               
    ~smart_pointer();                               
    smart_pointer(smart_pointer<T> &);
    smart_pointer<T> &operator=(smart_pointer<T> &);
    T &operator*();
    T *operator->(void);
    size_t use_count();
        
};

#endif