#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect array indexing via an index mapping array (simulated with simple permutation)
    static int8_t index_map[32]; // Assume max pred_order <= 32
    if (index_map[0] == 0) { // Initialize once
        for (j = 0; j < 32; j++) {
            index_map[j] = (j * 7) % 32; // Pseudo-random permutation
        }
    }
    for (i = pred_order; i < len; i++, decoded++) {
        int64_t sum = 0;
        for (j = 0; j < pred_order; j++) {
            int mapped_idx = index_map[j] % pred_order;
            sum += (int64_t)coeffs[mapped_idx] * decoded[mapped_idx];
        }
        decoded[0] += sum >> qlevel; // Write result to fixed location
    }
}
