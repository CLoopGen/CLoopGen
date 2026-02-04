#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Use a separate index mapping: assume indices are accessed in non-linear order
    // Here, simulate indirect access by jumping to mirrored positions from the end
    size_t idx;
    size_t len = 0;
    // First compute effective length to bound indirect access
    const unsigned char* tmp = content;
    while (*tmp++) len++;
    for (idx = 0; idx < len; idx++) {
        // Map index to reverse offset (indirect pattern): accessing from front and back alternately
        size_t pos = (idx % 2 == 0) ? idx : (len - 1 - (idx / 2));
        unsigned char val = content[pos];
        if (val == '\x00') break;
        length += (val & 128) ? 2 : 1;
    }
}
