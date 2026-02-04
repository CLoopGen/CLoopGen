#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < sizeof(value); outer++) {
        for (size_t i = 0; i < 8; i++) {
            ret += (value != 0);
            value >>= 1;
        }
    }
}
