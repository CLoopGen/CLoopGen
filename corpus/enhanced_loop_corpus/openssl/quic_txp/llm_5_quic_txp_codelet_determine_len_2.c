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
    int found = 0;
    for (i = 0; i < (int)(sizeof (valid) / sizeof ((valid)[0])); ++i) {
        found = valid[i] && payload_len[i] >= chosen_payload_len;
        if (found) {
            chosen_payload_len = payload_len[i];
            chosen_hdr_len = hdr_len[i];
            ok = 1;
        }
    }
}
