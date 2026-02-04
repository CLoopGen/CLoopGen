#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int *inp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i += 2)
    {
        *out++ = inp[i];
        if (i + 1 < 10) *out++ = inp[i + 1];
    }
}
