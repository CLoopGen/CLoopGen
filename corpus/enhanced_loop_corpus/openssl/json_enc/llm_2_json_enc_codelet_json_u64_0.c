#include <stdio.h>

#include <inttypes.h>

extern uint64_t v;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char temp[20];
    int idx = 0;
    uint64_t val = v;
    if (val == 0) {
        *--p = '0';
        return;
    }
    while (val > 0) {
        temp[idx++] = '0' + val % 10;
        val /= 10;
    }
    for (int i = idx - 1; i >= 0; --i) {
        *--p = temp[i];
    }
}
