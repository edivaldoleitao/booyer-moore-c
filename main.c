#include <stdio.h>
typedef unsigned char byte;

int 
boyermoore1 (byte a[], int m,
             byte b[], int n) 
{
   int ult[256]; // o alfabeto é 0..255

   // pré-processamento da palavra a
   for (int f = 0; f < 256; ++f) ult[f] = 0;
   for (int i = 1; i <=  m; ++i) ult[a[i]] = i;

   // busca da palavra a no texto b
   int ocorrs = 0;
   int k = m;
   while (k <= n) {
      // a[1..m] casa com b[k-m+1..k]?
      int i = m, j = k;
      while (i >= 1 && a[i] == b[j]) 
         --i, --j;   
      if (i < 1) ++ocorrs;
      if (k == n) k += 1;
      else k += m - ult[b[k+1]] + 1;
   }
   return ocorrs;
}

int main(void) {

  
  byte a[2] = {'a','b'};
  byte b[5] = {'a','b','a','b'};
  
  int i = boyermoore1( a, 1,  b, 5);
  printf("%i",i);
  return 0;
}
