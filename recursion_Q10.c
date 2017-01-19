///Write a function to delete the first occurrence of the character c in the string s.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///Iterative Function
void f10_I (char *s, char c){
    int shift = 0;

    while (*s){
        (*s) = *(s + shift);
        shift += (shift == 0 && (*s == c));
        s++;
    }
}


///Recursive Function
void f10_R (char *s,int shift,char c){
    if (*s){
        (*s) = *(s + shift);
        f10_R (s + 1,shift + (shift == 0 && (*s == c)),c);
    }
    else return;
}

int main (){
    char s1 [MAX_LENGTH] = "ftrniJNaaaaUIraji95a48 50jgf fmo";
    char s2 [MAX_LENGTH] = "ftrniJNaaaaUIraji95a48 50jgf fmo";
    char c = 'a';

    printf ("Original string: %s\nCharacter to be deleted: %c\n",s1,c);
    f10_I(s1,c);
    f10_R(s2,0,c);
    printf ("Deleted iteritavly: %s\nDeleted Recursibly: %s\n",s1,s2);

    system ("pause");
}
