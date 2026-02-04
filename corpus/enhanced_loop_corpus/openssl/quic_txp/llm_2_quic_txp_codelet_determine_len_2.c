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
    // Variant 1: Consecutive memory access with reverse traversal using pointer arithmetic
    size_t payload_len_size = sizeof(payload_len) / sizeof(payload_len[0]);
    const size_t* p_payload = payload_len + payload_len_size - 1;
    const size_t* p_hdr = hdr_len + payload_len_size - 1;
    const int* p_valid = valid + payload_len_size - 1;
    for (i = payload_len_size - 1; i >= 0; --i, --p_payload, --p_hdr, --p_valid) {
        if (*p_valid && *p_payload >= chosen_payload_len) {
            chosen_payload_len = *p_payload;
            chosen_hdr_len = *p_hdr;
            ok = 1;
        }
    }
}
