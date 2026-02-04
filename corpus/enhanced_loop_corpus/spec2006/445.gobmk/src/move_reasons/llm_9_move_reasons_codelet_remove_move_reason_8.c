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
    int limit = (move[pos].numpos_shape + move[pos].numneg_shape) % 120;
    if (limit == 0) limit = 60;
    n = -1;
    for (k = 0; k < limit && k < 120; k++) {
        int r = move[pos].reason[k];
        if (r < 0) continue;
        float penalty = (move_reasons[r].status == 0) ? 1.5f : 1.0f;
        float adjusted_value = move[pos].value * penalty;
        if (move_reasons[r].type == type && move_reasons[r].what == what && adjusted_value > 0.1f)
            n = k;
    }
    if (n == -1) n = 0;
}
