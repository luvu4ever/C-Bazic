#define _DEBUG_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX (2000)

void FailureFunction(const char P[], int F[])
{
  const int m = strlen(P);
  for (int i = 0; i < m; i++)
    F[i] = 0;
  int i = 1;
  int j = 0;
  while (i < m)
  {
    if (P[i] == P[j])
    { // we have matched j+1 chars
      F[i] = j + 1;
      i++, j++;
    }
    else if (j > 0) // use failure function to shift P
      j = F[j - 1];
    else
    {
      F[i] = 0; // no match
      i++;
    }
  }
}

// kmp match

int KMPMatch(const char T[], const char P[])
{
    int ans = -1;
  int *F = (int *)malloc(strlen(T) * sizeof(int));
  const int m = strlen(P);
  const int n = strlen(T);
  FailureFunction(P, F);
  int i = 0;
  int j = 0;

  while (i < n){
    if (T[i] == P[j])
      if (j == m-1){
        ans = i-j;
        j = F[j-1];
      }
      else{
        i++, j++;
      }
    else{
      if (j > 0)
        j = F[j - 1];
      else
        i++;
    }
  }
  return ans; // no match
}

void KMPSearch(char* txt, char* pat)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int F[M];
 
    // Preprocess the pattern (calculate lps[] array)
    FailureFunction(pat, F);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            return;
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = F[j - 1];
            else
                i = i + 1;
        }
    }
    printf("SubString not found\n");
}

int main() {
  char t[256];
  char p[256];
  scanf("%s", t);
  scanf("%s", p);
  printf("\nText   :%s\n", t);
  printf("Pattern: %s\n", p);
  int retVal = KMPMatch(t, p);
  if (retVal == -1)
    printf("SubString not found\n");
  else
    printf("\nfound: '%d'\n", retVal);
    printf("\n");
    KMPSearch(t, p);
  return 0;
}
