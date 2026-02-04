#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dest_size1 * dest_size2; i++) {
    size_t e1 = i * i + 3;
    size_t e2 = (e1 + i) % 7;
    e1 += e2 * 2;
}
}
