/*************************************************************
*
*tabutsp.cpp: an implecation of tabu search for TSP 
*auther     : caowg
*Written on : 10/24/12.
*
*************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int N = 10;
const int MAX = 9999;

int sequence[N]; // the sequence of the vertex in the  path
int tabu[N][N]; // the tabu e.g. : tabu[i][j]=k ,if k>0,then the vertex j cannot be placed at i in the sequence
const int tabulength = 2;


typedef struct Solution // the 
{
    int sequence[N] ;
    int length ;
    
};
Solution opt ;
int cur_length = 0;

typedef struct Min
{
    int i ; // i,j the swap id int the sequenct 
    int j ;
    int delta ; // the increment after swap 
    
};

    
    

int ajcent[N][N]; // the length in the graph


/*
 * function : to get the local opt sulotion
 */ 
void greedy();

/*
 * function : return the shortest edge of vertex and its ajcent 
 * nextv    : its ajcent
 *  
 */ 
int getshortaj_v(int vertex,const vector<int> & vec,int & nextv);



/*
 * function : init the programe
 */ 
void initpro(char * filename);


    
/*
 * function : get the length between sequence vertex and its left_process
 * sequeid :  the sequence of the vertex in the path
 */
inline int getleft(int sequeid);

/*
 * function : get the length between sequence vertex and its right_follower
 * sequeid :  the sequence of the vertex in the path
 */
inline int getright(int sequeid);

/* function : get the delta after swap i,j 
 *
 *
 */
inline int getdelta(const int& i ,const int& j);


/*
 * function : the tabu search
 *
 */ 
void tabus();


int main(int argc, char ** argv)
{
    
    if(argc==2)
    {
        initpro(argv[1]);
    }
//    cout << getdelta(0,2);
   tabus();
    
    
    return 0 ;
    
    
}

void greedy()
{
    vector<int> vec ;
    
    
    int i ,j;
    int min;
    int va ,vb ;
    int next1 ,next2;
    int temp1 ,temp2 ;
    temp1 = temp2 = 0;
    
    
    
    // get the min edge
    min = ajcent[0][0];
    va = vb = 0 ;
    
    for(i = 0 ; i<N ; i++)
    {
        for( j = 0 ; j< N ; j++)
        {
            if(ajcent[i][j] < min)
            {
                va = i ;
                vb = j ;
                min = ajcent[i][j];
            }
        }
    }
    cur_length += min;
    
    // get the greedy sequence
    vec.push_back(va);
    vec.push_back(vb);
    while(vec.size() < N)
    {
        va = *(vec.begin()) ;
        vb = *(vec.end()-1);
        temp1 = getshortaj_v(va,vec,next1);
        temp2 = getshortaj_v(vb,vec,next2);
    
        if( temp1 < temp2)
        {
            vec.insert(vec.begin(),next1);
            cur_length+=temp1 ;
        }
        else
        {
            vec.insert(vec.end(),next2);
            cur_length+= temp2 ;
            
        }
        
                
    }

    cur_length+=ajcent[vec[0]][vec[N-1]];//构成环
    
    opt.length = cur_length ;
    
    for(i = 0 ; i<N ; i++)
    {
        sequence[i] = vec[i];
//        cout << sequence[i]+1<<' ';
        
    }
    cout <<"greedy "<<cur_length << endl;
    
    
    
}

int getshortaj_v(int vertex,const vector<int> & vec,int & nextv)
{
    int i = 0 ;
    int shortedge , shortvertex;
    shortedge = MAX+1 ; // 保证即使无链接也能在把这个点给加上来
    nextv = 0 ;
    
    for(i = 0 ; i<N ; i++)
    {
        if(find(vec.begin(),vec.end(),i)==vec.end())
        {
            if(ajcent[vertex][i] < shortedge)
            {
                shortedge = ajcent[vertex][i] ;
                nextv = i ;
            }
        }
        
    }
    return shortedge;
    
}


void initpro(char * filename)
{
    int i ,j ;
    // 读入 gpaph
    ifstream file ;
    file.open(filename);
    if(file.fail())
    {
        cout << " Error open " << filename <<endl;
        exit(0);
    }
    for(i = 0 ; i< N ; i++)
    {
        for(j = 0 ; j<N ; j++)
        {
            file >> ajcent[i][j] ;
            if(ajcent[i][j]==0)
                ajcent[i][j]=MAX ;
//            cout << ajcent[i][j]<<" ";
        }
        //      cout <<endl;
        
    }
    
    file.close();



    //init tabu  & ajcent
    for(i = 0 ; i < N ; i++)
        for(j = 0 ; j< N ; j++)
        {
            tabu[i][j] = 0 ;
        }
    

    // 调用greedy() to get the local opt
   greedy();
    
    
    
}



