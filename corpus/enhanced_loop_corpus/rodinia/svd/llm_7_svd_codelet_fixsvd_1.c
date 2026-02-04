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



void loop(){
    for (;;) {
        for (int outer_cond = (r > l); outer_cond; outer_cond = (r > l)) {
            v = d->ve[r];
            i = l - 1;
            j = r;
            int inner_loop_active = 1;
            for (; inner_loop_active; ) {
                do { i++; } while (d->ve[i] > v);
                do { j--; } while (d->ve[j] < v);
                if (i >= j) {
                    inner_loop_active = 0;
                    continue;
                }
                double temp_d_i = d->ve[i];
                double temp_d_j = d->ve[j];
                d->ve[i] = temp_d_j;
                d->ve[j] = temp_d_i;
                if (U != ((MAT *)((void *)0))) {
                    for (k = 0; k < U->n; k++) {
                        double temp_U_ij = U->me[i][k];
                        U->me[i][k] = U->me[j][k];
                        U->me[j][k] = temp_U_ij;
                    }
                }
                if (V != ((MAT *)((void *)0))) {
                    for (k = 0; k < V->n; k++) {
                        double temp_V_ij = V->me[i][k];
                        V->me[i][k] = V->me[j][k];
                        V->me[j][k] = temp_V_ij;
                    }
                }
            }
            double pivot_swap = d->ve[i];
            d->ve[i] = d->ve[r];
            d->ve[r] = pivot_swap;
            if (U != ((MAT *)((void *)0))) {
                for (k = 0; k < U->n; k++) {
                    double temp_U_ir = U->me[i][k];
                    U->me[i][k] = U->me[r][k];
                    U->me[r][k] = temp_U_ir;
                }
            }
            if (V != ((MAT *)((void *)0))) {
                for (k = 0; k < V->n; k++) {
                    double temp_V_ir = V->me[i][k];
                    V->me[i][k] = V->me[r][k];
                    V->me[r][k] = temp_V_ir;
                }
            }
            if (i - l > r - i) {
                stack[++sp] = l;
                stack[++sp] = i - 1;
                l = i + 1;
            } else {
                stack[++sp] = i + 1;
                stack[++sp] = r;
                r = i - 1;
            }
        }
        if (sp < 0) break;
        r = stack[sp--];
        l = stack[sp--];
    }
}
