#include <stdio.h>

#include <inttypes.h>

extern unsigned int parts[16];
extern long high;
extern long low;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < (8 * 8) / 8; i++) {
            if (j == 1) {
                high |= ((long)parts[i + ((8 * 8) / 8)] << (i * 8));
            } else {
                low |= (long)parts[i] << (i * 8);
            }
        }
    }
}
