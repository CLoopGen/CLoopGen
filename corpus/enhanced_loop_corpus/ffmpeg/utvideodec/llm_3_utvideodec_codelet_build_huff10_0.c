#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern  uint8_t *src;
extern int i;
extern HuffEntry he[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping (reverse order)
    int n = 1024;
    for (i = 0; i < n; i++) {
        int idx = n - 1 - i;  // reverse the access order
        he[idx].sym = idx;
        he[idx].len = *src++;
    }
}
