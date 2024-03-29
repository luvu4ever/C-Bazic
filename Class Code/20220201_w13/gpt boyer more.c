

#include <stdio.h>
#include <string.h>
 
// A utility function to get maximum of two integers
int max (int x, int y) { return (x > y)? x: y; }
 
// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic( char *str, int size, int badchar[256]){
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < 256; i++)
         badchar[i] = -1;
 
    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}

 // A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm 

 void search( char *txt,  char *pat){

     int m = strlen(pat);

     int n = strlen(txt);

     int badchar[256];

     /* Fill the bad character array by calling the preprocessing function badCharHeuristic() for given pattern */

     badCharHeuristic(pat, m, badchar);

     int s = 0;   // s is shift of the pattern with respect to text 

     while(s <= (n - m)){

         int j = m-1;

         /* Keep reducing index j of pattern while characters of pattern and text are matching at this shift s*/

         while(j >= 0 && pat[j] == txt[s+j]){

             j--;   // If pattern is present at current shift, then index j will become -1 after the above loop 								   }   if (j < 0){   /* If the pattern is present at current shift, then index j will become -1 after the above loop */   printf("pattern occurs at shift = %d\n", s);   /* Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern. The condition s+m < n is necessary for the case when pattern occurs at the end of text */   s += (s+m < n)? m-badchar