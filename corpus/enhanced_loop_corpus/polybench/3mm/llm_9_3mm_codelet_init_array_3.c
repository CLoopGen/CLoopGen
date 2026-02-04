#include <stdio.h>

#include <inttypes.h>

extern int nk;
extern int nl;
extern int nm;
extern double D[1200][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int ii, jj;
for (i = 0; i < nm; i++) {
    for (j = 0; j < nl; j++) {
        for (ii = 0; ii < 3; ii++) {
            for (jj = 0; jj < 3; jj++) {
                if ((i + ii) < nm && (j + jj) < nl) {
                    D[i + ii][j + jj] = (double)(((i + ii) * ((j + jj) + 2) + 2) % nk) / (5 * nk);
                }
            }
        }
    }
}
}
