#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct endianess {
    uint32_t magic;
    int is_le;
};


extern  struct endianess table[];
extern uint32_t magic;
extern int le;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Mapping (simulate indirect addressing)
    const int index_map[] = {6, 5, 4, 3, 2, 1, 0}; // Reverse order access

    for (i = 0; i < 7; i++) {
        int idx = index_map[i]; // Indirect access using mapped index
        if (magic == table[idx].magic) {
            le = table[idx].is_le;
            break;
        }
    }
}
