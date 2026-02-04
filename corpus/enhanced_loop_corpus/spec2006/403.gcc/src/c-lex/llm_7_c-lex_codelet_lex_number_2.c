#include <stdio.h>

#include <inttypes.h>

extern unsigned int parts[16];
extern long high;
extern long low;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (8 * 8) / 8; i++) {
        high |= ((long)parts[i + ((8 * 8) / 8)] << ((i % 4) * 8));
        low |= (long)parts[i] << (((i + 2) % 4) * 8);
    }
}
