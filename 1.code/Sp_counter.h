/*************************************************************************
	计数基类声明
 ************************************************************************/
 
#include<iostream>
#include<mutex>
#ifndef __SP_COUNTER_H__
#define __SP_COUNTER_H__
using namespace std;

/* 引用计数基类 */
class Sp_counter {
private :
    size_t *_count;
    std::mutex mt;
public :
    Sp_counter();
    virtual ~Sp_counter();
    Sp_counter& operator=(Sp_counter& spc);
    Sp_counter& GetCounter();
    size_t Get_Reference();
    virtual void Increase();
    virtual void Decrease();
};

#endif