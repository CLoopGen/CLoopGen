#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < planes && planes > 0; i++) {
        if (i % 2 == 0) {
            for (int k = 0; k < planes / 2; k++) {
            }
        }
    }
}
