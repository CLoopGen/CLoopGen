#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int num_ents;
    int entries[256][2];
} C_cell;

extern int i;
extern C_cell *ptr;
extern int next_n;
extern int tmp;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing adjacent elements (i, i+1), access with a stride of 2
    // This changes comparison and swap pattern to operate on elements spaced by 2
    // Adjust logic to ensure bounds are respected and sorting behavior is preserved
    for (n = (ptr->num_ents - 1) / 2; n > 0; n = next_n) {
        next_n = 0;
        for (i = 0; i < n * 2 && (i + 2) < ptr->num_ents; i += 2) {
            if (ptr->entries[i][1] > ptr->entries[i + 2][1]) {
                tmp = ptr->entries[i][0];
                ptr->entries[i][0] = ptr->entries[i + 2][0];
                ptr->entries[i + 2][0] = tmp;
                tmp = ptr->entries[i][1];
                ptr->entries[i][1] = ptr->entries[i + 2][1];
                ptr->entries[i + 2][1] = tmp;
                next_n = i / 2;
            }
        }
    }
}
