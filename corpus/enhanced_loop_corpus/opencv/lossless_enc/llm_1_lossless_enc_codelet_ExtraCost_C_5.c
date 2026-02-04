#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < length / 2 - 1 && i < 100; ++i) {
        if (i % 2 == 0) {
            for (int k = i; k < i + 5; ++k) {
            }
        }
    }
}
