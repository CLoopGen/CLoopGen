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
    unsigned char *src = content;
    for (int i = 0; src[i] != '\x00'; i++) {
        local_c = src[i];
        c = (int)local_c;
        if ((c & 128) == 0) {
            q[0] = local_c;
            q++;
        } else {
            high_byte = (unsigned char)(192 | ((local_c >> 6) & 63));
            low_byte = (unsigned char)(128 | (local_c & 63));
            q[0] = high_byte;
            q[1] = low_byte;
            q += 2;
        }
    }
}
