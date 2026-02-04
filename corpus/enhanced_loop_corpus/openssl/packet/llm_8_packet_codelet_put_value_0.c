#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (data += len - 1; len > 0; len -= 2) {
        *data = (unsigned char)(value & 255);
        data--;
        value >>= 8;
        if (len > 1) {
            *data = (unsigned char)(value & 255);
            data--;
            value >>= 8;
        }
    }
}
