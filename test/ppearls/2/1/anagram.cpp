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
/*error
 * if the testcode in the main function, or use the heap mem
 * *** glibc detected *** /home/cpper/workspace/c++/test/ppearls/2/1/anagram:
 *  double free or corruption (fasttop): 0x091d01a8 ***
 *  but the sub function does'not return the error
 */

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class anagram_node
{
public:
    string str ;
    set<string>  sset;
    operator string()
        {
            return str;
        }
    bool operator< (const anagram_node & data) const; // for use of stl sort
};
    
set<string> ssec; // the dics
set<anagram_node> anaset ;

// void readdata();
 void dealdata();
// void output();
const string get_anagram(const string & data);


int main(int arg ,char *arv[])
{
    // // sort(anadata,anadata+2); 利用set 就不用 sort 了
    ssec.insert("haha");
    ssec.insert("ahha");
    ssec.insert("ahah");
    dealdata();
    
    
        
}
// void dealdata()
// {
    
    
// }
void dealdata()
{
    anagram_node  anatemp ;
    pair< set<anagram_node>::iterator ,bool > pairtemp;
    
    
    for(set<string>::iterator it = ssec.begin() ; it!=ssec.end() ; it++)
    {
        anatemp.str = get_anagram(*it);
        pairtemp = anaset.insert(anatemp);
        const_cast<anagram_node&>(*(pairtemp.first)).sset.insert(*it);
        
        
        //pairtemp.first->sset.insert(*it);
    }
  

}


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


