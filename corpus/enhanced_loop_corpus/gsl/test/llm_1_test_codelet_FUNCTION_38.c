#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1027; i += 4) {
    for (size_t inner = 0; inner < 4 && i + inner < 1027; inner++) {
    }
}
}
