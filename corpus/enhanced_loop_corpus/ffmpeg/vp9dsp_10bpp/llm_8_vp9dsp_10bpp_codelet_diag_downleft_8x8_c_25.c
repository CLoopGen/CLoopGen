#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 1; i += 2) {
    v[i] = (top[i] + top[i + 1] * 3 + 3) >> 2;
    if (i + 1 < 6) v[i + 1] = (top[i + 1] + top[i + 2] * 3 + 3) >> 2;
}
}
