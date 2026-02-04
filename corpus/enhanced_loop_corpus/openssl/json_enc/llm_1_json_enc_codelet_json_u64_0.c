#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (*p = '\x00'; v > 0; ) {
        for (int i = 0; i < 1 && v > 0; i++) {
            *--p = '0' + v % 10;
            v /= 10;
        }
    }
}
