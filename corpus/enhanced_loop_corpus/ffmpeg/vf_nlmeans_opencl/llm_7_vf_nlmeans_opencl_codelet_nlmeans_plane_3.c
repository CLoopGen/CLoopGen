#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nb_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sum = 0;
    for (i = 0; i < nb_pixel / 4; i++) {
        local_sum = i % 3 == 0 ? local_sum + i : local_sum;
    }
    // Introduce a final write that breaks potential WAW with other uses of i
    i = nb_pixel / 4;
}
