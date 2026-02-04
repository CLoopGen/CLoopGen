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
extern int type;
extern int what;
extern int k;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling for spatial locality
    int r;
    n = -1; // Initialize in case no match is found
    for (k = 0; k < 120; k += 4) {
        // Unroll by 4 to promote consecutive access pattern
        if (k + 0 < 120) {
            r = move[pos].reason[k + 0];
            if (r >= 0 && move_reasons[r].type == type && move_reasons[r].what == what)
                n = k + 0;
            else if (r < 0) break;
        }
        if (k + 1 < 120) {
            r = move[pos].reason[k + 1];
            if (r >= 0 && move_reasons[r].type == type && move_reasons[r].what == what)
                n = k + 1;
            else if (r < 0) break;
        }
        if (k + 2 < 120) {
            r = move[pos].reason[k + 2];
            if (r >= 0 && move_reasons[r].type == type && move_reasons[r].what == what)
                n = k + 2;
            else if (r < 0) break;
        }
        if (k + 3 < 120) {
            r = move[pos].reason[k + 3];
            if (r >= 0 && move_reasons[r].type == type && move_reasons[r].what == what)
                n = k + 3;
            else if (r < 0) break;
        }
    }
}
