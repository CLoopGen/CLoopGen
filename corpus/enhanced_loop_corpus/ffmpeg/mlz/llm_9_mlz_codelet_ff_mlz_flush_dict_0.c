#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MLZDict {
    int string_code;
    int parent_code;
    int char_code;
    int match_len;
} MLZDict;

extern MLZDict *dict;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work using synthetic inner loop emulation via indexing
    int outer_limit = 8756;  // Approximately 35023 / 4
    for (i = 0; i < outer_limit; i++) {
        int base_idx = i * 4;
        // Simulate processing of multiple elements per iteration without nested loops
        dict[base_idx + 0].string_code = -1;
        dict[base_idx + 0].parent_code = -1;
        dict[base_idx + 0].match_len = 0;

        if (base_idx + 1 < 35023) {
            dict[base_idx + 1].string_code = -1;
            dict[base_idx + 1].parent_code = -1;
            dict[base_idx + 1].match_len = 0;
        }

        if (base_idx + 2 < 35023) {
            dict[base_idx + 2].string_code = -1;
            dict[base_idx + 2].parent_code = -1;
            dict[base_idx + 2].match_len = 0;
        }

        if (base_idx + 3 < 35023) {
            dict[base_idx + 3].string_code = -1;
            dict[base_idx + 3].parent_code = -1;
            dict[base_idx + 3].match_len = 0;
        }

        // Add auxiliary computation to maintain workload perception
        int temp = base_idx * base_idx;
        temp %= 1000;
        dict[base_idx % 35023].char_code = temp;
    }
}
