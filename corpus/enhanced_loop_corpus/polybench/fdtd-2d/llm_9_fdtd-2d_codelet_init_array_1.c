#include <stdio.h>

#include <inttypes.h>

extern int nx;
extern int ny;
extern double ex[1000][1200];
extern double ey[1000][1200];
extern double hz[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j++) {
        double temp1 = (double)i;
        double temp2 = temp1 * (j + 1);
        double temp3 = temp1 * (j + 2);
        double temp4 = temp1 * (j + 3);
        ex[i][j] = temp2 / nx;
        ey[i][j] = temp3 / ny;
        hz[i][j] = temp4 / nx;
        
        // Additional computational work to increase intensity
        ex[i][j] += (temp2 + temp3) / (nx + ny);
        ey[i][j] += (temp3 + temp4) / (nx * 2);
        hz[i][j] -= (temp2 + temp4) / (ny * 2);
    }

}
