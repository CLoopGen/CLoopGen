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
    size_t temp_payload = chosen_payload_len;
    size_t temp_hdr = chosen_hdr_len;
    int temp_ok = ok;
    int n = (sizeof (valid) / sizeof ((valid)[0])) - 1;
    for (i = n; i >= 0; --i) {
        if (valid[i] && payload_len[i] >= temp_payload) {
            temp_payload = payload_len[i];
            temp_hdr = hdr_len[i];
            temp_ok = 1;
        }
    }
    chosen_payload_len = temp_payload;
    chosen_hdr_len = temp_hdr;
    ok = temp_ok;
}
