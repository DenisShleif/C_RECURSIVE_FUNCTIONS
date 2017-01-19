///Write a function that takes a string and evaluates it
///according to the rule that all letter chars get 10 points,
///all number chars get 5 points, all spaces get 20 points and
///all other characters get 1 point except for the addition sign which gets 0 points.
///Return the value of the string.

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

int valChar (char* c){
    if (valBet (c,'a','z') || valBet (c,'A','Z'))
        return 10;
    if (valBet (c,'0','9'))
        return 5;
    if (c == ' ')
        return 20;
    if (c != '+')
        return 1;
    return 0;
}

///function
int f7_I (char* s){
    int tmp = 0;
    while (*s){
        tmp += valChar (*s);
        s++;
    }
    return tmp;
}

int f7_R (char* s){
    if (!*s)
        return 0;
    return f7_R (s + 1) + valChar (*s);
}

///Main
int main (){
    char s [MAX_LENGTH + 1] = "RFJGNRNK  I$ * &Y(*38578379+++580--/";

    printf ("The value of string %s is\nIteritavly: %i\nRecursivly: %i\n\n",s,f7_I(s),f7_R(s));

    system ("pause");
}
