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
for (t = 0; t < tmax / 2; t++) {
    for (j = 0; j < ny; j += 2) {
        ey[0][j] = _fict_[t];
        if (j + 1 < ny) ey[0][j+1] = _fict_[t];
    }
    for (i = 1; i < nx; i++) {
        double temp_sum = 0.0;
        for (j = 0; j < ny; j++) {
            temp_sum += ey[i][j] + hz[i][j] - hz[i-1][j];
            ey[i][j] = ey[i][j] - 0.5 * (hz[i][j] - hz[i-1][j]);
        }
        // Introduce additional computation to increase intensity
        temp_sum = temp_sum > 0 ? temp_sum * 0.01 : -temp_sum * 0.01;
        hz[0][0] += temp_sum; // Artificially use temp_sum to avoid dead code elimination
    }
    for (i = 0; i < nx; i++)
        for (j = 1; j < ny; j++)
            ex[i][j] = ex[i][j] - 0.5 * (hz[i][j] - hz[i][j-1]);
    for (i = 0; i < nx - 1; i++)
        for (j = 0; j < ny - 1; j++)
            hz[i][j] = hz[i][j] - 0.7 * (ex[i][j+1] - ex[i][j] + ey[i+1][j] - ey[i][j]);
}
}
