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
extern int *x_ive;
extern int tmp;
extern int v;
extern int i;
extern int j;
extern int l;
extern int r;
extern int tmp_i;
extern int stack[60];
extern int sp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (;;) {
        for (; r > l; ) {
            v = x_ive[r];
            i = l;
            j = r - 1;

            // Strided access pattern: process elements with a fixed stride of 2
            // First pass: handle even indices in increasing order
            for (int idx = l; idx <= r; idx += 2) {
                if (idx < l || idx > r) continue;
                if (x_ive[idx] < v && idx < r) {
                    i = idx + 1;
                    break;
                }
            }

            // Second pass: handle odd indices in decreasing order
            for (int idx = r - 1; idx >= l; idx -= 2) {
                if (idx < l || idx > r) continue;
                if (x_ive[idx] > v && idx > l) {
                    j = idx - 1;
                    break;
                }
            }

            // Fallback to direct comparison if strided logic doesn't resolve
            if (i >= j) {
                i = l - 1;
                j = r;
                for (int iter = 0; iter < (r - l); iter++) {
                    while (++i, x_ive[i] < v);
                    while (--j, x_ive[j] > v);
                    if (i >= j) break;
                    tmp = x_ive[i];
                    x_ive[i] = x_ive[j];
                    x_ive[j] = tmp;
                    if (order != ((PERM *)0)) {
                        tmp_i = order->pe[i];
                        order->pe[i] = order->pe[j];
                        order->pe[j] = tmp_i;
                    }
                }
            }

            tmp = x_ive[i];
            x_ive[i] = x_ive[r];
            x_ive[r] = tmp;
            if (order != ((PERM *)0)) {
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
