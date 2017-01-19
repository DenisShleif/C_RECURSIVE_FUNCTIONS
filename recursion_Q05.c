///Write a function to count the number of multiples of m between a and b
///in an array of integers A. Where b >=a, and a, b, and m are all whole numbers.
///NOTE that the multiples are between the whole numbers a and b … a and b are not indices in the array.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///SubFunction
int valBet(int n, int min, int max){
    return n >= min && n <= max;
}

void outputArray (int *A, int nA){
    int i;
    for (i = 0; i < nA; i++)
        printf ("A [%2i] = %3i\n",i,A[i]);
}

///function
int f5_I (int* A,int n,int m, int a, int b){
    int i;
    int tmp = 0;
    for (i = 0; i < n; i++)
        if (valBet (A[i],a,b) && !(A[i] % m))
            tmp++;
    return tmp;
}

///function
int f5_R (int* A,int *n,int m, int a, int b){
   if (A == n + 1)
        return 0;
    return f5_R (A + 1,n,m,a,b) + (valBet (*A,a,b) && !(*A % m));
}

///Main
int main (){
    int A [MAX_LENGTH] = {5,76,34,65,20,987,32,54,78,43,23,76,70,34,23};
    int n = 15;
    int m = 10;
    int a = 20;
    int b = 100;

    printf ("Array:\n");
    outputArray (A,n);
    printf ("\nThe number of multiples of %i between %i and %i in the array are\nIteritavly: %i\nRecursivly: %i\n",m,a,b,f5_I(A,n,m,a,b),f5_R(A,&A[n],m,a,b));

    system ("pause");
}
