/*************************************************************
*
*tset.cpp: test the use of set
*auther     : caowg
*Written on : 05/08/13.
*
*************************************************************/

#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct node
{
    int a;
    int b;
    
};

int main(int arg ,char *arv[])
{
    node n1;

    // set<node> nset;
    // nset.insert(n1);
    vector<node> nvec;
    nvec.push_back(n1);
    
    return 0 ;
    
}
