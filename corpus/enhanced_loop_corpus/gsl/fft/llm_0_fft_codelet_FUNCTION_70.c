#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < q; i++) {
        for (k1 = 0; k1 < q; k1++) {
        }
    }
}
