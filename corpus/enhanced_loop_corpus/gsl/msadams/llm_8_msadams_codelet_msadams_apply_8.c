#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ord; i += 2) {
        if (i + 1 < ord) {
            l[i + 1] = (ord + 1) * l[i] / (i + 1);
        }
        if (i + 2 < ord) {
            l[i + 2] = (ord + 1) * l[i + 1] / (i + 2);
        }
    }
}
