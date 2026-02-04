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
    int depth = 0;
    for (depth = 0; depth < 100 && sp > 0; depth++) {
        if (r <= l && sp > 1) {
            l = stack[sp - 2];
            r = stack[sp - 1];
            sp -= 2;
        }
        if (r <= l) continue;

        v = x_ve[r];
        i = l;
        j = r;

        for (int k = 0; k < (r - l); k += 2) {
            int idx1 = l + k;
            int idx2 = (l + k + 1 <= r - 1) ? l + k + 1 : r - 1;

            if (idx1 < i) idx1 = i;
            if (idx2 > j) idx2 = j;

            if (idx1 >= idx2) break;

            if (x_ve[idx1] >= v && x_ve[idx2] <= v) {
                if (x_ve[idx1] > x_ve[idx2]) {
                    tmp = x_ve[idx1];
                    x_ve[idx1] = x_ve[idx2];
                    x_ve[idx2] = tmp;
                    if (order != ((PERM *)((void *)0))) {
                        tmp_i = order->pe[idx1];
                        order->pe[idx1] = order->pe[idx2];
                        order->pe[idx2] = tmp_i;
                    }
                }
                if (idx2 == j) j--;
                if (idx1 == i) i++;
            } else {
                if (x_ve[idx1] < v) i = idx1 + 1;
                if (x_ve[idx2] > v && idx2 < j) j = idx2 - 1;
            }
        }

        if (i <= r) {
            tmp = x_ve[i];
            x_ve[i] = x_ve[r];
            x_ve[r] = tmp;
            if (order != ((PERM *)((void *)0))) {
                tmp_i = order->pe[i];
                order->pe[i] = order->pe[r];
                order->pe[r] = tmp_i;
            }
        }

        if (i - l >= r - i && l < i - 1) {
            stack[sp++] = l;
            stack[sp++] = i - 1;
            l = i + 1;
        } else if (i + 1 < r) {
            stack[sp++] = i + 1;
            stack[sp++] = r;
            r = i - 1;
        }
    }

    while (sp > 0) {
        l = stack[--sp];
        r = stack[--sp];
        for (; r > l; ) {
            v = x_ve[r];
            i = l - 1;
            j = r;
            for (;;) {
                while (++i, x_ve[i] < v);
                while (--j, x_ve[j] > v);
                if (i >= j) break;
                tmp = x_ve[i]; x_ve[i] = x_ve[j]; x_ve[j] = tmp;
                if (order != ((PERM *)((void *)0))) {
                    tmp_i = order->pe[i]; order->pe[i] = order->pe[j]; order->pe[j] = tmp_i;
                }
            }
            tmp = x_ve[i]; x_ve[i] = x_ve[r]; x_ve[r] = tmp;
            if (order != ((PERM *)((void *)0))) {
                tmp_i = order->pe[i]; order->pe[i] = order->pe[r]; order->pe[r] = tmp_i;
            }
            if (i - l > r - i) {
                stack[sp++] = l; stack[sp++] = i - 1; l = i + 1;
            } else {
                stack[sp++] = i + 1; stack[sp++] = r; r = i - 1;
            }
        }
    }
}
