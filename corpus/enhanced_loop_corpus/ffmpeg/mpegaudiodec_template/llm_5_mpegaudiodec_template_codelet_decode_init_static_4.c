#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 7; i < 16; ++i) {
    is_table[0][i] = 0.;
    if (i > 10)
        is_table[1][i] = 0.;
}
}
