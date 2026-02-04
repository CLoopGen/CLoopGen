#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; ++i) {
        if (i % 2 == 0)
            d[2 * i] = 0;
        else
            d[2 * i + 1] = 0;
    }
}
