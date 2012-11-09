/*************************************************************
*
*tstruct.cpp: test the struct array
*auther     : caowg
*Written on : 11/06/12.
*
*************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct mumble
{
    char pc[1];
    
};

    
int main()
{
    string str="haha" ;
     mumble * pmuble =( mumble*) malloc(sizeof( mumble) + strlen(str.c_str)+1 );
    strcpy(mumble->pc,str.c_str);
    cout << mumble->pc ;
    return 0 ;
}
