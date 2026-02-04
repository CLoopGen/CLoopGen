#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern int t;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < n; ++t)
    for (r = 0; r < n; ++r)
        for (s = 0; s < n; ++s)
            (*B)[r][s] += A[r][t] * A[s][t];
}
