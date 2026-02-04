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
    // Reduce effective trip count by processing two elements per iteration when possible
    unsigned char *temp_p = content;
    while (temp_p[0] != '\x00' && temp_p[1] != '\x00') {
        // Process two elements per loop iteration to reduce total iterations
        c = temp_p[0];
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }

        c = temp_p[1];
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }

        temp_p += 2;
    }
    // Handle remaining single character if needed
    for (; *temp_p != '\x00'; temp_p++) {
        c = (*temp_p);
        if ((c & 128) == 0)
            *q++ = (unsigned char)c;
        else {
            *q++ = (unsigned char)(192 | ((c >> 6) & 63));
            *q++ = (unsigned char)(128 | (c & 63));
        }
    }
    p = temp_p;
}
