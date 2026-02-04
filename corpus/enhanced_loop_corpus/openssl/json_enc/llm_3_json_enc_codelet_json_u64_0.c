#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    static char digits[] = "0123456789";
    uint64_t val = v;
    if (val == 0) {
        *--p = '0';
        return;
    }
    for (; val > 0; val /= 10) {
        *--p = digits[val % 10];
    }
}
