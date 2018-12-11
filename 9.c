#include <stdio.h>
#include <omp.h>
#include<stdlib.h>

int main(void) 
{ 
int i; 
omp_set_num_threads(4); 

#pragma omp parallel private(i) 
{ 
// OMP_NUM_THREADS is not a multiple of 26, 
// which can be considered a bug in this code. 
int LettersPerThread = 26 / omp_get_num_threads(); 
int ThisThreadNum = omp_get_thread_num(); 
int StartLetter = 'a'+ThisThreadNum*LettersPerThread; 
int EndLetter = 'a'+ThisThreadNum*LettersPerThread+LettersPerThread; 
for (i=StartLetter; i<EndLetter; i++) 
printf("%c", i); 
} 
printf("\n"); 
return 0; 
} 
