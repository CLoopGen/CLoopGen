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
    unsigned char local_c, high_byte, low_byte;
    unsigned char *next_q = q;
    for (p = content; *p != '\x00'; p++) {
        local_c = *p;
        if ((local_c & 128) == 0) {
            *next_q++ = local_c;
        } else {
            high_byte = (unsigned char)(192 | ((local_c >> 6) & 63));
            low_byte = (unsigned char)(128 | (local_c & 63));
            *next_q++ = high_byte;
            *next_q++ = low_byte;
        }
    }
    q = next_q;
}
