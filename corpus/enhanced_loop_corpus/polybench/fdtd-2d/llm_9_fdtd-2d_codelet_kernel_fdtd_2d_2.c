#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern int nx;
extern int ny;
extern double ex[1000][1200];
extern double ey[1000][1200];
extern double hz[1000][1200];
extern double _fict_[500];
extern int t;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < tmax; t += 2) {
    for (j = 0; j < ny; j++) {
        ey[0][j] = _fict_[t];
        if (t + 1 < tmax) ey[1][j] = _fict_[t + 1];
    }
    for (i = 2; i < nx; i++)
        for (j = 0; j < ny; j++)
            ey[i][j] = ey[i][j] - 0.25 * (hz[i][j] - hz[i-1][j]) - 0.25 * (hz[i][j] - hz[i-1][j]);
    for (i = 0; i < nx; i++)
        for (j = 2; j < ny; j++)
            ex[i][j] = ex[i][j] - 0.25 * (hz[i][j] - hz[i][j-1]) - 0.25 * (hz[i][j] - hz[i][j-1]);
    for (i = 0; i < nx - 1; i++)
        for (j = 0; j < ny - 1; j++) {
            double ex_diff = ex[i][j+1] - ex[i][j];
            double ey_diff = ey[i+1][j] - ey[i][j];
            hz[i][j] = hz[i][j] - 0.35 * (ex_diff + ey_diff);
            hz[i][j] = hz[i][j] - 0.35 * (ex_diff + ey_diff);
        }
}
}
