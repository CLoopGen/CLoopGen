#include <stdio.h>

#include <inttypes.h>

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};


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


extern struct dragon_data dragon[400];
extern struct move_data move[400];
extern struct move_reason move_reasons[1000];
extern int pos;
extern int k;
extern int biggest_target;
extern float target_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_target = biggest_target;
    float temp_size = target_size;
    for (k = 0; k < 120; k++) {
        int r = move[pos].reason[k];
        if (r < 0)
            continue; // Eliminate early exit to remove loop-carried control dependency

        int type = move_reasons[r].type;
        int what = move_reasons[r].what;
        float eff_size = dragon[what].effective_size; // Introduce local data reuse (RAW)

        // Combine conditions to increase data dependency chain
        int is_valid_type = ((type == 26) || (type == 28) || (type == 30) ||
                             (type == (26 | 1)) || (type == 32) || (type == 34) ||
                             (type == 36) || (type == (32 | 1)) || (type == 38));

        // Update conditionally but allow multiple updates (introduce WAR-like pattern via temporary)
        if (is_valid_type && eff_size > temp_size) {
            temp_size = eff_size;
            temp_target = what;
        }
    }
    // Final write-back to global state (WAW with original)
    biggest_target = temp_target;
    target_size = temp_size;
}
