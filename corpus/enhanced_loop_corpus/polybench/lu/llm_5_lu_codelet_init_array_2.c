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
    for (r = 0; r < n; ++r) {
        double temp = 0.0;
        for (s = 0; s < n; ++s) {
            if (A[r][t] == 0 || A[s][t] == 0) {
                continue;
            }
            temp += A[r][t] * A[s][t];
        }
        (*B)[r][r] += temp;
    }
}
