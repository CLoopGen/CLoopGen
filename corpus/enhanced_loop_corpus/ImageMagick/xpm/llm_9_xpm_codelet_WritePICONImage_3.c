#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t characters_per_pixel;
extern size_t colors;
extern ssize_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (ssize_t)colors > 1000 ? 1000 : (ssize_t)colors;
    for (k = 8; k < limit; k = k * 8 + 4)
        if (k % 2 == 0)
            characters_per_pixel += 2;
        else
            characters_per_pixel++;
}
