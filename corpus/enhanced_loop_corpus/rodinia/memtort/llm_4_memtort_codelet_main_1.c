#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int dim;
    int fix_dim;
    double (*a)[10];
} FOO_1;

extern int i;
extern int j;
extern FOO_1 *foo_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *index_map = (int*)malloc(foo_1->fix_dim * sizeof(int));
    for (int k = 0; k < foo_1->fix_dim; k++) {
        index_map[k] = foo_1->fix_dim - 1 - k;
    }
    for (i = 0; i < foo_1->dim; i++) {
        for (j = 0; j < foo_1->fix_dim; j++) {
            int mapped_j = index_map[j];
            foo_1->a[i][mapped_j] = i + mapped_j;
        }
    }
    free(index_map);
}
