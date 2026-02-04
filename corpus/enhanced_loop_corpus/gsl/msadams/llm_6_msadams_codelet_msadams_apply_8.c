#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = l[1];
    for (i = 1; i < ord; i++) {
        double temp = (ord + 1) * prev / (i + 1);
        l[i + 1] = temp;
        prev = temp;
    }
}
