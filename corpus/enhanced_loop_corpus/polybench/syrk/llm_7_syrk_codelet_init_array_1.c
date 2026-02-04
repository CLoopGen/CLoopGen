#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double C[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp = (double)((i + j + 1) % m);
            C[i][j] = temp / m;
        }
    }
}
