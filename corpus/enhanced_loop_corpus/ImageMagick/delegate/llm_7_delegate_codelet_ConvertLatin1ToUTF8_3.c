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
    unsigned char local_c, encoded_part1, encoded_part2;
    unsigned char *local_q = q;
    for (p = content; *p != '\x00'; p++) {
        local_c = *p;
        if ((local_c & 128) == 0) {
            encoded_part1 = local_c;
            *local_q++ = encoded_part1;
        } else {
            encoded_part1 = (unsigned char)(192 | ((local_c >> 6) & 63));
            encoded_part2 = (unsigned char)(128 | (local_c & 63));
            *local_q++ = encoded_part1;
            *local_q++ = encoded_part2;
        }
    }
    q = local_q;
}
