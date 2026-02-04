#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    int index = (i * 3) % n; // Strided access with wrap-around using stride of 3
    A[index] = ((double)i + 2) / n;
    B[index] = ((double)i + 3) / n;
}
}
