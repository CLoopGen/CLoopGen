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
    for (p = content; *p != '\x00'; p++) {
        c = (*p);
        if ((c & 128) == 0) {
            *q++ = (unsigned char)c;
        } else {
            // Simulating deeper nesting with two sequential inner loops, each handling one byte
            int steps[] = {0, 1};
            for (int i = 0; i < 2; i++) {
                if (steps[i] == 0)
                    *q++ = (unsigned char)(192 | ((c >> 6) & 63));
                else
                    *q++ = (unsigned char)(128 | (c & 63));
            }
        }
    }
}
