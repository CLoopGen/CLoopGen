#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 2); ++i) {
        for (int j = 0; j < 4; ++j) {
            // Inner loop added: increased nesting depth to 2
            // Simulates processing 4 elements per outer iteration
        }
    }
}
