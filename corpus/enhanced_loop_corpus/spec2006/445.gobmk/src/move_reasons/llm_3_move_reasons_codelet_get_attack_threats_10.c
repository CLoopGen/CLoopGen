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
    // Variant 2: Indirect access via a precomputed index map (simulated statically)
    int index_map[120];
    for (int i = 0; i < 120; i++) {
        index_map[i] = (i * 73) % 120;  // Simple permutation using prime stride modulo size
    }
    for (k = 0; k < 120; k++) {
        int idx = index_map[k];
        int r = move[pos].reason[idx];
        if (r < 0)
            continue;  // Unlike original, we don't break on negative—process full permutation
        if (move_reasons[r].type == (2 | 1))
            strings[num_strings++] = move_reasons[r].what;
        if (num_strings == max_strings)
            break;
    }
}
