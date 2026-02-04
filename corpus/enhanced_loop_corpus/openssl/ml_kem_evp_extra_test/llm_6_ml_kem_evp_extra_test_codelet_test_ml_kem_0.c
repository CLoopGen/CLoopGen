#include <stdio.h>

#include <inttypes.h>

extern unsigned char *agenkey;
extern size_t agenkeylen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_index = 0;
    for (i = 0; i < agenkeylen; i++) {
        temp_index = i;  // Introduce WAW dependency on temp_index, but no loop-carried dependency
        if (agenkey[temp_index] != 0) {  // RAW: use of temp_index after write
            i = agenkeylen;  // Modify i to break loop (WAW on i), creating a non-standard exit
        }
    }
}
