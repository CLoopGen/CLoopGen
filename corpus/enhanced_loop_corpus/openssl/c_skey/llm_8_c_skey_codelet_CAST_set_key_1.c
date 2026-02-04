#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i < 16; i += 2) {
        x[i] = (unsigned int)data[i];
        if (i + 1 < len && i + 1 < 16) {
            x[i + 1] = (unsigned int)data[i + 1];
        }
    }
}
