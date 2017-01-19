///A sequence is defined by the following recurrence relation: tn = at(n-1) - bt(n-2) + ct(n-3) - dtn(n-4) + e
///and the base case: t1 = w, t2 = x, t3 = y, and t4 = z
///Write a function to determine the nth term in such a sequence.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_TERMS 10

///Struct
struct expType{
    int a;
    int b;
    int c;
    int d;
    int e;
    int w;
    int x;
    int y;
    int z;
};

///function
int f3_I (int n,struct expType exp){
    int tn [4] = {exp.w,exp.x,exp.y,exp.z};
    int i = 4;
    int k;
    int tmp;

    if (n <= 4)
        return tn [n - 1];
    else
        while (i != n){
            tmp = exp.a * tn [3] - exp.b * tn [2] + exp.c * tn [1] - exp.d * tn [0] + exp.e;
                for (k = 0; k < 3; k++)
                    tn [k] = tn [k + 1];
            tn [3] = tmp;
            i++;
        }
    return tn [3];
}

///function
int f3_R (int n,struct expType *exp){
    switch (n){
    case 1: return exp -> w;
    case 2: return exp -> x;
    case 3: return exp -> y;
    case 4: return exp -> z;
    default: return exp -> a * f3_R(n-1,exp) - exp -> b * f3_R(n-2,exp) + exp -> c * f3_R(n-3,exp) - exp -> d * f3_R(n-4,exp) + exp -> e;
    }
}

///Main
int main (){
    struct expType exp;
    int i;

    exp.a = 5;
    exp.b = 3;
    exp.c = 6;
    exp.d = 8;
    exp.e = 2;
    exp.w = 5;
    exp.x = 7;
    exp.y = 43;
    exp.z = 76;

    for (i = 1; i <= MAX_TERMS; i++){
        printf ("f3_I(%2i) = %i\n",i,f3_I (i,exp));
        printf ("f3_R(%2i) = %i\n",i,f3_R (i,&exp));
    }
    system ("pause");
}
