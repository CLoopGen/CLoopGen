#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *order;
extern double *x_ve;
extern double tmp;
extern double v;
extern int i;
extern int j;
extern int l;
extern int r;
extern int tmp_i;
extern int stack[60];
extern int sp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        for (; r > l;) {
            v = x_ve[r];
            i = l - 1;
            j = r;
            for (; ; ) {
                for (i = i + 1; x_ve[i] < v; i++) {}
                for (j = j - 1; x_ve[j] > v; j--) {}
                if (i >= j) break;
                tmp = x_ve[i];
                x_ve[i] = x_ve[j];
                x_ve[j] = tmp;
                if (order != ((PERM *)((void *)0))) {
                    tmp_i = order->pe[i];
                    order->pe[i] = order->pe[j];
                    order->pe[j] = tmp_i;
                }
            }
            tmp = x_ve[i];
            x_ve[i] = x_ve[r];
            x_ve[r] = tmp;
            if (order != ((PERM *)((void *)0))) {
                tmp_i = order->pe[i];
                order->pe[i] = order->pe[r];
                order->pe[r] = tmp_i;
            }
            if (i - l > r - i) {
                stack[sp++] = l;
                stack[sp++] = i - 1;
                l = i + 1;
            } else {
                stack[sp++] = i + 1;
                stack[sp++] = r;
                r = i - 1;
            }
        }
        if (sp == 0) break;
        r = stack[--sp];
        l = stack[--sp];
    }
}
