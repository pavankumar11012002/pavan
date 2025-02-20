#include <stdio.h>
 #include <string.h>
 int main() {
  char dna[100];
  char pattern[20];
  int count = 0;

  printf("Enter DNA Sequence: ");
  scanf("%s", dna);
 
  printf("Enter pattern to search: ");
  scanf("%s", pattern);
 
  int dna_len = strlen(dna);
  int pattern_len = strlen(pattern);
 
  for (int i = 0; i <= dna_len - pattern_len; i++) {
  if (strncmp(dna + i, pattern, pattern_len) == 0) {
  count++;
  }
  }
  printf("Pattern found %d time(s) in the DNA sequence.\n", count);
  return 0;
 }
