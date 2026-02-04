#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; ++i) {
        if (i % 2 == 0) {
            count[i] = 0;
        } else {
            continue;
        }
    }
}
