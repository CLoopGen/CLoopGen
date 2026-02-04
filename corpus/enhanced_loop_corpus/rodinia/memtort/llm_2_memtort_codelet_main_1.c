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
int total = foo_1->dim * foo_1->fix_dim;
for (int idx = 0; idx < total; idx++) {
    i = idx / foo_1->fix_dim;
    j = idx % foo_1->fix_dim;
    foo_1->a[i][j] = i + j;
}
}
