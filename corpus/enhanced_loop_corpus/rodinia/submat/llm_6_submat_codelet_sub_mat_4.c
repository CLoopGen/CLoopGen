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

extern MAT *old;
extern MAT *new;
extern u_int row1;
extern u_int col1;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int limit = new->m;
    double **old_me = old->me;
    double **new_me = new->me;
    u_int r1 = row1;
    u_int c1 = col1;
    for (i = 0; i < limit; i++) {
        double *temp_ptr = old_me[i + r1] + c1;
        new_me[i] = temp_ptr;
    }
}
