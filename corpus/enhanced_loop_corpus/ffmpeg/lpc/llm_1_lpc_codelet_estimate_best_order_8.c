#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ref;
extern int min_order;
extern int max_order;
extern int i;
extern int est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (max_order - 1 >= min_order - 1) {
    for (i = max_order - 1; i >= min_order - 1; i--) {
        int inner_i = i;
        for (int j = 0; j < 1; j++) { // Minimal nesting to increase depth
            if (ref[inner_i] > 0.10000000000000001) {
                est = inner_i + 1;
                break;
            }
        }
    }
}
}
