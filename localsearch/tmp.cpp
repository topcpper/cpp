
char * File_Name;
FILE *fp ;
char outfilename[30];
int Seed ;
int Total_Iterations ;
int Max_Non_Improv_One = 200000 ;
double starting_time, finishing_time, once_total_time, total_time ;

typedef struct Adjacent_Matrix{
         int neighbor ;
         struct Adjacent_Matrix *next ;
         }Adjacent ;
Adjacent * *A_Matrix ;
Adjacent *p1, *q1;

int N, K, G_K;  // node number and color number
int f, f_best, global_f_best;
int * Color; // color array for each vertex
int * Best_Color, * Global_Best_Color; // color array for each vertex
int ** Delta_Matrix;  // incremental matrix for each vertex being colored each color
int ** Edge;   // adjacent matrix
int ** TabuTenure;  // tabu tenure

int ** cost_matrix ;

vector<int> vec_conflict ;


/*
 * function : to init the const matrix  
 * parameter : void 
 * return :    void
 * 
 */ 
void init_cost_matrix();


/* function : to get  the number of the conflict pairs among the graph
 *  the conflict vertexs are pushed into the vector<int > vec_conflict
 * parameter : void
 * return : void 
 *
 */
int conflict_pairs();
