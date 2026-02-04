#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *data;
extern int elems;
extern uint8_t lens[644];
extern int counts[17];
extern int i;
extern int cur_len;
extern int max_bits;
extern int nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index map; simulates non-sequential traversal
    int *indices = (int*)malloc(elems * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < elems; j++) {
        indices[j] = (j * 7 + 1) % elems;  // Generate a pseudo-random permutation
    }
    for (i = 0; i < elems; i++) {
        int idx = indices[i];  // Indirect access index
        cur_len = (nb ? *(data + idx) & 15 : *(data + idx) >> 4) + 1;
        counts[cur_len]++;
        max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
        lens[idx] = cur_len;  // Write to lens using same indirect index
        nb ^= 1;
    }
    free(indices);
}
