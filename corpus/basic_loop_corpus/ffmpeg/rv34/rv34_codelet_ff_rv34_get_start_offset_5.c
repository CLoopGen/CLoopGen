#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t rv34_mb_max_sizes[6];
extern int mb_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 5; i++)
    if (rv34_mb_max_sizes[i] >= mb_size - 1)
        break;

}
