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
    // Variant 2: Strided (reverse sequential) indirect access with stride of 3
    int step = 3;
    int k;
    int count = num_strings;
    int limit = max_strings;
    const int* reason_list = move[pos].reason;
    const struct move_reason* mr = move_reasons;
    int* strings_ptr = strings;

    // Access indices in reverse order with a fixed stride to create non-consecutive access pattern
    for (k = 119; k >= 0; k -= step) {
        int r = reason_list[k];
        if (r < 0) continue;  // Skip invalid reasons but keep going due to strided pattern
        if (mr[r].type == (8 | 1)) {
            if (count >= limit) break;
            strings_ptr[count++] = mr[r].what;
        }
    }

    // Finalize the updated string count
    num_strings = count;
}
