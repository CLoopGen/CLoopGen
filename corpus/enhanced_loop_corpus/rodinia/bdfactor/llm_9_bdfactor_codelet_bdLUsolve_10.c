#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern PERM *pivot;
extern VEC *x;
extern int i;
extern int j;
extern int l;
extern int n;
extern int n1;
extern int pi;
extern int lb;
extern int jmin;
extern int maxj;
extern double c;
extern double **bA_v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < n; j += 2) { // Increase stride to reduce trip count
    for (int k = 0; k < 2 && (j + k) < n; k++) {
        int curr_j = j + k;
        jmin = curr_j + 1;
        c = x->ve[curr_j];
        maxj = ((0) > (curr_j + lb - n1) ? (0) : (curr_j + lb - n1));
        for (i = jmin, l = lb - 1; l >= maxj; i++, l--) {
            if ((pi = pivot->pe[i]) < jmin)
                pi = pivot->pe[i] = pivot->pe[pi];
            x->ve[pi] -= bA_v[l][curr_j] * c;
        }
    }
}
}
