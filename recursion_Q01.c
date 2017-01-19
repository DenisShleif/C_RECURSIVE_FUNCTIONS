///Write a function to compute the nth term in the following sequence of numbers:
///17, 26, 35, 44, 53, … Return the term.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define BASE_CASE 8
#define RECURENCE_RELATION 9

///Iterative function
int f1_I (int n){
    return RECURENCE_RELATION * n + BASE_CASE;
}

///Recursive Function
int f1_R (int n){
    if (!n)
        return BASE_CASE;
    else
        return f1_R (n - 1) + RECURENCE_RELATION;
}

///Main
int main (){
    int n = 7;
    printf ("Iterative: The %ith term is %i\n",n,f1_I (n));
    printf ("Recursive: The %ith term is %i\n",n,f1_R (n));
    system ("pause");
}
