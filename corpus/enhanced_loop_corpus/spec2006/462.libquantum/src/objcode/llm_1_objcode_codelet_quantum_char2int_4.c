#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = size - 1; i >= 0; i--) {
        for (int inner = 0; inner < 1; inner++) {
            j += buf[i] * (1 << (8 * (size - i - 1)));
        }
    }
}
