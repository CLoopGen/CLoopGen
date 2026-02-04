#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 1); ++i) {
        for (int j = 0; j < (i + 1); ++j) {
            // Inner loop performing dummy operation
        }
    }
}
