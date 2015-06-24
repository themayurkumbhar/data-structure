#include <stdio.h>

#define MAXARRAY 10

void shellsort(int a[], int total, int index);

int main(void) {
 int array[MAXARRAY] = {0};
 int i = 0;

 /* load some random values into the array */
 for(i = 0; i < MAXARRAY; i++)
  array[i] = rand() % 100; 

 /* print the original array */
 printf("Before shellsort: ");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }
 printf("\n");

 shellsort(array, MAXARRAY, 1);

 /* print the `shellsorted' array */
 printf("After  shellsort: ");
 for(i = 0; i < MAXARRAY; i++) {
  printf(" %d ", array[i]); 
 }
 printf("\n");
 getch();
 return 0;
}

 void shellsort(int a[], int total, int index) {
 int i = 0; 
 int j = 0; 
 int k = 0; 
 int l = 0;

 for(k = 0; k < index; k++) {
  for(i = k; i < total; i += index) {
   l = a[i];
   for(j = (i - index); j >= 0; j -= index) {
    if(a[j] > l)
     a[j + index] = a[j];
    else 
     break;
   }
   a[j + index] = l;
  }
 }

 return;
}
