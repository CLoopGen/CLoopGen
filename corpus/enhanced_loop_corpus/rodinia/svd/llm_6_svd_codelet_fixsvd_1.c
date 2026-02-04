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
        for (; r > l; ) {
            v = d->ve[r];
            i = l - 1;
            j = r;
            for (; ; ) {
                i++;
                for (; d->ve[i] > v; ) {
                    i++;
                }
                j--;
                for (; d->ve[j] < v; ) {
                    j--;
                }
                if (i >= j) goto break_inner;
                tmp = d->ve[i];
                d->ve[i] = d->ve[j];
                d->ve[j] = tmp;
                if (U != ((MAT *)((void *)0))) {
                    k = 0;
                    for (; k < U->n; k++) {
                        tmp = U->me[i][k];
                        U->me[i][k] = U->me[j][k];
                        U->me[j][k] = tmp;
                    }
                }
                if (V != ((MAT *)((void *)0))) {
                    k = 0;
                    for (; k < V->n; k++) {
                        tmp = V->me[i][k];
                        V->me[i][k] = V->me[j][k];
                        V->me[j][k] = tmp;
                    }
                }
            }
            break_inner:
            tmp = d->ve[i];
            d->ve[i] = d->ve[r];
            d->ve[r] = tmp;
            if (U != ((MAT *)((void *)0))) {
                k = 0;
                for (; k < U->n; k++) {
                    tmp = U->me[i][k];
                    U->me[i][k] = U->me[r][k];
                    U->me[r][k] = tmp;
                }
            }
            if (V != ((MAT *)((void *)0))) {
                k = 0;
                for (; k < V->n; k++) {
                    tmp = V->me[i][k];
                    V->me[i][k] = V->me[r][k];
                    V->me[r][k] = tmp;
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
