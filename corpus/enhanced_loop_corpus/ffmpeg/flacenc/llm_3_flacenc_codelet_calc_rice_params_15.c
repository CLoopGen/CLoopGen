#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t udata[65535];
extern  int32_t *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = n - 1; i >= 0; i--)
        udata[i] = (2 * data[i]) ^ (data[i] >> 31);
}
