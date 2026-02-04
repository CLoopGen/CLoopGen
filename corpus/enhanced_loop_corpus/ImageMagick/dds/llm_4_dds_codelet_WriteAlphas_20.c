#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char indices5[16];
extern unsigned char indices7[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    unsigned char index = indices7[i];
    indices5[i] = (index == 0) ? 1 : ((index == 1) ? 0 : 9 - index);
}
}
