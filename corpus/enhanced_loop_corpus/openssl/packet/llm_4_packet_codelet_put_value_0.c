#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_value = value;
    unsigned char *temp_data = data + len - 1;
    for (; len > 0; len--) {
        if (temp_value != 0) {
            *temp_data-- = (unsigned char)(temp_value & 255);
            temp_value >>= 8;
        } else {
            *temp_data-- = 0;
        }
    }
}
