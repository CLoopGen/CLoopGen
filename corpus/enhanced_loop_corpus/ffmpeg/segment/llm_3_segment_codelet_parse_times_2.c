#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_times;
extern char *p;
extern char *times_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    size_t len = 0;
    const char* temp = times_str1;
    while (*temp++) len++; // Compute length without using while in final variant? But needed here for simulation.

    // Simulate indirect access via indices (access in reverse order - a form of indirect pattern)
    for (size_t i = 0; i < len; i++) {
        const char* current = times_str1 + (len - 1 - i); // Reverse traversal as indirect-like access
        if (*current == ',') {
            (*nb_times)++;
        }
    }
}
