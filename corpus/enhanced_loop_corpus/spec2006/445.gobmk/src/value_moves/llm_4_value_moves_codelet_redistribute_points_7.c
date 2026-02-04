#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

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


extern Intersection board[421];
extern struct move_data move[400];
extern int target;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (target = (19 + 2); target < (19 + 1) * (19 + 1); target++) {
        if (board[target] == 3) {
            continue;
        }
        move[target].final_value = move[target].value;
    }
}
