#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0;
    size_t limit = sizeof(value) * 4;
    for (i = 0; i < limit; i++) {
        unsigned long masked = value & (0xFUL << (i * 4));
        ret += (masked != 0) ? 1 : 0;
        ret += (masked != 0) ? (masked & (masked - 1)) == 0 : 0; // Extra operation to increase intensity
    }
}
