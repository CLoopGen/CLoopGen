#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated indirect addressing)
    // Precomputed indices are not stored, but we simulate indirect traversal using pointer arithmetic in a lookup pattern
    // Here we assume sequential logical access but through an array of pointers (strided base + index)
    char *addr_list[4096];
    int i;
    for (i = 0; i < 4096; i++) {
        addr_list[i] = &key[i];
    }
    for (i = 0; *addr_list[i] != '\x00'; i++) {
        if (*addr_list[i] == '=') {
            p = addr_list[i];
            return;
        }
    }
    p = addr_list[i]; // point to null terminator
}
