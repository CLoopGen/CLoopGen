#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulates irregular access pattern)
    // Build an index map that defines the order of access
    char *base = s1 + pos;
    int len = 0;
    char *temp[256]; // Assume max string length for simplicity
    while (len < 255 && base[len]) {
        temp[len] = &base[len];
        len++;
    }
    temp[len] = NULL;

    // Process characters via pointer indirection in reverse order (to alter access pattern)
    for (int i = len - 1; i >= 0; i--) {
        char *p = temp[i];
        if (*(p + 1)) {
            *p = *(p + 1);
        } else {
            *p = '\0'; // Handle end
        }
    }
}
