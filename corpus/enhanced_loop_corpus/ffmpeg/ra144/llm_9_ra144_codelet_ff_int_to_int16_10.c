#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int *inp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        int val1 = *inp++;
        int val2 = *inp++;
        *out++ = (int16_t)(val1 + val2);
        *out++ = (int16_t)(val1 - val2);
    }
}
