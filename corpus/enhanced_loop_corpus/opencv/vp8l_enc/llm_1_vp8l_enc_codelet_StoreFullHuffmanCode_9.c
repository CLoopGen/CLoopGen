#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num_tokens > 0) {
        for (i = 0; i < num_tokens; ++i) {
            for (int k = 0; k < 1; ++k) {
            }
        }
    }
}
