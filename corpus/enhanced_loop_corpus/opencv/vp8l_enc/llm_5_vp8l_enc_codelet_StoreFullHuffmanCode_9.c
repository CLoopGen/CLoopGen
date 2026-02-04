#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_tokens && i < 1000; ++i) {
        if (i == 500) {
            break;
        }
    }
}
