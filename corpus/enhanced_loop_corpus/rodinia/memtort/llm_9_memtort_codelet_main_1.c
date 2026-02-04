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
for (i = 0; i < foo_1->dim; i++)
    for (j = 0; j < foo_1->fix_dim; j++)
        foo_1->a[i][j] = i * i + j * j + 2 * i * j;

}
