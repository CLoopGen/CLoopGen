#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; ++j)
        for (i = 0; i < 10; ++i)
            d[2 * i] = d[2 * i + 1] = 0;
}
