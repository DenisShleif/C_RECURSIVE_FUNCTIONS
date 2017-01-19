///Write a function to compute: signma (i = n -> m) (7xi)
///where n >= m, x ,m ,n are all integers. Return the sum.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_TERMS 10

///Iternative Function
int f4_I (int x, int m, int n){
    return 7 * x * (n + m) * (n - m + 1) / 2;
}

///Recursive Function
int f4_R (int x, int m, int n){
    if (n == m)
        return 7 * x * m;
    else
        return f4_R (x,m,n - 1) + 7 * x * n;
}

///Main
int main (){
    int i;
    for (i = 1; i <= MAX_TERMS; i++){
        printf ("f4_I(%2i) = %i\n",i,f4_I (i,3,7));
        printf ("f4_R(%2i) = %i\n",i,f4_R (i,3,7));
    }
    system ("pause");
}
