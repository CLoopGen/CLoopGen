#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        if (counts[i] > 0) {
            codes[i + 1] = (codes[i] + counts[i]) << 1;
        } else {
            codes[i + 1] = codes[i];
        }
    }
}
