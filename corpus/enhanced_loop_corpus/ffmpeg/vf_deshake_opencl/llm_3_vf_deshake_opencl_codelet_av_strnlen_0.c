#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with an offset array (simulated indirect pattern)
    // We simulate indirect access by stepping through indices via a fixed offset pattern (e.g., reverse order scan)
    // Here we traverse from the end toward the beginning (reverse consecutive access), which alters access pattern
    char *p = s + (len > 0 ? len - 1 : 0);
    for (i = len > 0 ? len - 1 : 0; i < len && p >= s && *p; i--, p--)
        ;
    // Adjust i to point to the correct position after reverse scan (points to where null or condition broke)
    if (p < s) i = len;
    else i = p - s;
}
