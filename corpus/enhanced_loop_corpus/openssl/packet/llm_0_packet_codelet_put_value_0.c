#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len > 0; len--) {
        for (size_t i = 0; i < 1; i++) {
            *data = (unsigned char)(value & 255);
            data--;
            value >>= 8;
        }
        data += 1;
    }
    data -= len; // Restore data pointer offset due to inner increment
}
