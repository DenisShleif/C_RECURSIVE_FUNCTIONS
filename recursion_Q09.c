///Write a function that counts all of the characters, c,
///in the string s. Return the count of the character c in the string s.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///Iterative Function
int f9_I (char *s){
    int i = 0;
    while (s[i])
        i++;
    return i;
}

///Recursive Function
int f9_R (char *s){
    if (!*s)
        return 0;
    return f9_R (s + 1) + 1;
}

int main (){
    char s [MAX_LENGTH] = "ftrniJNUIrji9548 50jgf fmo";

    printf ("The number of characters in string %s is\nIterativly: %i\nRecursivly: %i\n\n",s,f9_I(s),f9_R(s));

    system ("pause");
}
