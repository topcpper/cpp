/*************************************************************
*
*tsizeclass.cpp: test the size of class
*auther     : caowg
*Written on : 11/09/12.
*
*************************************************************/

#include <iostream>

using namespace std;

class x
{
};

class B: public virtual x
{
};

class A:public virtual x
{
};

class c :public A,public B
{
};

    
    
    
    
int main(int arg ,char *arv[])
    {
        cout << "sizeof x :"<<sizeof(x)<<endl; 
        cout << "sizeof a :"<<sizeof(A)<<endl;
        cout << "sizeof b :"<<sizeof(B)<<endl;

        cout << "sizeof c :"<<sizeof(c)<<endl;
        return 0 ;
        
        
        
    }
