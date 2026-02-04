#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < n; ++r)
        for (s = 0; s < n; ++s)
            if (r == 0 || s == 0)
                A[r][s] = (*B)[r][s];
            else
                A[r][s] = (*B)[r][s] + A[r-1][s] + A[r][s-1] - A[r-1][s-1];
}
