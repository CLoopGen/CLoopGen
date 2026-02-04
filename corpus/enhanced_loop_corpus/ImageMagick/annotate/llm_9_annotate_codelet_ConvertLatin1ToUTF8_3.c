#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern int c;
extern  unsigned char *restrict p;
extern unsigned char *restrict q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift_mask_low = 63;
    int prefix_byte1 = 192;
    int prefix_byte2 = 128;
    int loop_count = 0;
    for (p = content; *p != '\x00' && loop_count < 1024; p++) {
        c = (*p);
        unsigned char uc = (unsigned char)c;
        unsigned char high_part = (uc >> 6) & shift_mask_low;
        unsigned char low_part = uc & shift_mask_low;
        if ((c & 128) == 0) {
            *q++ = uc;
        } else {
            *q++ = (unsigned char)(prefix_byte1 | high_part);
            *q++ = (unsigned char)(prefix_byte2 | low_part);
        }
        loop_count++;
    }
}
