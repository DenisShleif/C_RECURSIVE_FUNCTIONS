s///Repeat the previous question using a binary search.

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

int av (int n1, int n2){
    return (n1 + n2)/2;
}

///Iterative Function
int f15_I (int *A,int nA, int n){
    int lo = 0;
    int hi = nA - 1;
    int mid = av (hi,lo);

    while (lo != hi){
        if (n > A[mid]){
            lo = mid + 1;
            mid = av (hi,lo);
        }
        else{
            hi = mid;
            mid = av (hi,lo);
        }
    }
    if (A[lo] == n)
        return lo;
    return -1;
}
///Recursive Function
int f15_R (int *A, int lo,int hi,int n){
    if (lo == hi){
        if (A[lo] == n)
            return lo;
        return -1;
    }
    int mid = (lo + hi)/2;
    if (n > A[mid])
        return f15_R (A,mid + 1,hi,n);
    return f15_R (A,lo,mid,n);
}

int main (){
    int A [MAX_LENGTH] = {2,5,7,8,11,14,19,26,38,49,54,69,73,89};
    int nA = 14;
    int n = 79;

    printf ("Array:\n");
    outputArray (A,nA);
    printf ("\nThe index of element %i of the array is\nIterativly: %i\nRecursivly: %i\n\n",n,f15_I (A,nA,n),f15_R (A,0,nA - 1,n));

    system("pause");
}
