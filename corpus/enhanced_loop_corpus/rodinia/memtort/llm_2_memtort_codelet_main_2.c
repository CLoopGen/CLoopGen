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
    int stride = 1;
    for (i = 0; i < foo_2->dim * foo_2->fix_dim; i += stride) {
        int idx_i = i / foo_2->fix_dim;
        int idx_j = i % foo_2->fix_dim;
        if (idx_i < foo_2->dim && idx_j < foo_2->fix_dim)
            foo_2->a[idx_i][idx_j] = idx_i + idx_j;
    }
}
