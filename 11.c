#include <stdio.h>
#include <malloc.h>
#include <omp.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{ 
int i,j,threads; 
int x[10]; 
int *sum_of_powers; 
int n=10; 

if (argc> 1) 
{ 
threads = atoi(argv[1]); 
if (omp_get_dynamic()) 
{ 
omp_set_dynamic(0); 
printf("called omp_set_dynamic(0)\n"); 
} 
omp_set_num_threads(threads); 
} 
printf("%d threads max\n",omp_get_max_threads()); 
sum_of_powers = (int *) malloc(n * sizeof(int)); 

#pragma omp parallel for private(j) lastprivate(x) 
for (i=0; i<n; i++) 
{ 
printf("%d threads currently executing\n",omp_get_num_threads()); 
x[0]  = 1; 
for (j=1; j<4; j++) x[j] = x[j-1] * (i+1); 
sum_of_powers[i] = x[0] + x[1] + x[2] + x[3]; 
} 
for (i=0; i<n; i++) 
{ 
printf("Sum of powers 0-3 of %d = %d\n",i+1,sum_of_powers[i]);
} 
printf("n cubed = %d\n",x[3]); 
return 0; 
} 
