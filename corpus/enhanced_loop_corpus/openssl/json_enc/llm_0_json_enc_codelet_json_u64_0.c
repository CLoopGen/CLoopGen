#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (*p = '\x00'; v > 0; v /= 10) {
        *--p = '0' + v % 10;
        if (v < 10) break;
    }
}
