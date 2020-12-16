//Name: Animesh Jha
// Roll Number: 19EC10007
// Present Address Delhi
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define NROOMS 10
void genDoors(int A [][NROOMS])
{
    for(int z=0;z<NROOMS;z++)
    {
        for(int x=z;x<NROOMS;x++)
        {
            if(x==z)
            {
                A[z][x]=1;
            }
            else
            {
                int temp=rand()%2;
                A[z][x]=temp;
                A[x][z]=temp;   
            }
        }
    }
}
void printConn(int A[][NROOMS])
{
    for(int z=0;z<NROOMS;z++)
    {
        for(int x=0;x<NROOMS;x++)
        {
            printf("%d ",A[z][x]);
        }
        printf("\n");
    }
}
void boolMul(int A[][NROOMS], int B[][NROOMS], int C[][NROOMS])
{
    for(int z=0;z<NROOMS;z++)
    {
        for(int x=0;x<NROOMS;x++)
        {
            C[z][x]=0;
        }
    }
    for(int z=0;z<NROOMS;z++)
    {
        for(int x=0;x<NROOMS;x++)
        {
            for(int c=0;c<NROOMS;c++)
            {
                C[z][x] += A[z][c] * B[c][x];
            }
            if(C[z][x]>1)
                    C[z][x]=1;
        }
    }
}
void copyConn(int B[NROOMS][NROOMS], int A[NROOMS][NROOMS])
{
    for(int z=0;z<NROOMS;z++)
        for(int x=0;x<NROOMS;x++)
            B[z][x]=A[z][x];
}
int main()
{
    srand(time(0));
    /*int A[NROOMS][NROOMS]={ {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
                            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                            {0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}};*/ // sample input for testing
    /*int A[NROOMS][NROOMS]={ {1, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                            {1, 1, 1, 0, 1, 0, 1, 0, 1, 0}, 
                            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0}, 
                            {1, 0, 0, 1, 0, 1, 1, 1, 0, 0}, 
                            {0, 1, 1, 0, 1, 1, 0, 1, 0, 0}, 
                            {1, 0, 0, 1, 1, 1, 1, 0, 1, 0}, 
                            {0, 1, 0, 1, 0, 1, 1, 1, 0, 0}, 
                            {1, 0, 0, 1, 1, 0, 1, 1, 1, 0}, 
                            {0, 1, 0, 0, 0, 1, 0, 1, 1, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};*/ // random input for testing
    int A[NROOMS][NROOMS];
    int B[NROOMS][NROOMS],C[NROOMS][NROOMS];
    genDoors(A);
    printf("Initial connectivity \n");
    printConn(A);
    printf("\n");
    copyConn(B,A);
    // final connectivity will be given by C=A^(NROOMS-1);
    for(int z=1;z<NROOMS-1;z++)
    {
        boolMul(A,B,C);
        //printf("A^%d\n",z+1);
        //printConn(C);
        //printf("\n");
        copyConn(B,C);
    }
    printf("final connectivity is \n");
    printConn(C);
    return 0;
}