inline int getleft(int sequeid)
{
    int vertex = sequence[sequeid];
    
    return sequeid > 0 ? ajcent[vertex][sequence[sequeid-1]] : ajcent[vertex][sequence[N-1]];
    
}

inline int getright(int sequenid)
{
    int vertex = sequence[sequenid] ;

    return sequenid < N-1 ? ajcent[vertex][sequence[sequenid+1]] : ajcent[vertex][sequence[0]] ;
    
}

inline int getdelta(const int& i ,const int& j)
{
    int oldl ,newl,temp ;
    int returnv ;
    
    oldl = getleft(i)+getleft(j)+getright(i)+getright(j);
    //临时交换,便于计算
    temp = sequence[i] ;
    sequence[i] = sequence[j] ;
    sequence[j] = temp ;
    
    newl = getleft(i)+getleft(j)+getright(i)+getright(j);
    if(getleft(i)==MAX || getleft(j)==MAX || getright(i)==MAX || getright(j)==MAX)
        returnv = MAX ;
    else
        returnv = newl -oldl ;
    
    // 换回
    temp = sequence[i] ;
    sequence[i] = sequence[j] ;
    sequence[j] = temp ;
    //cout << "new :" <<newl << " old:" <<oldl<<endl;
    
    return returnv ;
    
}


void tabus()
{
    Min min ;
    Min tabumin ;

    
    int temp,k ;
    
    char mark='y' ;
    int i ,j ;
    
    int delta ;
    int total = 0 ;
    
    int count =10 ;
    
    while(mark!='n')
    {
        tabumin.delta = MAX;
        min.delta = MAX ;
        // for0
        for(i = 0 ; i<N ;i++)
        {
            // for1
            for(j=i+1 ; j< N ; j++)  
            {
                // swap(i,j)  // i,j sequence of the path 
                delta = getdelta(i,j);

                if(tabu[i][sequence[j]] > 0 || tabu[j][sequence[i]]>0 )
                {
                    
                    if(tabumin.delta > delta)
                    {
                        tabumin.i = i ;
                        tabumin.j = j ;
                        tabumin.delta = delta ;
                        
                    }
                    // tabu length -- ?
                    if(tabu[i][sequence[j]]>0)tabu[i][sequence[j]]--;
                    if(tabu[j][sequence[i]]>0)tabu[j][sequence[i]]--;
                    
                }
                else
                {
                    if(min.delta > delta)
                    {
                        min.i = i;
                        min.j = j ;
                        min.delta = delta ;
                    }
                    
                }//end else
            } //end for1
            
        }// end for0
        
        if(tabumin.delta + cur_length < opt.length) //aspiration
        {
            // for(k=0 ; k<N ;k++)
            //     cout << sequence[k]<<' ';
            // cout<<endl;
            temp = sequence[tabumin.i];
            sequence[tabumin.i] =  sequence[tabumin.j] ;
            sequence[tabumin.j] = temp ;
            for(i = 0 ; i < N ;i++)
                opt.sequence[i] = sequence[i] ;
            cur_length = tabumin.delta + cur_length ;
            opt.length = cur_length ;
            // for(k=0 ; k<N ;k++)
            //     cout << sequence[k]<<' ';
            // cout<<endl;
            // cout << "tabu "<<tabumin.i << "-> " <<sequence[tabumin.j] <<" "<< tabumin.j << "->"<<sequence[tabumin.i]<<" delta:"<<tabumin.delta<<endl;
           
            
        }
        else
        {
            tabu[min.i][sequence[min.i]] = tabulength ;
            tabu[min.j][sequence[min.j]] = tabulength ;

            temp = sequence[min.i] ;
            sequence[min.i] = sequence[min.j] ;
            sequence[min.j] = temp ;
            cur_length = min.delta + cur_length ;
//            cout << min.i << " " << min.j <<endl;
            if(cur_length<opt.length)
            {
                opt.length=cur_length;
                for(k=0 ; k<N ; k++)
                    opt.sequence[k]=sequence[k];
            }
            // for(k=0 ; k<N ;k++)
            //     cout << sequence[k]<<' ';
            // cout<<endl;
            
            // cout << min.i << "-> "<<sequence[min.j] <<" "<< min.j << "->"<<sequence[min.i]<<" delta:"<<min.delta<<endl;
        }
        
        count--;
        if(count==0)
        {
            total+=10;
            
            cout<<"已经进行了"<<total<<"次迭代,目前最优解为: "<<opt.length<<endl;
            cout<<"opt.sequence : ";
            

            for(i=0 ; i<N ; i++)
                    cout << opt.sequence[i]+1 << " ";
            cout <<endl;
            
            for(i=0 ; i<N ; i++)
                    cout << sequence[i] +1<< " ";
            cout<<endl;
            
            cout << "press y for continue , n for break"<<endl;
            cin>> mark;
            if(mark=='y')count=10;
            
            
                
        }
        
        
        
        
    }// end while
    
}
