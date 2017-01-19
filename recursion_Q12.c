///Write a function that inserts a number, n,
///into the correct position in an array of sorted integers A.
///Assume that the array is sorted in increasing order.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///HelperFunction
void outputArray (int *A1, int nA1, int *A2, int nA2, int *A3, int nA3){
    int i = 0;
    printf ("Original\t\tIterativly\t\tRecursively\n Array:\t\t\t Modified\t\t  Modified\n\t\t\t  Array:\t\t   Array\n");
    while (i < nA1 || i < nA2 || i < nA3){
        if (i < nA1)
            printf ("A [%2i] = %2i\t\t",i,A1[i]);
        else
            printf ("\t\t\t");
        if (i < nA2)
            printf ("A [%2i] = %2i\t\t",i,A2[i]);
        else
            printf ("\t\t\t");
        if (i < nA3)
            printf ("A [%2i] = %2i\t\t",i,A3[i]);
        else
            printf ("\t\t\t");
        printf ("\n");
        i++;
    }
}

int findN (int *A,int nA,int i,int n){
    if (A[i] <= n)
        return findN (A,nA,i + 1,n);
    return i;
}

int swap (int *a, int *b){
    *a = *a - *b;
    *b = *b + *a;
    *a = *b - *a;
}

///Iterative Function
void f12_I (int *A, int *nA,int n){
    int i = *nA - 1;
    while (A[i] > n)
        A[i + 1] = A[i--];
    A[i + 1] = n;
    (*nA)++;
}

///Recursive Function
void f12_R (int *A, int *nA,int i,int n){
    if (i == 0){
        A[i] = n;
        (*nA)++;
    }
    else if (A[i - 1] > n){
        A[i] = A[i - 1];
        f12_R(A,nA,i - 1,n);
    }
    else{
        A[i] = n;
        (*nA)++;
    }
}

int main (){
    int A1 [MAX_LENGTH] = {2,5,7,8,11,14,19,26,38,49,54,69,73,89};
    int A2 [MAX_LENGTH] = {2,5,7,8,11,14,19,26,38,49,54,69,73,89};
    int A3 [MAX_LENGTH] = {2,5,7,8,11,14,19,26,38,49,54,69,73,89};
    int nA1 = 14;
    int nA2 = 14;
    int nA3 = 14;
    int n = 52;

    f12_I (A2,&nA2,n);
    f12_R (A3,&nA3,nA3,n);
    outputArray (A1, nA1, A2, nA2, A3, nA3);
    printf ("Integer inserted = %i\n\n",n);

    system ("pause");
}
