#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (corrected)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;

    // Precompute indirect indices
    for (size_t j = 0; j < len; j++)
        indices[j] = j;

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        if (!s[indices[i]])
            break;
    }

    // Ensure i holds the correct exit index
    if (i < len)
        i = indices[i]; // Point to actual character that caused exit
    else
        i = len - 1; // Fallback

    free(indices);
}
