///A sequence is defined by the following recurrence relation: tn = 7t(n - 1) - 4t(n - 2) - 9t(n - 3)
///and the base case: t1 = 0, t2 = 5, t3 = 3
///Write a function to determine tn given n.
/// Write this function both recursively AND iteratively.
///Do not bother trying to write the more efficient version of the recursive function.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define t1 0
#define t2 5
#define t3 3
#define m1 7
#define m2 -4
#define m3 -9
#define MAX_TERMS 10

///Iternary Function
int f2_I (int n){
    int tn [3] = {t1,t2,t3};
    int i = 3;
    int k;
    int tmp;

    if (n <= 3)
        return tn [n - 1];
    else
        while (i != n){
            tmp = m1 * tn [2] + m2 * tn [1] + m3 * tn [0];
            for (k = 0; k < 2; k++)
                tn [k] = tn [k + 1];
            tn [2] = tmp;
            i++;
        }
    return tn [2];
}

///Recursive Function
f2_R (int n){
    switch (n){
    case 1: return t1;
    case 2: return t2;
    case 3: return t3;
    default: return m1 * f2_R(n-1) + m2 * f2_R(n-2) + m3 * f2_R(n-3);
    }
}

///Main
int main (){
    int i;
    for (i = 1; i <= MAX_TERMS; i++){
        printf ("f2_I(%2i) = %i\n",i,f2_I (i));
        printf ("f2_R(%2i) = %i\n",i,f2_R (i));
    }
    system ("pause");
}

