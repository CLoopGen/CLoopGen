#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (count = 0; count < (((8 * 8) / 8) * 2); count++) {
        if (count % 2 == 0) {
            parts[count] = 0;
        } else {
            continue;
        }
    }
}
