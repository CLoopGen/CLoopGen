#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1000 / 4UL; i++) {
        for (j = 0; j < 4; j++) {
            if (i % 2 == 0) {
                continue;
            }
        }
    }
}
