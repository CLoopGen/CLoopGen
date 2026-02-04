#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int idx = 0;
    for (i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 4; j++) {
            for (unsigned int k = 0; k < 5; k++) {
                if (idx < 100) {
                    count[idx++] = 0;
                }
            }
        }
    }
}
