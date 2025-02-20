#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char n[50], d[50]; int a; } P;

int cmp(const void *a, const void *b) { return strcmp(((P*)a)->d, ((P*)b)->d); }

int main() {
  int n;  printf("Enter number of passengers: ");  scanf("%d", &n);
  P* p = (P*)malloc(n * sizeof(P));

  for (int i = 0; i < n; i++) {
    printf("Passenger %d:\nEnter name: ", i + 1); scanf(" %[^\n]s", p[i].n);
    printf("Enter age: "); scanf("%d", &p[i].a);
    printf("Enter destination: "); scanf(" %[^\n]s", p[i].d);
  }

  qsort(p, n, sizeof(P), cmp);
  printf("\nSorted List (by destination):\n");
  for (int i = 0; i < n; i++) printf("%s - %s\n", p[i].n, p[i].d);

  char s[50]; printf("\nEnter destination to search: "); scanf(" %[^\n]s", s);
  printf("Passengers traveling to %s:\n", s);
  int f=0;
  for (int i = 0; i < n; i++) { if (strcmp(p[i].d, s) == 0) { printf("%s\n", p[i].n); f=1; } }
  if(!f) printf("No passengers found traveling to %s.\n",s);

  free(p);  return 0;
}
