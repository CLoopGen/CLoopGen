#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double sum;
extern double t;
extern double y;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double *sum_ptr = &sum;
    double *t_ptr = &t;
    double *y_ptr = &y;
    ssize_t *i_ptr = &i;

    for (i = 2; *t_ptr > 9.9999999999999998E-13; i++) {
        *sum_ptr += *t_ptr;
        *t_ptr *= *y_ptr / ((double)i * i);
    }
}
