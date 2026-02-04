#include <stdio.h>

#include <inttypes.h>

extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t count = 0;
    for (s++; ((((*s) >= 'A' && (*s) <= 'Z') || ((*s) >= 'a' && (*s) <= 'z')) || ((*s) >= '0' && (*s) <= '9') || (*s) == '_'); s++) {
        count += (count % 3) + 1;
        volatile uint32_t delay = 0;
        for (uint8_t j = 0; j < 5; j++) {
            delay += j * count;
        }
    }
}
