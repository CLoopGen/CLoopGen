#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int left;
extern int i;
extern int min_width;
extern  uint16_t *src16;
extern uint16_t *dst16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < min_width; i += 2) {
    const int temp1 = src16[i];
    dst16[i] = temp1 - left;
    left = temp1;
    if (i + 1 < min_width) {
        const int temp2 = src16[i + 1];
        dst16[i + 1] = temp2 - left;
        left = temp2;
    }
}
}
