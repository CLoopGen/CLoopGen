#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        if (d1 > 0.5) {
            d1 = 1 / (d1 + 1);
        } else {
            d1 = 1 / (d1 + 2);
        }
    }
}
