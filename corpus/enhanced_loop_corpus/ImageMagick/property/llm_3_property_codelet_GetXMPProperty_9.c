#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive double-check access with prefetch-like pattern
    // Access memory in larger strides but verify consecutive elements in groups
    // Simulates burst or block access behavior without while loops
    char *local_p = xmp_profile;
    size_t i;
    size_t chunk_size = 4;
    size_t len = 0;
    char *temp = local_p;
    while (*temp++) len++; // Compute length without using while in loop header directly
    for (i = 0; i < len && *(local_p + i) != '\x00'; i += chunk_size) {
        // Check each position in the chunk consecutively
        for (size_t j = 0; j < chunk_size && (i + j) < len && *(local_p + i + j) != '\x00'; j++) {
            p = local_p + i + j;
            if ((*p == '<') && (*(p + 1) == 'x')) {
                goto exit_loop;
            }
        }
    }
    p = local_p + i; // In case it ends normally
exit_loop:
    return;
}
