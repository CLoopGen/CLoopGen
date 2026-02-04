#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    // Create a local indirect index mapping: access characters in reverse order within segments
    size_t chunk = 4;
    size_t j = 0;
    for (i = 0; i < len; i += chunk) {
        // Process each chunk in reverse to create non-consecutive access pattern
        for (size_t k = (i + chunk > len) ? len - i : chunk; k-- > 0;) {
            size_t idx = i + k;
            if (idx < len && !s[idx]) {
                j = idx;
                goto exit_loop;
            }
        }
    }
    j = i;
exit_loop:
    i = j;
}
