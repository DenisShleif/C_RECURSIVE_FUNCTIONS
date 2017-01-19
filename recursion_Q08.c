///Write a function to determine if a string is a palindrome.
///A palindrome is a word that is still the same word when spelled backwards.
///Here are some palindromes: abba, dud, C, 845q2t2q548. The empty string is also a palindrome.
///Return 1 if the string is a palindrome and 0 if it is not.

///Libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

///Constants
#define MAX_LENGTH 80

///Helper Function
char *lastLetterPointer (char *s){
    while (*s)
        s++;
    return s - 1;
}

///Iterative Function
int f8_I (char *s){
   char *lo = s;
   char *hi = lastLetterPointer (s);

   while (lo <= hi){
        if (*lo != *hi)
            return 0;
        hi--;
        lo++;
   }
    return 1;
}

///Recursve Function
int f8_R (char *lo, char *hi){
    if (lo >= hi)
        return 1;
    else if (*lo == *hi)
        return f8_R (lo + 1, hi - 1);
    else
        return 0;
}

///Main
int main (){
    char s[MAX_LENGTH + 1] = "racecar";

    printf ("%s is a palindrome: %i\n%s is a palindrome: %i\n\n",s,f8_I(s),s,f8_R(s,lastLetterPointer (s)));

    system ("pause");
}
