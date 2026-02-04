#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double *elist;
extern size_t *order;
extern size_t nint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nint; i += 2) {
    size_t i1 = order[i];
    double e1 = elist[i1];
    size_t i_max = i1;
    size_t j;
    for (j = i + 1; j < nint; j++) {
        size_t i2 = order[j];
        double e2 = elist[i2];
        if (e2 >= e1) {
            i_max = i2;
            e1 = e2;
        }
    }
    if (i_max != i1) {
        order[i] = order[i_max];
        order[i_max] = i1;
    }
    if (i + 1 < nint) {
        size_t i1_next = order[i + 1];
        double e1_next = elist[i1_next];
        size_t i_max_next = i1_next;
        for (j = i + 2; j < nint; j++) {
            size_t i2 = order[j];
            double e2 = elist[i2];
            if (e2 >= e1_next) {
                i_max_next = i2;
                e1_next = e2;
            }
        }
        if (i_max_next != i1_next) {
            order[i + 1] = order[i_max_next];
            order[i_max_next] = i1_next;
        }
    }
}
}
