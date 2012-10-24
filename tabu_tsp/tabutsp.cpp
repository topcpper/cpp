/*************************************************************
*
*tabutsp.cpp: an implecation of tabu search for TSP 
*auther     : caowg
*Written on : 10/24/12.
*
*************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

const int N = 5;
const int MAX = 9999;


int sequence[N]; // the sequence of the vertex in the  path
int tabu[N][N]; // the tabu e.g. : tabu[i][j]=k ,if k>0,then the vertex j cannot be placed at i in the sequence
const tabulength = 5;


typedef struct Solution // the 
{
    int sequence[N] ;
    int length ;
    
};
Solution opt ;
int cur_length ;


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


    
    

    
    return 0 ;
    
    
}

void greedy()
{
    int i ;
    int min;
    int va ,vb ;
    int cursor = 0 ;
    
    
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
            }
        }
    }
    
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
            file >> ajcent[i][j] ;
    }
    file.close();

    //init tabu  & ajcent
    for(i = 0 ; i < N ; i++)
        for(j = 0 ; j< N ; j++)
        {
            tabu[i][j] = 0 ;
            ajcent[i][j] = MAX ;
            
        }
    

    // 调用greedy() to get the local opt
    greedy();
    
    
}



inline int getleft(int sequeid)
{
    int vertex = sequence[sequeid];
    
    return sequeid > 0 ? ajcent[vertex][sequence[sequeid-1]] : 0;
    
}

inline int getright(int sequenid)
{
    int vertex = sequence[sequenid] ;

    return sequid < N-1 ? ajcent[vertex][sequence[sequeid+1]] : 0 ;
    
}

inline int getdelta(const int& i ,const int& j)
{
    int oldl ,newl,temp ;
    oldl = getleft(i)+getleft(j)+getright(i)+getright(j);
    //临时交换,便于计算
    temp = sequence[i] ;
    sequence[i] = sequence[j] ;
    sequence[j] = temp ;
    
    newl = getleft(i)+getleft(j)+getright(i)+getright(j);
    // 换回
    temp = sequence[i] ;
    sequence[i] = sequence[j] ;
    sequence[j] = temp ;
    return newl -oldl ;
    
}


void tabus()
{
    Min min ;
    Min tabumin ;
    
    int mark=1 ;
    int i ,j ;
    
    int delta ;
    
    while(mark)
    {
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
        
        if(tabumin.delta + cur_opt.length < opt.length) //aspiration
        {
            temp = sequence[tabumin.i];
            sequence[i] =  sequence[j] ;
            sequence[j] = temp ;
            for(i = 0 ; i < N ;i++)
                opt.sequence[i] = sequence[i] ;
            cur_length = tabumin.delta + cur_length ;
            opt.length = cur_.length ;
            
        }
        else
        {
            tabu[i][sequence[i]] = tabulength ;
            tabu[j][sequence[j]] = tabulength ;
            
            temp = sequence[min.i] ;
            sequence[i] = sequence[j] ;
            sequence[j] = temp ;
            cur_length = min.delta + cur_length ;
        }
        
        
        
        
    }// end while
    
}
