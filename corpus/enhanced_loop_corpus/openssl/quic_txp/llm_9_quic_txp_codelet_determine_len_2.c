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
    int n = (sizeof(valid) / sizeof(valid[0])) - 1;
    for (i = n; i >= 0; i -= 2) {
        if (valid[i] && payload_len[i] >= chosen_payload_len) {
            chosen_payload_len = payload_len[i];
            chosen_hdr_len = hdr_len[i];
            ok = 1;
        }
        if (i > 0 && valid[i-1] && payload_len[i-1] >= chosen_payload_len) {
            chosen_payload_len = payload_len[i-1];
            chosen_hdr_len = hdr_len[i-1];
            ok = 1;
        }
    }
}
