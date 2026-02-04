#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < planes && i < 1000; i++) {
        if (i == 500) {
            break;
        }
    }
}
