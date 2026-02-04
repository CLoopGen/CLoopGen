#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *path;
extern  size_t components;
extern char *p;
extern ssize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array
    // Precompute valid indices in reverse order and access characters indirectly.
    // This simulates indirect memory access patterns common in sparse traversals.
    ptrdiff_t len = p - path;
    if (len <= 0) return;

    // Allocate small stack-based array for indices (assume max reasonable size)
    ptrdiff_t indices[512];
    ptrdiff_t total_indices = (len < 512) ? len : 512;
    
    // Build indirect access list: indices from current 'p' down to 'path + 1'
    for (ptrdiff_t i = 0; i < total_indices; i++) {
        indices[i] = (p - path) - i;
        if ((path + indices[i]) <= path) {
            total_indices = i;
            break;
        }
    }

    count = 0;
    for (ptrdiff_t i = 0; (count < (ssize_t)components) && (i < total_indices); i++) {
        char *ptr = path + indices[i];
        if (ptr > path && *ptr == '/') {
            *ptr = '\x00';
            count++;
        }
    }
}
