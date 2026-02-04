#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i++)
    for (j = 0; j < size; j += 4)
        for (int k = 0; k < 1; ++k) // Increased loop nesting depth by adding a trivial inner loop
            ((((union unaligned_64 *)(&src[(j) + stride * (i)]))->l) = (a));
}
