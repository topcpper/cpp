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
#include <utility>
using namespace std;

class anagram_node
{
public:
    string str ;
    set<string> * pset;
    anagram_node():pset(NULL){};
    ~anagram_node()
        {
            cout<<"here is deconstructor"<<endl;
                                
            delete pset;
            
        }
    operator string()
        {
            return str;
        }
    
    bool operator< (const anagram_node & data) const; // for use of stl sort
    
};
    
set<string> ssec; // the dics
set<anagram_node> anaset ;
set<anagram_node> anaset2 ;
// void readdata();
 void dealdata();
// void output();
const string get_anagram(const string & data);


int main(int arg ,char *arv[])
{
        
    // cout<<sizeof(anagram_node)<<endl;
                
    // anagram_node anadata[2] ;
    // anadata[0].str="aaa";
    // anadata[0].pset= new set<string>;
    // anadata[0].pset->insert("haha");
    
    // anadata[1].str="aaa";
    // anadata[1].pset= new set<string>;
    // anadata[1].pset->insert("gag");

    // anaset.insert(anadata[0]);
    // anaset.insert(anadata[1]);
    // cout<<anaset.size()<<endl;
    
        
    // // sort(anadata,anadata+2); 利用set 就不用 sort 了
    // cout<<(*(anaset.begin())).str<<endl;
        
        
//        cout<<get_anagram(data);

    ssec.insert("haha");
    ssec.insert("ahha");
    ssec.insert("ahah");
    dealdata();
    cout<<anaset.size()<<endl;
    cout<<(*anaset.begin()).pset->size()<<endl;
    cout<<*(*anaset.begin()).pset->begin()<<endl;
    cout<<anaset.begin()->pset<<endl;
    
    // anagram_node node1 ;
    
    // node1.str="aaga";
    // node1.pset=new set<string> ;
    
    // node1.pset->insert("123");
    // node1.pset->insert("456");
    
    // set<anagram_node> tempset ;
    // tempset.insert(node1);
    // cout<<node1.pset<<endl;
    // cout<<tempset.begin()->pset<<endl;

   cout<<"here is test:"<<endl;
    
    anagram_node pnode1 ;
    
    (pnode1).str = "haha";
    (pnode1).pset = new set<string>;
    (pnode1).pset->insert("haha");
    anaset2.insert(pnode1);
    
    cout<<anaset2.begin()->pset<<endl;
    
    cout<<"deleete"<<endl;
    cout<<anaset2.begin()->pset<<endl;
    cout<<"test end"<<endl;
        

    
    
    
        
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
        anatemp.pset = new set<string>;
        cout<<anatemp.pset<<endl;
        
        pairtemp = anaset.insert(anatemp);
        pairtemp.first->pset->insert(*it);
        
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


