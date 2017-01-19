///Write a function that determines the square root of a real number r.
///Assume that r will be greater than or equal to 1.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///Helper functions
float absolute (float r){
    if (r < 0)
        return -r;
    return r;
}

///Iterative Function
float f13_I (double r, float tolerance){
    float guess = 1.0;
    while (absolute ((r/guess) - (guess)) > tolerance)
        guess = (r/guess + guess)/2;
    return guess;
}

///Recursive Function
float f13_R (double r, float tolerance, float guess){
    if (absolute ((r/guess) - (guess)) <= tolerance)
        return guess;
    return f13_R(r,tolerance,(r/guess + guess)/2);
}

int main (){
     double r = 254.546767;

    printf ("Iteratively: sqrt (%f) = %f\n",r,f13_I(r,0.00001));
    printf ("Recursively: sqrt (%f) = %f\n",r,f13_R(r,0.00001, 1.0));

    system ("pause");
}
