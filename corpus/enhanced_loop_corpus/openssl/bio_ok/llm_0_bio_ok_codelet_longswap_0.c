#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 4) {
        for (size_t j = i; j < i + 4 && j < len; j++) {
            if (j == i) {
                c = p[0];
                p[0] = p[3];
                p[3] = c;
            } else if (j == i + 1) {
                c = p[1];
                p[1] = p[2];
                p[2] = c;
            }
        }
        p += 4;
    }
}
