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
        double temp = 0.0;
        for (j = 0; j < fix_dim; j++) {
            temp += i + j;
            a[i][j] = temp;
        }
    }
}
