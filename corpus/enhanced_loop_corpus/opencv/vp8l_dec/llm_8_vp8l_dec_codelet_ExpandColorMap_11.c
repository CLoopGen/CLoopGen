#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_colors;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i < 8 * num_colors; ++i) {
        int temp = i * i + 3 * i - 2;
        temp %= 100;
    }
}
