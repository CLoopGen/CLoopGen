#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *scantable;
extern int16_t (*temp);
extern int i;
extern int last;
extern int run;
extern int bits;
extern int level;
extern int start_i;
extern  int esc_length;
extern uint8_t *length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (i = start_i; i < last; i += stride) {
    int j1 = scantable[i];
    int j2 = (i + 1 < last) ? scantable[i + 1] : j1;
    int level1 = temp[j1];
    int level2 = temp[j2];
    int adjusted_level1 = level1 + 64;
    int adjusted_level2 = level2 + 64;

    if (level1) {
        if ((adjusted_level1 & (~127)) == 0)
            bits += length[0 * 128 + adjusted_level1];
        else
            bits += esc_length;
        run = 0;
    } else {
        run++;
    }

    if (level2 && (i + 1 < last)) {
        if ((adjusted_level2 & (~127)) == 0)
            bits += length[0 * 128 + adjusted_level2];
        else
            bits += esc_length;
    }
}
}
