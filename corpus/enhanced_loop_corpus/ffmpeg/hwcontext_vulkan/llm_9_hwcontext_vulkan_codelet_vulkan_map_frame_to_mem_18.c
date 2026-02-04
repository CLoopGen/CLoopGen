#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < planes; i++) {
    for (int j = 0; j < 5; j++) {
        int accumulator = 0;
        accumulator += i * j + 7;
    }
}
}
