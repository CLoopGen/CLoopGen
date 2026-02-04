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
    // Variant 2: Strided memory access with stride of 2 (process every other element)
    // This changes access pattern to non-consecutive, simulating potential cache behavior changes
    u_int n = mat->n;
    u_int aligned_n = (n / 2) * 2;  // Ensure we don't overflow on odd n
    double *row_i = &(out->me[i][0]);
    double *row_k = &(out->me[k][0]);

    // Process pairs with stride 2
    for (j = 0; j < aligned_n; j += 2) {
        // First element in stride
        temp = c * row_i[j] + s * row_k[j];
        row_k[j] = -s * row_i[j] + c * row_k[j];
        row_i[j] = temp;

        // Second element in stride
        temp = c * row_i[j+1] + s * row_k[j+1];
        row_k[j+1] = -s * row_i[j+1] + c * row_k[j+1];
        row_i[j+1] = temp;
    }

    // Handle remaining element if n is odd
    if (n % 2 == 1) {
        j = n - 1;
        temp = c * row_i[j] + s * row_k[j];
        row_k[j] = -s * row_i[j] + c * row_k[j];
        row_i[j] = temp;
    }
}
