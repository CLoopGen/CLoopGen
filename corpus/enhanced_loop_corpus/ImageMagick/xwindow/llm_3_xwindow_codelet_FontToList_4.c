#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of direct sequential traversal, we use an auxiliary index array to simulate indirect access.
    // For realism and simplicity, we generate indices in-order but through an indirection layer.
    size_t len = 0;
    char *temp = font;
    while (*temp++) len++; // Compute length without using while in main logic

    // Create a simulated index map (in real scenarios this could be non-sequential)
    ptrdiff_t *indices = (ptrdiff_t*)malloc(len * sizeof(ptrdiff_t));
    if (!indices) return; // Fail gracefully if malloc fails

    for (size_t i = 0; i < len; i++)
        indices[i] = (ptrdiff_t)i;

    // Use indirect addressing via index array
    for (size_t i = 0; i < len; i++) {
        char c = *(font + indices[i]);
        if (c == '\x00') break;
        if ((c == ':') || (c == ';') || (c == ','))
            fonts++;
    }

    free(indices);
}
