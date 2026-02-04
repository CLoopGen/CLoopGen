#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total_bits = sizeof(value) * 8;
    for (i = 0; i < total_bits; i += 2) {
        ret += ((value >> i) != 0);
    }
    for (i = 1; i < total_bits; i += 2) {
        ret += ((value >> i) != 0);
    }
}
