#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = ord + 1;
    for (i = 1; i < ord - 1; i++) {
        double temp1 = l[i] * factor;
        double temp2 = l[i + 1] * factor;
        l[i + 1] = temp1 / (i + 1);
        l[i + 2] = temp2 / (i + 2);
    }
}
