// Determinant of 6*6 matrix using recurssion 
// can be extended to nXn

#include <stdio.h>
#include <stdlib.h>
static int count =0;

#define PRINT 1
void readMatrix(int (*mat)[6] )
{

    printf("reading the matrix");
    for (int i =0 ; i<6; i++)
        for (int j=0 ; j<6; j++)
            scanf("%d", &mat[i][j]);

}


void printMatrix(int* mat, int n, int m)
{

    if(PRINT)
    {
        printf("printing matrix\n");
        for (int i =0 ; i<n ;i++)
        {
            for (int j=0 ; j<m; j++)
                printf("%d ", *((mat + i*m ) +j));
            
            printf("\n");
            
        }
    }
  } 

int det2mat(int* mat, int n, int m)
{

    if(PRINT)
    {
        printMatrix(mat,n,m);
    }
    int val = ((mat +0)) *((mat +3)) - ((mat +1)) * ((mat +2));
    printf("the val is = %d\n", val);
    return val;
} 

int* createMatix(int* mat,  int n, int m, int ignore)
{
    
    int * new_mat = (int *)malloc((n-1) *(m-1) *sizeof(int));
    
    for (int i =0, ni=0 ; i<n ;i++)
    {
        if (i == 0)
            continue; 
         
        for (int j=0 ,nj=0 ; j<m; j++)
        {
            if (j == ignore)
                continue; 

            new_mat[ni*(n-1) +nj] = *((mat + i*m ) +j);
            nj++;
        
        }
        ni++; 
    }
    return new_mat;
    
}
int matmul(int* mat, int n, int m)
{

    //printf("I am in matmul\n");
    int sign;
    int det=0;
    
    if(n == m && n ==2)
    {
        count++;
        return det2mat((int*)mat, n, m);
        
    }
    for (int j=0 ; j<m; j++)
    {
        //printf("%d ", *((mat + i*m ) +j));

        sign = (j)%2?-1:1;
        int mirror_mat =createMatix((int) mat,m,m, j);
        int curval = *(mat +j);

        det += sign* curval *matmul(mirror_mat,n-1,m-1);
        printf("the sign is %d\n", sign);
        printf("the determinant is %d\n", det);
        //printf("\n");
    }

    return det;
} 

int main(void)
{
    int mat[6][6] ={0};
    /*
    readMatrix(mat);
    printf("printing the matrix\n");

    for (int i =0 ; i<6; i++)
    {
        for (int j=0 ; j<6; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    */
    //int m[3][3] = {{7,2,3}, {4,3,2}, {3,8,1}};
    //int m[4][4] = {{7,2,3, 1}, {4,3,2,7}, {3,-8,32, 6}, {5,1,3, 9}};
    
    int m[6][6] = {{7,2,3, 1, 4,5}, 
                    {4,3,2,7,3,2}, 
                    {3,-8,32, 6,1,9}, 
                    {5,1,3, 9, 8,8},
                    {1,3,6,8,9,2},
                    {3,1,2,3,1,5}};
    int index =6;
    printf("I amhere\n\n");
    for (int i =0 ; i<index; i++)
    {
        for (int j=0 ; j<index; j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
   // printf("\n%d %d %d", 0%2, 1%2, 2%2);
    printf("\n");
    int det = matmul((int*) m, index,index);
    /*for(int i=0; i<index; i++)
    {
        printf("\n%d\n",i);
        int x =createMatix((int) m,index,index, i);
        printMatrix(x, index-1, index-1);
        free(x);
    }*/

   //printf("\n total counts :%d", count); 
   printf("\nAnswer : %d\n", det) ;
}
