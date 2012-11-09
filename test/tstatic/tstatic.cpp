/*************************************************************
*
*tstatic.cpp: test the static in c++
*auther     : caowg
*Written on : 11/06/12.
*
*************************************************************/

#include <iostream>

using namespace std;
void print();

int main()
{
    int i = 0 ;
    for(i=0 ; i<5 ; i++)
        print();
    return 0 ;
    
}
void print()
{
    static int a ;
    a++;
    cout<< a;
     
}

