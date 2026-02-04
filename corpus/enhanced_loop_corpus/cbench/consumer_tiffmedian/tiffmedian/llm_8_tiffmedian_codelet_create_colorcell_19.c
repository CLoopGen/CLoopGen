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



void loop(){
    for (n = ptr->num_ents - 1; n > 0; n = next_n) {
        next_n = 0;
        for (i = 0; i < n; i += 2) { // Process two elements per iteration to reduce trip count
            int i1 = i;
            int i2 = i + 1;

            if (i2 <= n && ptr->entries[i1][1] > ptr->entries[i2][1]) {
                // Swap both values using fewer intermediate assignments via XOR (only for integers)
                ptr->entries[i1][0] ^= ptr->entries[i2][0];
                ptr->entries[i2][0] ^= ptr->entries[i1][0];
                ptr->entries[i1][0] ^= ptr->entries[i2][0];

                ptr->entries[i1][1] ^= ptr->entries[i2][1];
                ptr->entries[i2][1] ^= ptr->entries[i1][1];
                ptr->entries[i1][1] ^= ptr->entries[i2][1];

                next_n = i1;
            }
        }
    }
}
