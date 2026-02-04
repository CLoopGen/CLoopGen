#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated)
    // Simulate indirect access using a fixed pattern: traverse in reverse order within chunks
    size_t chunk_size = 4;
    size_t num_chunks = (len + chunk_size - 1) / chunk_size;
    i = 0;
    for (size_t c = 0; c < num_chunks; c++) {
        size_t start = c * chunk_size;
        size_t end = (start + chunk_size < len) ? start + chunk_size : len;
        // Traverse chunk in reverse to create non-sequential access
        for (size_t j = end; j > start; j--) {
            i = j - 1;
            if (!s[i]) {
                // Early termination if null byte found
                goto exit_loop;
            }
        }
    }
exit_loop:
    // Finalize i such that it reflects the first position where s[i] == 0 or i == len
    while (i < len && s[i]) i++;
}
