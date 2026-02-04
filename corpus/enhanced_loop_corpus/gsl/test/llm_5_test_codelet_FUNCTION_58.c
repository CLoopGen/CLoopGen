#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1027 && i != 500; i++) {
        if (i == 300) {
            i += 100;
        }
    }
}
