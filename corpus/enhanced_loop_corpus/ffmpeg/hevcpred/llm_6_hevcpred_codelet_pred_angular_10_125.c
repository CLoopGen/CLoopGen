#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *top;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (x = 0; x <= size - 3; x += 4) {
        temp = ((const union unaligned_64 *)(&top[x - 1]))->l;
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = temp;
    }
    // Introduces a temporary variable to modify the data dependency pattern (breaks direct WAW and RAW if multiple accesses)
    // Changes from direct memory-to-memory to use an intermediate register, altering data flow.
}
