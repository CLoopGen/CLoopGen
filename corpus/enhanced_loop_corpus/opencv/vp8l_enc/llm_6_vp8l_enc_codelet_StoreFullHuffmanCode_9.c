#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < num_tokens; ++i) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // This variant modifies data flow by creating a loop-local accumulation, introducing a WAW on 'temp'
    // and a true dependence (RAW) between iterations via the use of previous temp value.
}
