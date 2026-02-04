#include <stddef.h>
#include <stdint.h>

int ok;
size_t chosen_payload_len;
size_t chosen_hdr_len;
size_t payload_len[4];
size_t hdr_len[4];
int i;
int valid[4];

void init_vars() {
    // Initialize chosen values to small numbers to allow updates
    chosen_payload_len = 0;
    chosen_hdr_len = 0;
    ok = 0;

    // Initialize arrays with sample data
    for (int idx = 0; idx < 4; ++idx) {
        valid[idx] = 1; // Mark all entries as valid
        payload_len[idx] = (idx + 1) * 10000; // Increasing sizes: 10k, 20k, 30k, 40k
        hdr_len[idx] = (idx + 1) * 100;       // Corresponding header lengths
    }

    // Ensure that the loop processes all elements safely
    i = 0;
}