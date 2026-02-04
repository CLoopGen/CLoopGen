#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i * i && i > 0; j++) {  // Quadratically increased trip count
        int row = (j - 1) / i + 1;
        int col = (j - 1) % i + 1;
        if (row <= i && col <= i) {
            R1->me[row][col] -= 1.0;
        }
    }
}
