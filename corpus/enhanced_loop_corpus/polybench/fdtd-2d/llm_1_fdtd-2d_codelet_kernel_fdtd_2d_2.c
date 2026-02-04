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
for (t = 0; t < tmax; t++) {
    for (j = 0; j < ny; j++) {
        ey[0][j] = _fict_[t];
        for (i = 1; i < nx; i++) {
            ey[i][j] = ey[i][j] - 0.5 * (hz[i][j] - hz[i - 1][j]);
        }
        for (i = 0; i < nx; i++) {
            if (j > 0) {
                ex[i][j] = ex[i][j] - 0.5 * (hz[i][j] - hz[i][j - 1]);
            }
            if (i < nx - 1 && j < ny - 1) {
                hz[i][j] = hz[i][j] - 0.69999999999999996 * (ex[i][j + 1] - ex[i][j] + ey[i + 1][j] - ey[i][j]);
            }
        }
    }
}
}
