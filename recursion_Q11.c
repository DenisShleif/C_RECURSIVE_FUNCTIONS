///Write a function to delete all instances of the character c that occur in the string s.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///Iterative Function
void f11_I (char *s, char c){
    int shift = 0;

    while (*s){
        (*s) = *(s + shift);
        shift += (*s == c);
        s += (*s != c);
    }
}


///Recursive Function
void f11_R (char *s,int shift,char c){
    if (*s){
        (*s) = *(s + shift);
        f11_R (s + (*s != c),shift + (*s == c),c);
    }
}

int main (){
    char s1 [MAX_LENGTH] = "ftrniJNaaaaUIraji95a48 50jgf fmo";
    char s2 [MAX_LENGTH] = "ftrniJNaaaaUIraji95a48 50jgf fmo";
    char c = 'a';

    printf ("Original string: %s\nCharacter to be deleted: %c\n",s1,c);
    f11_I(s1,c);
    f11_R(s2,0,c);
    printf ("Deleted iteritavly: %s\nDeleted Recursibly: %s\n",s1,s2);

    system ("pause");
}
