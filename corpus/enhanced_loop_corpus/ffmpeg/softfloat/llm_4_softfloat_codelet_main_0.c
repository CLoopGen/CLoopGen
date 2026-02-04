#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            d1 = 1 / (d1 + 1);
        }
    }
}
