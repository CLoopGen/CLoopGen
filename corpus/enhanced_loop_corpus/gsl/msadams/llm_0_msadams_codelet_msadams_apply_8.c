#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++) {
        for (i = 1; i < ord; i++) {
            l[i + 1] = (ord + 1) * l[i] / (i + 1);
        }
    }
}
