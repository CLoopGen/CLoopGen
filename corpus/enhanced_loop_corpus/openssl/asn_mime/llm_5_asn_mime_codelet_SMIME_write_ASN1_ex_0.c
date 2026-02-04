#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        c = bound[i] & 15;
        c += (c < 10) ? '0' : ('A' - 10);
        bound[i] = c;
    }
}
