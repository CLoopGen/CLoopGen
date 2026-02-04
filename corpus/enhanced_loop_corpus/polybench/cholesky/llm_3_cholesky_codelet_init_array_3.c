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
    for (s = 0; s < n; s += 2) {
        A[r][s] = (*B)[r][s];  // Strided access with step 2
        if (s + 1 < n)
            A[r][s+1] = (*B)[r][s+1];
    }
}
