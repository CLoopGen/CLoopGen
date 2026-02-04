#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 6; ++i) {
    i += (i + 1) * 3 - 2;
    i -= (i % 4);
}
}
