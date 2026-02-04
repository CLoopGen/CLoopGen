#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ord > 1) {
        for (i = 1; i < ord; i++) {
            for (size_t inner = 0; inner < 1; inner++) {
                l[i + 1] = (ord + 1) * l[i] / (i + 1);
            }
        }
    }
}
