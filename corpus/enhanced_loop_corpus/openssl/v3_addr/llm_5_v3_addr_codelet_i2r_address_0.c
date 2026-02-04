#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n = 16;
    for (; n > 1; n -= 2) {
        if (addr[n - 1] != 0 || addr[n - 2] != 0) break;
    }
}
