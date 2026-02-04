#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 8) {
        if (i + 3 < len) {
            c = p[0]; p[0] = p[3]; p[3] = c;
            c = p[1]; p[1] = p[2]; p[2] = c;
        }
        if (i + 7 < len) {
            c = p[4]; p[4] = p[7]; p[7] = c;
            c = p[5]; p[5] = p[6]; p[6] = c;
        }
        p += 8;
    }
}
