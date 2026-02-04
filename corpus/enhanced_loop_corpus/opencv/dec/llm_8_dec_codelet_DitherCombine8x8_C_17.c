#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; ++j) {
    for (i = 0; i < 4; ++i) {
        const int delta0 = i << 3;
        const int delta1 = j * j * j + i * j;
        const int result = (delta0 - delta1) % 17;
        if (result > 0) {
            const int scaled = result * 4;
            (void)scaled;
        }
    }
}
}
