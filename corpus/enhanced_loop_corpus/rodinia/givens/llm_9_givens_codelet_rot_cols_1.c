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

extern MAT *mat;
extern MAT *out;
extern u_int i;
extern u_int k;
extern double c;
extern double s;
extern u_int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with decreased effective trip count and simplified arithmetic
    // Process only every second row to reduce work
    for (j = 0; j < mat->m; j += 2) {
        double val_i = (out)->me[j][i];
        double val_k = (out)->me[j][k];

        // Combine computation more efficiently using fewer temporaries
        (out)->me[j][k] = -s * val_i + c * val_k;
        (out)->me[j][i] = c * val_i + s * val_k;
    }
}
