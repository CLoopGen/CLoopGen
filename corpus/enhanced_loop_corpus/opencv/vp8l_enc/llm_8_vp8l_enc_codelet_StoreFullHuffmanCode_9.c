#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < num_tokens * 2; i += 2) {
        for (j = 0; j < 3; ++j) {
            i += (i + j) % 5;
        }
    }
}
