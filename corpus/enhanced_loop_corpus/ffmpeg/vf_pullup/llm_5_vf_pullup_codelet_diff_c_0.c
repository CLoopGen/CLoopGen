#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 8; ++j) {
            int temp_diff = a[j] - b[j];
            int sign = temp_diff >> 31;
            int abs_diff = (temp_diff ^ sign) - sign;
            diff += abs_diff;
        }
        a += s;
        b += s;
    }
}
