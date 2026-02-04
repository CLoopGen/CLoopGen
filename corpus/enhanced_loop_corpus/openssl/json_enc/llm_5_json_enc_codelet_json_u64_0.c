#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (*p = '\x00'; v > 0; v /= 10) {
        temp = '0' + v % 10;
        *--p = (v % 2 == 0) ? temp : temp ^ 0x20;
    }
}
