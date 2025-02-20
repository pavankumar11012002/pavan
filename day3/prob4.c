#include <stdio.h>
 int main() {
  int scores[5];
  int highest, lowest, sum = 0;
  printf("Enter 5 scores: ");
  for (int i = 0; i < 5; i++) {
  scanf("%d", &scores[i]);
  sum += scores[i];
  if (i == 0) {
  highest = lowest = scores[i];
  } else {
  if (scores[i] > highest) highest = scores[i];
  if (scores[i] < lowest) lowest = scores[i];
  }
  }
  printf("Highest: %d\n", highest);
  printf("Lowest: %d\n", lowest);
  printf("Average: %.1f\n", (float)sum / 5);
  return 0;
 }
