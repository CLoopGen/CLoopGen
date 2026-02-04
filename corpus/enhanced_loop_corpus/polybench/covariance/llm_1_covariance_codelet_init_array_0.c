#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int ii = 0; ii < 700; ii++) {
    for (int jj = 0; jj < 600; jj++) {
        int i1 = 2 * ii, i2 = 2 * ii + 1;
        int j1 = 2 * jj, j2 = 2 * jj + 1;
        data[i1][j1] = ((double)i1 * j1) / 1200;
        if (i2 < 1400 && j1 < 1200) data[i2][j1] = ((double)i2 * j1) / 1200;
        if (i1 < 1400 && j2 < 1200) data[i1][j2] = ((double)i1 * j2) / 1200;
        if (i2 < 1400 && j2 < 1200) data[i2][j2] = ((double)i2 * j2) / 1200;
    }
}
}
