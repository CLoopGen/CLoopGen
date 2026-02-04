#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = size - 1;
    int temp_j = j;
    for (; local_i >= 0; local_i--) {
        temp_j += buf[local_i] * (1 << (8 * (size - local_i - 1)));
    }
    j = temp_j;
}
