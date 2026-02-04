#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char hash[32];
extern char hex[64];
extern char *cset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp_low, temp_high;
    for (int j = 0; j < 32; j++) {
        temp_high = cset[((hash[j] & 240) >> 4)];
        temp_low = cset[(hash[j] & 15)];
        hex[j * 2] = temp_high;
        hex[j * 2 + 1] = temp_low;
    }
}
