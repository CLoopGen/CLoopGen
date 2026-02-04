#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (q > 0) {
        k1 = 0;
        for (; k1 < q;) {
            k1++;
        }
    }
}
