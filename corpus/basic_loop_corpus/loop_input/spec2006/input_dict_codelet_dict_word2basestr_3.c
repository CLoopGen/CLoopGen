#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int int32;

char *word;
int32 i;
int32 len;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    word = (char*)malloc(data_size);
    if (!word) {
        exit(1);
    }
    // Fill with non '(' characters except near the beginning to ensure loop stops safely
    memset(word, 'x', data_size);
    // Place '(' at index 1 so that loop stops at i=1 without going out of bounds
    word[1] = '(';
    len = data_size - 1; // ensures i starts at len-2 = data_size-3, which is safe
    i = 0; // will be overwritten by loop, but initialize anyway
}