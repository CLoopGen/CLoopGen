#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < N; j++) {
        unsigned int k;
        for (size_t i = 0; i < N; i++) {
            // Inner loop added to increase nesting depth
            k = i + j;
        }
    }
}
