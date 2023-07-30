#include<stdio.h>
#include<time.h>

int factorial(int n){
    //check special case
    if(n<=1) return 1;
    // otherwise
    return n*factorial(n-1);
}

int sum(int a[],int N){
    if(N==0) return 0;
    return a[N-1] + sum(a,N-1);
}

int sum2(int a[],int m,int n){
    if (m==n) return a[m];
    return sum2(a,m,(m+n)/2) + sum2(a,(m+n)/2+1,n);
}

int strlength(char *str){
    if (*str =='\0') return 0;
    return 1 + strlength(str+1);
}

int digit(int number){
    if (number/10 == 0) return 1;
    return 1 + digit(number/10);
}

int count=0;
void  HNTower (int n, char A, char B, char C){
    if (n == 1) 
    // move the disk from A to B
    // printf("Move from %c to %c \n", A, B);
    count ++;
    else {
        //move n-1 from A to C using B
        HNTower(n-1, A, C, B);
        //move 1 from A to B using C
        HNTower(1, A, B, C);
        //move n-1 from C to B using A
        HNTower(n-1, C, B, A);
    }
}

void RBackTrack(int V[],int i,int N,int *D){
//V stores the solution, is an integer array
// v[i]=j means: the queen is put at [i][j]
// i is the step number
// N is the size of problem 
// D is a matrix of NxN D[i][j]=0 if v[i]=-1; otherwist D[i][j]=1
    if (i==N){
        //  V is a solution
        // stop the algorithm
    }
    else {
        while (i<N){
            //find the first jth position so that D[i][j]=0
            for (int j = 0; j < N; j++){
                if (*(D +i*N +j) == 0){ //D[i][j]
                    V[i] = j;
                    *(D + i*N + j) = 1 ;
                    // find all positions that can not be 
                    // vertical, horizontal, diagonal
                    // insert code here
                    break;
                }
            }
            // call backtrack
            RBackTrack (V,i+1,N,D);
            V[i] = -1;
        }
    }
}

static int tic_time=0;
void tic(){
    tic_time =clock();
}
int toc(){
    return clock()-tic_time;
}
int main(){
    // int n;
    // int a[]={1,5,9,8,10,7};
    // int N=sizeof(a)/sizeof (int);
    // scanf("%d",&n);
    // while (n<0){
    //     scanf("%d",&n);
    // }
    // printf("%d! = %d\n",n,factorial(n));
    // printf("Sum = %d\n",sum(a,N));
    // printf("Sum = %d\n",sum2(a,0,N-1));
    // char str[]="Huu Nam";
    // printf("Strlength = %d\n",strlength(str));
    // int number=1089;
    // printf("Sum of digits = %d\n", digit(number));
    HNTower(3,'a','b','c');
    printf("%d\n",count);
    printf("%d\n ",toc);
    // 8 Queens
    int V[8]={-1};
    int D[64]={0};
    // RBackTrack(V,0,8,D);
    return 0;
}
