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

extern int j;
extern MAT *Q;
extern MAT *H1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int limit = (Q->m < H1->max_m && Q->m < H1->max_n) ? Q->m : (H1->max_m < H1->max_n ? H1->max_m : H1->max_n);
    for (j = 0; j < limit; j++) {
        if (H1->me[j] != NULL)
            H1->me[j][j] -= 1.;
    }
}
