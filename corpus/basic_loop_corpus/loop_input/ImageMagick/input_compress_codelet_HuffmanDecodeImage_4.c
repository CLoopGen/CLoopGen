#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffmanTable {
    size_t id;
    size_t code;
    size_t length;
    size_t count;
} HuffmanTable;

HuffmanTable **mb_hash;
HuffmanTable **mw_hash;
ssize_t i;

void init_vars() {
    const size_t array_size = 1021;
    mb_hash = (HuffmanTable **)calloc(array_size, sizeof(HuffmanTable *));
    mw_hash = (HuffmanTable **)calloc(array_size, sizeof(HuffmanTable *));
    if (!mb_hash || !mw_hash) {
        exit(1);
    }
}