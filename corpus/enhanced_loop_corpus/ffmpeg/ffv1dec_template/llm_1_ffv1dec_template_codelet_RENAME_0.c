#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 4; x++) {
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 2; k++) {
        }
    }
}
}
