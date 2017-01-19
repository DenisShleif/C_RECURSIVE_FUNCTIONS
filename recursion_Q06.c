///An array contains positive integers but the last element is negative.
///The last element of the array is called a sentinel and is used to indicate the end of the array ...
///kind of like the NULL terminator in a string.
///Write a function to compute the sum of the multiples of m in the array.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80
#define SENTINAL -1

///SubFunction
int valBet(int n, int min, int max){
    return n >= min && n <= max;
}

void outputArray (int *A){
   int i = 0;
   while (A[i] >= 0){
        printf ("A [%2i] = %3i\n",i,A[i]);
        i++;
   }
}

///function
int f6_I (int* A,int m){
    int tmp = 0;

    while ((*A) > SENTINAL){
        tmp += !((*A) % m) * (*A);
        A++;
    }
    return tmp;
}

///function
int f6_R (int* A,int m){
   if (*A == SENTINAL)
        return 0;
    return f6_R (A + 1,m) + (*A) * (!(*A % m));
}


///Main
int main (){
    int A [MAX_LENGTH] = {5,76,34,65,20,987,32,54,78,43,23,76,70,34,23,-1};
    int m = 10;

    printf ("Array:\n");
    outputArray (A);
    printf ("\n\nThe Sum of the multiples of %i in the array are\nIteritavly: %i\nRecursivly: %i\n",m,f6_I(A,m),f6_R(A,m));

    system ("pause");
}

