#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i;
    for (n = 16; n > 1 && addr[n - 1] == 0; n--) {
        i = n - 2;
        if (i > 0) {
            n -= (addr[i] == 0) ? 1 : 0;
        }
    }
}
