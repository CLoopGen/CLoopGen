#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int dim;
    int fix_dim;
    double (*a)[2];
} FOO_2;

extern int i;
extern int j;
extern FOO_2 *foo_2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *access_order_i = (int*)malloc(foo_2->dim * foo_2->fix_dim * sizeof(int));
    int *access_order_j = (int*)malloc(foo_2->dim * foo_2->fix_dim * sizeof(int));
    int idx = 0;
    for (i = 0; i < foo_2->dim; i++) {
        for (j = 0; j < foo_2->fix_dim; j++) {
            access_order_i[idx] = i;
            access_order_j[idx] = j;
            idx++;
        }
    }
    for (idx = 0; idx < foo_2->dim * foo_2->fix_dim; idx++) {
        int ii = access_order_i[idx];
        int jj = access_order_j[idx];
        foo_2->a[ii][jj] = ii + jj;
    }
    free(access_order_i);
    free(access_order_j);
}
