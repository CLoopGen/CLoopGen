#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (r = 0; r < n; ++r)
        for (s = 0; s < n; ++s) {
            temp = (*B)[r][s] + A[r][s]; 
            A[r][s] = temp;
        }
}
