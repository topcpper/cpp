/*************************************************************
*
*tinilist.cpp: test the init list
*auther     : caowg
*Written on : 11/09/12.
*
*************************************************************/

#include <iostream>

using namespace std;

class x
{
private:
    int i ;
    int j ;
public:
    x(int val):j(val),i(j)
        {
            cout<<i<<" "<<j<<endl;
            
        }
    
    
};

    

int main(int arg ,char *arv[])
{
    x x0(2) ;
    return 0 ;
    
        
}
