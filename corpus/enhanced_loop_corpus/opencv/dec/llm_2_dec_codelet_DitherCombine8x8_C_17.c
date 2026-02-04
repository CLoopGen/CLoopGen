#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; ++j) {
    for (i = 0; i < 8; ++i) {
        const int delta0 = i * 16 + j;
        const int delta1 = (i + 1) * 16 + j;
    }
}
}
