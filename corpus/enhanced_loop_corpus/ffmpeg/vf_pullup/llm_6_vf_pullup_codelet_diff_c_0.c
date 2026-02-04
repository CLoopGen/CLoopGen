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
    int temp_diff = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            int diff_val = a[j] - b[j];
            int sign = diff_val >> 31;
            temp_diff += ((diff_val ^ sign) - sign);
        }
        a += s;
        b += s;
    }
    diff += temp_diff;
}
