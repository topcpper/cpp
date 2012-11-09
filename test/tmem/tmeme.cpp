/*************************************************************
*
*tmeme.cpp: test the mem in the virtual class
*auther     : caowg
*Written on : 11/09/12.
*
*************************************************************/

#include <iostream>
#include <memory.h>
#include <cstring>
using namespace std;

class shape
{
public:
    shape()
        {
            memset(this,0,sizeof(shape));
        }
//        virtual ~shape(); 
    
    
};

class shape1
{
public:
    shape1(const char * str)
        {
            strcpy(p,str);
            
        }
    
    shape1()
        {
            memset(this,0,sizeof(shape));
        }
    inline void test(shape1& t)
        {
            memcpy(p,&t,sizeof(shape1));
            cout << p <<endl;
            
            
        }
    
    
private:
    char p[10];
        
};   
int main(int arg ,char *arv[])
{
    shape s;
    shape1 s1 ;
    shape1 s0("haha");
    s1.test(s0);
    
    return 0 ;
    
        
}
