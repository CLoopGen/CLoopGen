#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char indices5[16];
extern unsigned char indices7[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    unsigned char index;
    index = indices7[i];
    if (index == 0)
        indices5[i] = 1;
    else if (index == 1)
        indices5[i] = 0;
    else
        indices5[i] = 9 - index;

    // Unroll second iteration manually to maintain 16 total operations
    index = indices7[i + 8];
    if (index == 0)
        indices5[i + 8] = 1;
    else if (index == 1)
        indices5[i + 8] = 0;
    else
        indices5[i + 8] = 9 - index;
}
}
