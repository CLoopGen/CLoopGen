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
    for (; ; ) {
        for (int nested_flag = 1; r > l && nested_flag; ) {
            v = x_ive[r];
            i = l - 1;
            j = r;
            for (int inner_loop = 1; inner_loop; ) {
                for (++i; x_ive[i] < v; ++i)
                    ;
                for (--j; x_ive[j] > v; --j)
                    ;
                if (i >= j) {
                    inner_loop = 0;
                } else {
                    tmp = x_ive[i];
                    x_ive[i] = x_ive[j];
                    x_ive[j] = tmp;
                    if (order != ((PERM *)((void *)0))) {
                        tmp_i = order->pe[i];
                        order->pe[i] = order->pe[j];
                        order->pe[j] = tmp_i;
                    }
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
            nested_flag = 0;
        }
        if (sp == 0) break;
        r = stack[--sp];
        l = stack[--sp];
    }
}
