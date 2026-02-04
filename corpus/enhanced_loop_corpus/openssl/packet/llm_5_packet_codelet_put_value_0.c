#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp_data = data + len - 1;
    uint64_t temp_value = value;
    size_t i = 0;
    for (; i < len; i++) {
        *(temp_data - i) = (unsigned char)(temp_value & 255);
        if ((temp_value >>= 8) == 0) {
            while (++i < len) {
                *(temp_data - i) = 0;
            }
        }
    }
}
