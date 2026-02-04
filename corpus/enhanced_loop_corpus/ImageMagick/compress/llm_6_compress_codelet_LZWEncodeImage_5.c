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
    ssize_t temp_prefix[256];
    ssize_t temp_suffix[256];
    ssize_t temp_next[256];

    for (index = 0; index < 256; index++) {
        temp_prefix[index] = (-1);
        temp_suffix[index] = (ssize_t)index;
        temp_next[index] = (-1);
    }

    for (index = 0; index < 256; index++) {
        table[index].prefix = temp_prefix[index];
        table[index].suffix = temp_suffix[index];
        table[index].next = temp_next[index];
    }
}
