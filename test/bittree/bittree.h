#ifndef BITTREE_H
#define BITTREE_H
#include <vector>
using namespace std;

/* the node of the tree */
template<typename T>
struct Node
{
     Node * left ; /* point to left */
     Node * right ; /* point to right */
     T data; /* data  */
};

/* the container type of the tempopary data array */
template<typename T>
struct vectype
{
     T data ;
     bool isnull ;
};


template<typename T>
class bittree
{
private:
     Node<T> * pnode;

public:
     
     bittree ():pnode(NULL)
     {
     }
     
     /* create the tree from vec
      * vec can support flexible interface */
     void createBittree(const vector<vectype<T> > &vec);
     
     /* void preOrder(bittree & tree); */
     /* void preOrderR(bittree & tree); */
     /* void inOrder(bittree & tree); */
     /* void inOrderR(bittree & tree); */
     /* ~bittree(); */
     
};



#endif
