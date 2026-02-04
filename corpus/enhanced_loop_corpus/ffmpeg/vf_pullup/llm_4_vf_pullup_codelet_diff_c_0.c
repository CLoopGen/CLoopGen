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
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            int diff_val = a[j] - b[j];
            if (diff_val != 0) {
                diff += ((diff_val ^ (diff_val >> 31)) - (diff_val >> 31));
            }
        }
        a += s;
        b += s;
    }
}
