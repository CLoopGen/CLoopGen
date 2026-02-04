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
    for (k = 0; k < 60; k++) {
        int r1 = move[pos].reason[k];
        int r2 = move[pos].reason[k + 60];
        if (r1 >= 0) {
            if (move_reasons[r1].type == (8 | 1))
                strings[num_strings++] = move_reasons[r1].what;
            if (num_strings == max_strings)
                break;
        }
        if (r2 >= 0) {
            if (move_reasons[r2].type == (8 | 1))
                strings[num_strings++] = move_reasons[r2].what;
            if (num_strings == max_strings)
                break;
        }
    }
}
