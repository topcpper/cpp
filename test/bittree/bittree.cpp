/*************************************************************
*
*bittree.cpp: it is my impletion of bittree
*auther     : caowg
*Written on : 04/01/13.
*
*************************************************************/
#include <list>
#include <iostream>
#include "bittree.h"
#include <queue>
using namespace std;

template<typename T>
void bittree<T>:: createBittree( const vector<vectype<T> > &vec)
{
    typename vector< vectype<T> > :: const_iterator itert = vec.begin() ;
    
    
    if(itert == vec.end())
        return ;
 
    queue<Node<T> *> quep;
    
    pnode = new Node<T> ;
    Node<T> * ptemp ;
    T data_temp;
    
    pnode->data = (*itert).data ;
    pnode->left = NULL;
    pnode->right = NULL;
    que.push((*itert).data);
    quep.push(ptemp);
    itert ++ ;
    while( itert != vec.end() && !quep.empty())
    {
        ptemp = quep.front();
        quep.pop();

        // data_temp = que.front() ;
        // que.pop() ;

        if(ptemp == NULL)
        {
            itert++ ;
            itert++ ;
            continue ;
        }
        
        // not null
        
        if((*itert).isnull == 0 )
        {
            ptemp->left = new Node<T>;
            ptemp->left->left=NULL ;
            ptemp->left->right=NULL ;
            
            ptemp->left->data = (*itert).data;
        }
        else
            ptemp->left = NULL ;
        quep.push(ptemp->left);
        
        if(++itert == vec.end())
            break ;
        
        if((*itert).isnull == 0 )
        {
            ptemp->right = new Node<T>;
            ptemp->right->left =NULL ;
            ptemp->right->right = NULL ;
            
            ptemp->right->data = (*itert).data;
        }
        else
            ptemp->right = NULL ;
        quep.push(ptemp->right);
        itert++ ;        
    }
}





int main(int arg ,char *arv[])
{

    // test 
    vector< vectype<int> > vec ;
    vectype<int> node[6] ;
    node[0].data = 1;
    node[0].isnull = 0;

    node[1].data = 0;
    node[1].isnull = 1;
    node[2].data = 3;
    node[2].isnull = 0;
    node[3].data = 1;
    node[3].isnull = 1;
    node[4].data = 1;
    node[4].isnull = 1;
    node[5].data = 1;
    node[5].isnull = 0;

    bittree<int> tree ;
    tree.createBittree(vec);
    
    
        
}
