#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 - 2; i++) {
        v[i] = (i % 2 == 0)
            ? ((top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2)
            : ((top[i] + top[i + 2] * 3 + 1) >> 2);
    }
}
