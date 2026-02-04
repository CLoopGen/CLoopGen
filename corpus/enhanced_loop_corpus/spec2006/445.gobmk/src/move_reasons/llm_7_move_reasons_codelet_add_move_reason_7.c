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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_type = type;  // Introduce local copy to eliminate potential WAW hazard on shared 'type'
    int local_what = what;
    int match_index = -1;

    // Transform into counting loop with no early exit, eliminating loop-carried control dependency
    for (k = 0; k < 120; k++) {
        int r = move[pos].reason[k];
        if (r >= 0 && move_reasons[r].type == local_type && move_reasons[r].what == local_what) {
            match_index = k;  // Write-after-write dependency on match_index resolved via last-write semantics
        }
        // Maintain RAW: each iteration depends on r and move_reasons[r] before updating match_index
    }

    // Single return after loop to preserve original semantics without loop-external exits
    if (match_index != -1) {
        return;
    }
}
