#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            i += (j % 2) ? (i % 4) : (j + 1);
        }
    }
}
