#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2 - 1; i++) {
        if (i % 2 == 0 && i / 2 < 16 && i / 2 < len) {
            x[i / 2] = (unsigned int)(data[i / 2] ^ 0xAA);
        } else if (i % 2 == 1 && i / 2 < len && i / 2 + 1 < 16) {
            x[i / 2 + 1] = (unsigned int)(data[i / 2 + 1] ^ 0x55);
        }
    }
}
