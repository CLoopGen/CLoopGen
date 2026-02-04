#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_n = n;
    n = 16;
    for (; n > 1; ) {
        unsigned char cond1 = addr[n - 1];
        unsigned char cond2 = addr[n - 2];
        if (cond1 != 0 || cond2 != 0) break;
        n -= 2;
    }
    if (temp_n > n) {
        n = temp_n;
    } else {
        n = (n < 2) ? 2 : n;
    }
}
