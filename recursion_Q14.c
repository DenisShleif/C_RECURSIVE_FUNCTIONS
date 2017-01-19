///Write a function that finds an element key in an array of sorted integers A.
///If key is found then return the index of key in the array otherwise return -1
///to indicate that it was not found. Assume that there are no duplicate elements in the array. Use a linear search.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///HelperFunction
void outputArray (int *A, int nA){
    int i;
    for (i = 0; i < nA; i++)
        printf ("A [%2i] = %i\n",i,A[i]);
}

///Iterative Function
int f14_I (int *A,int nA,int n){
    int i = 0;
    while (i < nA && A[i] < n)
        i++;
    if (A[i] == n)
        return i;
    return -1;
}

///Recursive Function
int f14_R (int *A, int nA, int i,int n){
    if (A[i] < n)
        return f14_R (A,nA,i + 1,n);
    if (A[i] == n)
        return i;
    return -1;
}

int main (){
    int A [MAX_LENGTH] = {2,5,7,8,11,14,19,26,38,49,54,69,73,89};
    int nA = 14;
    int n = 73;

    printf ("Array:\n");
    outputArray (A,nA);
    printf ("\nThe index of the %i in the array is\nIterativly: %i\nRecursivly: %i\n\n",n,f14_I (A,nA,n),f14_R (A,nA,0,n));

    system("pause");
}
