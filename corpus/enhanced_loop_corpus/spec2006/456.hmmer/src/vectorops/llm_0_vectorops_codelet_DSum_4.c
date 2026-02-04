#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < n; i++)
    for (x = i; x < i+1; x++)
        sum += vec[x];
}
