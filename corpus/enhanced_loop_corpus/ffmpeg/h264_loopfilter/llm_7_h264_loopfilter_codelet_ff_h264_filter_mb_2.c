#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int accumulator = 0;
for (i = 0; i < 8; i++) {
    accumulator = accumulator + i;
}
i = accumulator;
}
