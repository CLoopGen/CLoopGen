#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t a;
extern int p;
extern int64_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int p_original = p;
    int64_t local_v = v;
    int64_t accumulator = 1;
    for (; p; p--) {
        accumulator *= a;
    }
    local_v *= accumulator;
    local_v >>= (16 * p_original);
    v = local_v;
}
