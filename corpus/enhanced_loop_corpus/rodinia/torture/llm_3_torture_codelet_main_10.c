#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern VEC *w;
extern MAT *C;
extern double s1;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use row pointer caching to create consecutive memory access
    // Improves locality by holding a pointer to the current row of C and w->ve[i] in a local variable
    int i, j;
    double wi;
    double *c_row;
    for (i = 0; i < C->m; i++) {
        wi = s1 * (w)->ve[i];          // Cache scalar multiple
        c_row = (C)->me[i];           // Cache current row pointer for consecutive access
        for (j = 0; j < C->n; j++) {
            c_row[j] += wi * (w)->ve[j];  // Consecutive write to c_row with reused wi
        }
    }
}
