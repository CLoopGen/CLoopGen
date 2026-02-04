#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t size;
extern size_t i;
extern unsigned char *q;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size / 4; i++) {
        c = q[0];
        q[0] = out[0];
        out[0] = c;
        q--;
        out++;
        c = q[0];
        q[0] = out[0];
        out[0] = c;
        q--;
        out++;
    }
}
