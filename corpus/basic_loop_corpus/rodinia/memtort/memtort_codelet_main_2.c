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
for (i = 0; i < foo_2->dim; i++)
    for (j = 0; j < foo_2->fix_dim; j++)
        foo_2->a[i][j] = i + j;

}
