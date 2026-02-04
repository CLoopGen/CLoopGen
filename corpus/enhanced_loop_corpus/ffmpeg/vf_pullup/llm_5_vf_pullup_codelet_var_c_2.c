#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int var;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; ++i) {
    j = 0;
    for (; j < 8; ++j) {
        int diff = a[j] - a[j + s];
        int sign = diff >> 31;
        int abs_diff = (diff ^ sign) - sign;
        if (abs_diff > 0) {
            var += abs_diff;
        }
    }
    a += s;
}
}
