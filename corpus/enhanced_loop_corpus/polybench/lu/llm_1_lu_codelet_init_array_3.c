#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int t;
for (t = 0; t < n * n; ++t) {
    r = t / n;
    s = t % n;
    A[r][s] = (*B)[r][s];
}
}
