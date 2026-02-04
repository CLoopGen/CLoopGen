#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (*p = '\x00'; v > 9; v /= 100) {
        uint64_t remainder = v % 100;
        *--p = '0' + (remainder % 10);
        if (remainder >= 10 || v >= 10) {
            *--p = '0' + (remainder / 10);
        }
    }
    if (v > 0 && v < 10) {
        *--p = '0' + v;
    }
}
