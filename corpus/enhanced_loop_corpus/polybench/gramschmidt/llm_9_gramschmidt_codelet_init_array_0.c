#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1200];
extern double Q[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m * 2; i++)
    for (j = 0; j < n * 2; j++) {
        int idx_i = i % m;
        int idx_j = j % n;
        double base = (double)((idx_i + idx_j) % m);
        double scaled = (base * base) / (m * m) * 50.0 + 15.0;
        A[idx_i][idx_j] = scaled;
        Q[idx_i][idx_j] = (base * (m - base)) / m;
    }

}
