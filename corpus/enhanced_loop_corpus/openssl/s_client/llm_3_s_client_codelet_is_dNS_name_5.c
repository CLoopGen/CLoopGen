#include <stdio.h>

#include <inttypes.h>

extern  char *host;
extern  size_t MAX_LABEL_LENGTH;
extern size_t i;
extern int isdnsname;
extern size_t length;
extern size_t label_length;
extern int all_numeric;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulates indirect addressing pattern)
    // Create a local index array to define custom access order (e.g., reverse every block of 4)
    size_t indices[8]; // Small fixed-size buffer for indirect indexing (block processing)
    size_t block_size = 8;
    for (size_t block_start = 0; block_start < length && label_length < MAX_LABEL_LENGTH; block_start += block_size) {
        // Build indirect index list: reverse the order in this block for variation
        size_t limit = (block_start + block_size < length) ? block_start + block_size : length;
        size_t idx_count = 0;
        for (size_t j = limit - 1; j >= block_start && idx_count < 8; --j) {
            indices[idx_count++] = j;
            if (j == 0) break; // Prevent underflow when j reaches 0
        }
        // Traverse this block in reverse order using indirect indices
        for (size_t k = 0; k < idx_count && label_length < MAX_LABEL_LENGTH; ++k) {
            i = indices[k];
            char c = host[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
                label_length += 1;
                all_numeric = 0;
                continue;
            }
            if (c >= '0' && c <= '9') {
                label_length += 1;
                continue;
            }
            if (i > 0 && i < length - 1) {
                if (c == '-') {
                    label_length += 1;
                    continue;
                }
                if (c == '.' && host[i + 1] != '.' && host[i - 1] != '-' && host[i + 1] != '-') {
                    label_length = 0;
                    isdnsname = 1;
                    continue;
                }
            }
            isdnsname = 0;
            return; // Break out early on invalid character
        }
    }
}
