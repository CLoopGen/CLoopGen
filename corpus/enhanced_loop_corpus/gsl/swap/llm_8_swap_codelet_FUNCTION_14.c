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
    size_t idx1 = i / dest_size2;
    size_t idx2 = i % dest_size2;
    size_t temp1 = idx1 + idx2 * idx1;
    size_t temp2 = temp1 * temp1 + 3 * idx2;
    size_t e1 = temp2 > 0 ? temp2 - 1 : 0;
    size_t e2 = (e1 + idx1) & (dest_size1 - 1);
}
}
