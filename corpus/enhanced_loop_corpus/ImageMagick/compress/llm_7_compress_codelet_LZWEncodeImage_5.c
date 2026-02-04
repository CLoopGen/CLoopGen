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
    table[0].prefix = (-1);
    table[0].suffix = 0;
    table[0].next = (-1);

    for (index = 1; index < 256; index++) {
        table[index].prefix = table[index - 1].prefix;
        table[index].suffix = (ssize_t)index;
        table[index].next = table[index - 1].next;
    }

    for (index = 0; index < 256; index++) {
        table[index].prefix = (-1);
        table[index].next = (-1);
    }
}
