#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (simulating irregular access pattern)
    // Create a local index array that defines the access order (e.g., bit-reversed order for demonstration)
    static const UINT8 index_map[16] = {1, 2, 4, 8, 16, 3, 5, 9, 17, 6, 10, 18, 12, 20, 24, 7}; // example indirect sequence
    for (i = 0; i < 16; i++) {
        UINT8 idx = index_map[i];
        if (idx >= 1 && idx <= 16) {
            length += htbl->bits[idx];
        }
    }
}
