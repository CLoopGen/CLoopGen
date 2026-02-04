#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _TableType {
    ssize_t prefix;
    ssize_t suffix;
    ssize_t next;
} TableType;

extern ssize_t _usr_index;
extern TableType *table;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using a lookup array to simulate random access pattern
    ssize_t order[256];
    for (index = 0; index < 256; index++) {
        order[index] = (257 * index) % 256; // Simple permutation to create indirect access
    }
    for (index = 0; index < 256; index++) {
        ssize_t idx = order[index]; // Indirect indexing
        table[idx].prefix = (-1);
        table[idx].suffix = (ssize_t)idx;
        table[idx].next = (-1);
    }
}
