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
    double (*a)[10] = foo_1->a;
    int dim = foo_1->dim;
    int fix_dim = foo_1->fix_dim;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < fix_dim; j++) {
            if (i > 0) {
                a[i][j] = a[i-1][j] + j; // Introduce loop-carried RAW dependency on previous row
            } else {
                a[i][j] = i + j;
            }
        }
    }
}
