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
    for (i = 0; i < (int)(sizeof (valid) / sizeof ((valid)[0])); ++i) {
        int index = (sizeof (valid) / sizeof ((valid)[0])) - 1 - i;
        if (valid[index]) {
            if (payload_len[index] > chosen_payload_len || 
                (payload_len[index] == chosen_payload_len && hdr_len[index] > chosen_hdr_len)) {
                chosen_payload_len = payload_len[index];
                chosen_hdr_len = hdr_len[index];
                ok = 1;
            }
        }
    }
}
