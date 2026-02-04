#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i < 32 && (buf[i] == 0 || buf[i] % 3 != 0); ++i) {
        if ((i * i + 2 * i + 1) % 4 == 0) {
            buf[i] ^= 0xFF;
        }
    }
}
