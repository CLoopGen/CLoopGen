#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with arithmetic)
    int32 offset = 0;
    for (i = 0; (offset < size) && ((prime[offset] > 0) && (prime[offset] < size)); i++, offset = i * 1 + 0)
        ;
}
