#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i += 2) {
        count[i] = 0;
        if (i + 1 < 100)
            count[i + 1] = 0;
    }
}
