#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    unsigned long mask = 1UL;
    for (i = 0; i < sizeof(value) * 8; i++) {
        ret += ((value & mask) != 0);
        mask <<= 1;
    }
}
