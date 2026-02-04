#include <stdio.h>

#include <inttypes.h>

extern int ok;
extern size_t chosen_payload_len;
extern size_t chosen_hdr_len;
extern size_t payload_len[4];
extern size_t hdr_len[4];
extern int i;
extern int valid[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 1, but accessed via index mapping to simulate flexibility)
    // Here we use an auxiliary index array to simulate indirect/strided-like access pattern
    int index_map[] = {3, 2, 1, 0}; // Reverse order access — logical equivalent but with indirection
    int n = sizeof(index_map) / sizeof(index_map[0]);
    for (i = 0; i < n; ++i) {
        int idx = index_map[i];
        if (valid[idx] && payload_len[idx] >= chosen_payload_len) {
            chosen_payload_len = payload_len[idx];
            chosen_hdr_len = hdr_len[idx];
            ok = 1;
        }
    }
}
