#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < n && r < 100; ++r)  // Reduced trip count to cap at 100, limiting computational load
        for (s = 0; s < n && s < 100; ++s)
            A[r][s] = (*B)[r][s];
}
