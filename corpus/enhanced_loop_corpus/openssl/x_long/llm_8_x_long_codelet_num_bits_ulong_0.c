#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    for (i = 0; i < sizeof(value) * 16; i += 2) {
        ret += ((value >> i) != 0) + ((value >> (i + 1)) != 0);
    }
}
