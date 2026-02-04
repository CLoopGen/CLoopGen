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
for (t = 0; t < n; t += 2) {
    for (r = 0; r < n; ++r) {
        double temp1[2000], temp2[2000];
        for (s = 0; s < n; ++s) {
            temp1[s] = A[r][t];
            if (t + 1 < n) temp2[s] = A[r][t + 1];
        }
        for (s = 0; s < n; ++s) {
            (*B)[r][s] += temp1[s] * A[s][t];
            if (t + 1 < n) (*B)[r][s] += temp2[s] * A[s][t + 1];
        }
    }
}
}
