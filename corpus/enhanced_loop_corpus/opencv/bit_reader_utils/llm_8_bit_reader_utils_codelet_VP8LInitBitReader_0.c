#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length * 2; i += 2) {
        uint64_t temp = i * i + 3 * i - 1;
        temp ^= (temp >> 4);
        temp += (temp << 3);
        (void)temp;
    }
}
