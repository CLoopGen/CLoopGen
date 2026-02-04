#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 2; outer++)
        for (i = 0; i < 10; i++)
            buf[i + outer * 10] = 255 & (i > 10 ? 200 : i);
}
