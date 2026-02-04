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
for (i = 0; i < nm; i++)
    for (j = 0; j < nl; j += 2) {
        int temp1 = i * (j + 2);
        int temp2 = (temp1 + 2) % nk;
        double numerator = (double)(temp2);
        D[i][j] = numerator / (5.0 * nk);
        if (j + 1 < nl)
            D[i][j+1] = (double)((i * (j + 3) + 2) % nk) / (5.0 * nk);
    }
}
