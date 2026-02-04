#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array
    char **access_order = (char**)malloc(len * sizeof(char*));
    if (!access_order) {
        for (i = 0; i < len && s[i]; i++);
        return;
    }

    for (i = 0; i < len; i++)
        access_order[i] = &s[i];

    i = 0;
    for (i = 0; i < len; i++) {
        if (!(*access_order[i]))
            break;
    }

    // Map back to index: i is count of accessed elements
    if (i < len)
        i = access_order[i] - s; // compute offset
    else
        i = len;

    free(access_order);
}
