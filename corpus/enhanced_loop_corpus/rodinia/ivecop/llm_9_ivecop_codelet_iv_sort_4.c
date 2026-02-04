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
    int depth = 0;
    for (; ; depth++) {
        if (r <= l && sp == 0) break;

        while (!(r > l)) {
            if (sp == 0) goto exit_loop;
            r = stack[--sp];
            l = stack[--sp];
        }

        v = x_ive[r];
        i = l;
        j = r;

        for (int phase = 0; phase < 3; phase++) {
            switch (phase) {
                case 0:
                    for (; ; i++) {
                        if (i >= r) break;
                        if (x_ive[i] >= v) break;
                    }
                    break;
                case 1:
                    for (; ; j--) {
                        if (j <= l) break;
                        if (x_ive[j] <= v) break;
                    }
                    break;
                case 2:
                    if (i >= j) goto end_partition;
                    tmp = x_ive[i];
                    x_ive[i] = x_ive[j];
                    x_ive[j] = tmp;
                    if (order != ((PERM *)((void *)0))) {
                        tmp_i = order->pe[i];
                        order->pe[i] = order->pe[j];
                        order->pe[j] = tmp_i;
                    }
                    i++; j--;
                    phase = -1; // restart phases
                    break;
            }
        }
end_partition:
        tmp = x_ive[i];
        x_ive[i] = x_ive[r];
        x_ive[r] = tmp;
        if (order != ((PERM *)((void *)0))) {
            tmp_i = order->pe[i];
            order->pe[i] = order->pe[r];
            order->pe[r] = tmp_i;
        }

        if (r - i > i - l) {
            stack[sp++] = l;
            stack[sp++] = i - 1;
            l = i + 1;
        } else {
            stack[sp++] = i + 1;
            stack[sp++] = r;
            r = i - 1;
        }
    }
exit_loop:;
}
