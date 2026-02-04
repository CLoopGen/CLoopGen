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
for (ssize_t outer = 0; outer < 16; outer++) {
    for (index = outer * 16; index < (outer + 1) * 16 && index < 256; index++) {
        table[index].prefix = (-1);
        table[index].suffix = (ssize_t)index;
        table[index].next = (-1);
    }
}
}
