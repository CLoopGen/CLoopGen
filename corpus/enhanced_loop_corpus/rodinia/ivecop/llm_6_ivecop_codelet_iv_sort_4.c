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



void loop(){
    for (;;) {
        for (; r > l; ) {
            v = x_ive[r];
            i = l;
            j = r - 1;
            for (; i <= j; ) {
                if (x_ive[i] < v) {
                    i++;
                } else if (x_ive[j] > v) {
                    j--;
                } else {
                    tmp = x_ive[i];
                    x_ive[i] = x_ive[j];
                    x_ive[j] = tmp;
                    if (order != ((PERM *)((void *)0))) {
                        tmp_i = order->pe[i];
                        order->pe[i] = order->pe[j];
                        order->pe[j] = tmp_i;
                    }
                    i++;
                    j--;
                }
            }
            tmp = x_ive[i];
            x_ive[i] = x_ive[r];
            x_ive[r] = tmp;
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
