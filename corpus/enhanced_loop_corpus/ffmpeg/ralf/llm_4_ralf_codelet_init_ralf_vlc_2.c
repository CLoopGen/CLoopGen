#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 16; i++) {
        if (i % 2 == 0) {
            counts[i] = 0;
        } else {
            counts[i] = 0;
        }
    }
}
