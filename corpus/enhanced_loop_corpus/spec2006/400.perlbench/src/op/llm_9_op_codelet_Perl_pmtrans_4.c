#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN rlen;
extern U8 *r;
extern I32 i;
extern I32 j;
extern I32 del;
extern I32 grows;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    if (!tbl[i]) {
        if (j >= (I32)rlen) {
            tbl[i] = del ? -2 : (rlen ? r[j - 1] : (short)i);
        } else {
            if (r[j] >= 128)
                grows = 1;
            tbl[i] = r[j++];
        }
    }
    // Mirror behavior for upper half with arithmetic transformation
    I32 mirrored_index = 255 - i;
    if (!tbl[mirrored_index]) {
        if (j >= (I32)rlen) {
            tbl[mirrored_index] = del ? -2 : (rlen ? r[(j - 1) % rlen] : (short)mirrored_index);
        } else {
            tbl[mirrored_index] = r[j] ^ 0xFF; // Invert bits for variation
            j++;
        }
    }
}
}
