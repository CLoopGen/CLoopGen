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
    for (i = start_i; i < last; i += 2) {
        int j1 = scantable[i];
        int j2 = (i + 1 < last) ? scantable[i + 1] : j1;
        level = temp[j1];
        int level2 = temp[j2];
        if (level) {
            level += 64;
            if ((level & ~127) == 0)
                bits += length[run * 128 + level];
            else
                bits += esc_length;
            run = 0;
        } else {
            run++;
        }
        if (level2 && (i + 1 < last)) {
            level2 += 64;
            if ((level2 & ~127) == 0)
                bits += length[run * 128 + level2];
            else
                bits += esc_length;
            run = 0;
        }
    }
}
