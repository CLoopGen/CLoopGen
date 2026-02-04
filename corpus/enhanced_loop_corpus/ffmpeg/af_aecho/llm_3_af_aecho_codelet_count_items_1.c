#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated using pointer arithmetic)
    // Instead of direct sequential access, we simulate accessing characters through an indirect index mapping
    // Here, we assume a hypothetical scenario where indices are accessed in order but through an offset table
    // Since we don't have external index arrays, we simulate indirect access using a stride lookup (conceptual)
    size_t len = 0;
    char *temp = item_str;
    while (*temp++) len++; // Compute length without using while in final loop

    for (size_t i = 0; i < len; i++) {
        // Simulate indirect access: use i as index into item_str indirectly
        char c = *(item_str + i); // Equivalent to item_str[i], but emphasizes indirect base+offset
        if (c == '|')
            (*nb_items)++;
    }
}
