#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int *inp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (int outer = 0; outer < 1; outer++)
        for (; i < 10; i++)
            *out++ = *inp++;
}
