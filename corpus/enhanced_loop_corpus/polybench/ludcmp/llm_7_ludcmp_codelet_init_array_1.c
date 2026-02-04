#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++)
        A[i][j] = (double)(-(j + 1) % (n + 1)) / (n + 1) + 1;
    for (j = i + 1; j < n; j++) {
        A[i][j] = A[i][j-1] / 2.0; // Introduces RAW dependency on previous element in same row
    }
    A[i][i] = 1; // WAW hazard introduced: overwrites earlier write from first loop when j == i
}
}
