#include <stdio.h>

#include <inttypes.h>

extern char *url;
extern char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a fixed increment (mimicking lookup via index table)
    int stride_pattern[] = {1, 2, 1}; // Example access pattern
    int pattern_size = 3;
    char *p = url;
    int i = 0;

    for (; *p != '\x00'; ) {
        if (*p == ' ') {
            end = p;
            return;
        }
        p += stride_pattern[i % pattern_size]; // Strided jump based on pattern
        i++;

        // Prevent infinite loop by bounding p within reasonable range
        if (p > url + 1000) break;
    }

    // Final fallback: scan linearly from start to ensure correctness
    for (end = url; *end != '\x00'; end++) {
        if (*end == ' ') break;
    }
}
