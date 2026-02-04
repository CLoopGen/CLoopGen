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

extern VEC *d;
extern MAT *U;
extern MAT *V;
extern int i;
extern int j;
extern int k;
extern int l;
extern int r;
extern int stack[100];
extern int sp;
extern double tmp;
extern double v;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (;;) {
        for (; r > l;) {
            v = d->ve[r];
            i = l;
            j = r - 1;

            // Strided access pattern: process elements with a fixed stride of 2
            // First pass: handle even indices in increasing order
            for (int idx = l; idx <= r; idx += 2) {
                if (idx <= r && d->ve[idx] > v) {
                    i = idx;
                    break;
                }
            }
            for (int idx = r - 1; idx >= l; idx -= 2) {
                if (idx >= l && d->ve[idx] < v) {
                    j = idx;
                    break;
                }
            }

            // Proceed with corrected pivot logic using strided-found indices
            if (i >= j) {
                i = r;
            } else {
                // Swap using primary index determined by strided scan
                tmp = d->ve[i];
                d->ve[i] = d->ve[j];
                d->ve[j] = tmp;
                if (U != ((MAT *)((void *)0))) {
                    for (k = 0; k < U->n; k++) {
                        tmp = U->me[i][k];
                        U->me[i][k] = U->me[j][k];
                        U->me[j][k] = tmp;
                    }
                }
                if (V != ((MAT *)((void *)0))) {
                    for (k = 0; k < V->n; k++) {
                        tmp = V->me[i][k];
                        V->me[i][k] = V->me[j][k];
                        V->me[j][k] = tmp;
                    }
                }
                j = i; // To exit inner loop simulation
            }

            // Final pivot swap
            tmp = d->ve[j];
            d->ve[j] = d->ve[r];
            d->ve[r] = tmp;
            if (U != ((MAT *)((void *)0))) {
                for (k = 0; k < U->n; k++) {
                    tmp = U->me[j][k];
                    U->me[j][k] = U->me[r][k];
                    U->me[r][k] = tmp;
                }
            }
            if (V != ((MAT *)((void *)0))) {
                for (k = 0; k < V->n; k++) {
                    tmp = V->me[j][k];
                    V->me[j][k] = V->me[r][k];
                    V->me[r][k] = tmp;
                }
            }

            // Update bounds based on partition
            if (j - l > r - j) {
                stack[++sp] = l;
                stack[++sp] = j - 1;
                l = j + 1;
            } else {
                stack[++sp] = j + 1;
                stack[++sp] = r;
                r = j - 1;
            }
        }
        if (sp < 0) break;
        r = stack[sp--];
        l = stack[sp--];
    }
}
