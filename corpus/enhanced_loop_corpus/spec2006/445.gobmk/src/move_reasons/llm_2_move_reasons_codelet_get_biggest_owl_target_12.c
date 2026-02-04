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
    for (k = 0; k < 120; k += 4) {
        int r0 = move[pos].reason[k];
        int r1 = (k + 1 < 120) ? move[pos].reason[k + 1] : -1;
        int r2 = (k + 2 < 120) ? move[pos].reason[k + 2] : -1;
        int r3 = (k + 3 < 120) ? move[pos].reason[k + 3] : -1;

        if (r0 >= 0) {
            switch (move_reasons[r0].type) {
              case 26:
              case 28:
              case 30:
              case (26 | 1):
              case 32:
              case 34:
              case 36:
              case (32 | 1):
              case 38:
                if (dragon[move_reasons[r0].what].effective_size > target_size) {
                    biggest_target = move_reasons[r0].what;
                    target_size = dragon[move_reasons[r0].what].effective_size;
                }
                break;
            }
        }

        if (r1 >= 0) {
            switch (move_reasons[r1].type) {
              case 26:
              case 28:
              case 30:
              case (26 | 1):
              case 32:
              case 34:
              case 36:
              case (32 | 1):
              case 38:
                if (dragon[move_reasons[r1].what].effective_size > target_size) {
                    biggest_target = move_reasons[r1].what;
                    target_size = dragon[move_reasons[r1].what].effective_size;
                }
                break;
            }
        }

        if (r2 >= 0) {
            switch (move_reasons[r2].type) {
              case 26:
              case 28:
              case 30:
              case (26 | 1):
              case 32:
              case 34:
              case 36:
              case (32 | 1):
              case 38:
                if (dragon[move_reasons[r2].what].effective_size > target_size) {
                    biggest_target = move_reasons[r2].what;
                    target_size = dragon[move_reasons[r2].what].effective_size;
                }
                break;
            }
        }

        if (r3 >= 0) {
            switch (move_reasons[r3].type) {
              case 26:
              case 28:
              case 30:
              case (26 | 1):
              case 32:
              case 34:
              case 36:
              case (32 | 1):
              case 38:
                if (dragon[move_reasons[r3].what].effective_size > target_size) {
                    biggest_target = move_reasons[r3].what;
                    target_size = dragon[move_reasons[r3].what].effective_size;
                }
                break;
            }
        }

        if (r0 < 0 && r1 < 0 && r2 < 0 && r3 < 0)
            break;
    }
}
