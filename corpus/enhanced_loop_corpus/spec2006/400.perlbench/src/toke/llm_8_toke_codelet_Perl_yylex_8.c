#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i = 0;
    char c;
    for (; i < 5; i++) {
        c = *(t + i);
        if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')) {
            t += i;
            break;
        }
        if (i == 4) t += 5;
    }
}
