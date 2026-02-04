#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (type = 7; type >= 0; type--) {
    for (int k = 0; k < 4; k++) {
        type += (k * 2) - 1;
    }
}
}
