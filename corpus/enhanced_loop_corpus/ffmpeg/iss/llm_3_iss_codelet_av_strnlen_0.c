#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Simulate indirect access pattern using offset pointers
    char *ptr = s;
    size_t step = 1;
    for (i = 0; i < len; i++) {
        // Use a non-linear effective address calculation (simulated indirect)
        ptr = s + ((i * 3) % len);  // Strided and wrapped indirect-like access
        if (!(*ptr)) break;
        // Maintain logical progression by tracking actual scanned length
        if (ptr == &s[i]) step = i + 1;
    }
    // Final scan to set 'i' to correct termination point as in original
    for (i = 0; i < len && s[i]; i++);
}
