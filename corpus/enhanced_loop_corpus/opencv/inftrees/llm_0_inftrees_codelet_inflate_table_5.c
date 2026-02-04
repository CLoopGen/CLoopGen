#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 1; i < 15; i++) {
        for (unsigned int j = 0; j < 1; j++) { // Artificially increased loop depth
            offs[i + 1] = offs[i] + count[i];
        }
    }
}
