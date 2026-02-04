#include <stdio.h>

#include <inttypes.h>

struct move_data {
    float value;
    float final_value;
    float additional_ko_value;
    float territorial_value;
    float strategical_value;
    float maxpos_shape;
    float maxneg_shape;
    int numpos_shape;
    int numneg_shape;
    float followup_value;
    float influence_followup_value;
    float reverse_followup_value;
    float secondary_value;
    float min_value;
    float max_value;
    float min_territory;
    float max_territory;
    float randomness_scaling;
    int reason[120];
    int move_safety;
    int worthwhile_threat;
    float random_number;
};


struct move_reason {
    int type;
    int what;
    int status;
};


extern struct move_data move[400];
extern struct move_reason move_reasons[1000];
extern int pos;
extern int max_strings;
extern int strings[];
extern int k;
extern int num_strings;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic and loop unrolling
    int k0, k1, k2, k3;
    const struct move_reason* mr = move_reasons;
    const int* reason_list = move[pos].reason;
    int* strings_ptr = strings;
    int count = num_strings;
    int limit = max_strings - count;

    // Unroll by 4 for consecutive access and improved spatial locality
    for (k0 = 0; k0 < 120 && limit > 0; k0 += 4) {
        int r0 = reason_list[k0];
        if (r0 < 0) break;
        if (mr[r0].type == (8 | 1)) {
            *strings_ptr++ = mr[r0].what;
            if (++count >= max_strings) break;
        }

        int r1 = reason_list[k0 + 1];
        if (r1 < 0) break;
        if (mr[r1].type == (8 | 1)) {
            *strings_ptr++ = mr[r1].what;
            if (++count >= max_strings) break;
        }

        int r2 = reason_list[k0 + 2];
        if (r2 < 0) break;
        if (mr[r2].type == (8 | 1)) {
            *strings_ptr++ = mr[r2].what;
            if (++count >= max_strings) break;
        }

        int r3 = reason_list[k0 + 3];
        if (r3 < 0) break;
        if (mr[r3].type == (8 | 1)) {
            *strings_ptr++ = mr[r3].what;
            if (++count >= max_strings) break;
        }
    }
    // Handle remaining elements not covered by unrolling
    for (; k0 < 120; k0++) {
        int r = reason_list[k0];
        if (r < 0) break;
        if (mr[r].type == (8 | 1)) {
            *strings_ptr++ = mr[r].what;
            if (++count >= max_strings) break;
        }
    }
    num_strings = count;
}
