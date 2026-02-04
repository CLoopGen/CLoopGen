#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using precomputed index list
    if (len == 0) return;

    size_t *index_map = (size_t*)malloc(len * sizeof(size_t));
    if (!index_map) return;

    for (i = 0; i < len; i++)
        index_map[i] = i;

    i = 0;
    while (i < len) {
        size_t pos = index_map[i];
        if (!s[pos]) break;
        i++;
    }
    if (i < len)
        i = index_map[i]; // set i to actual string index where null was found
    else
        i = len;

    free(index_map);
}
