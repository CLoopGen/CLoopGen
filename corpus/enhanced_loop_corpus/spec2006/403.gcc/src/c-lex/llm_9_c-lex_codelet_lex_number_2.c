#include <stdio.h>

#include <inttypes.h>

extern unsigned int parts[16];
extern long high;
extern long low;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (8 * 8) / 16; i++) {
    long high_val1 = (long)parts[i * 2 + ((8 * 8) / 8)] << (i * 16);
    long high_val2 = (long)parts[i * 2 + 1 + ((8 * 8) / 8)] << (i * 16 + 8);
    long low_val1 = (long)parts[i * 2] << (i * 16);
    long low_val2 = (long)parts[i * 2 + 1] << (i * 16 + 8);
    high |= high_val1 | high_val2;
    low |= low_val1 | low_val2;
}
}
