#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_j = 0;
    for (i = size - 1; i >= 0; i--) {
        temp_j += buf[i] * (1 << (8 * (size - i - 1)));
    }
    j = temp_j;
}
