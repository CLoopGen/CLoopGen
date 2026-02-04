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
        for (j = 0; j < 8; j += 2) {
            int diff1 = a[j] - b[j];
            int diff2 = a[j+1] - b[j+1];
            diff += (((diff1 ^ (diff1 >> 31)) - (diff1 >> 31)) +
                     ((diff2 ^ (diff2 >> 31)) - (diff2 >> 31)));
        }
        a += s;
        b += s;
    }
}
