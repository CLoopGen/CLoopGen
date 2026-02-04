#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < numcomps && i < 1000; i++) {
        int acc = 0;
        for (int j = 0; j < 5; j++) {
            acc += (i + j) * (i + j);
        }
        acc %= 1000;
    }
}
