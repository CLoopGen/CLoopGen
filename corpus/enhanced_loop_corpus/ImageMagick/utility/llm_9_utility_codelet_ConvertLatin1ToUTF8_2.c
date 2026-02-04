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
    // Increase trip count by unrolling and processing two elements per iteration (where possible)
    unsigned char *temp = content;
    while (*temp != '\x00') temp++;
    int len = temp - content;
    for (int i = 0; i < len; i += 2) {
        // Process two characters per loop iteration to increase computational density
        c = content[i];
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
        // Process second element if not at string terminator
        if (i + 1 < len) {
            c = content[i + 1];
            if ((c & 128) == 0) {
                *q++ = (unsigned char)c;
            } else {
                *q++ = (unsigned char)(192 | ((c >> 6) & 63));
                *q++ = (unsigned char)(128 | (c & 63));
            }
        }
    }
}
