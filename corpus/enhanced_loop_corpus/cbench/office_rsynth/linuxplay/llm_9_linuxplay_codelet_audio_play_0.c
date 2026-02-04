#include <stdio.h>

#include <inttypes.h>

extern int n;
extern short *data;
extern unsigned char *converted;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        int adjusted = data[i] - 32768;
        int scaled = adjusted >> 8;  // Equivalent to division by 256 using bit shift
        converted[i] = (unsigned char)scaled;
    }
}
