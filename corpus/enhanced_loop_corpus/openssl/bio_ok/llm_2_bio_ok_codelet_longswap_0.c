#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 4) {
        size_t idx1 = i, idx2 = i + 3;
        c = p[idx1], p[idx1] = p[idx2], p[idx2] = c;
        idx1 = i + 1, idx2 = i + 2;
        c = p[idx1], p[idx1] = p[idx2], p[idx2] = c;
    }
}
