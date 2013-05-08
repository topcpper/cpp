/*************************************************************
*
*anagram.cpp: 变位词
*auther     : caowg
*Written on : 05/08/13.
*
*************************************************************/

/*
 * readfile to set<T>
 * 
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// struct anagram_node
// {
//     string anagram ;
//     set<string> * pset;
// };
class anagram_node
{
public:
    string str ;
    set<string> * pset;
    anagram_node():pset(NULL){};
    bool operator< (const anagram_node & data) const;
    
};
    
// set<string> svec;
// void readdata();
// void dealdata();
// void output();
const string get_anagram(const string & data);


int main(int arg ,char *arv[])
    {
        cout<<sizeof(anagram_node);
        string data("debac");
        anagram_node anadata[2] ;
        anadata[0].str="abc";
        anadata[1].str="aaa";
        if(anadata[0].str<anadata[1].str)
            cout<<"haha"<<endl;
        sort(anadata,anadata+1);
        cout<<anadata[0].str<<endl;
        
        
        cout<<get_anagram(data);
        
        
        
    }
// void dealdata()
// {
    
    
// }

bool anagram_node::operator< (const anagram_node & data) const
{
    return (this->str < data.str );
        
}

const string get_anagram(const string & data)
{
    vector<char > cvec;
    for(int i = 0  ; i<data.size() ; i++)
        cvec.push_back(data[i]);
    sort(cvec.begin(),cvec.end());
    string temp ;
    for(vector<char>::iterator it = cvec.begin() ; it != cvec.end() ; it++)
        temp += *it ;
    return temp;
}


