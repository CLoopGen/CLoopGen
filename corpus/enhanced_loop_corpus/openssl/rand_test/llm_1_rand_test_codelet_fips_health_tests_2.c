#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t block = 0; block < sizeof(buf); block += 16) {
        for (size_t offset = 0; offset < 16; offset++) {
            i = block + offset;
            if (i >= sizeof(buf)) break;
            buf[i] = 255 & (i >= 512 && i % 8 == 0 ? 128 : i);
        }
    }
}
