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

Intersection board[421];
struct move_data move[400];
int target;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? ((i % 4) + 1) : 0;
    }
    for (int i = 0; i < 400; i++) {
        move[i].value = (float)(i * 0.5f);
        move[i].final_value = 0.0f;
        move[i].additional_ko_value = 0.0f;
        move[i].territorial_value = 0.0f;
        move[i].strategical_value = 0.0f;
        move[i].maxpos_shape = 0.0f;
        move[i].maxneg_shape = 0.0f;
        move[i].numpos_shape = 0;
        move[i].numneg_shape = 0;
        move[i].followup_value = 0.0f;
        move[i].influence_followup_value = 0.0f;
        move[i].reverse_followup_value = 0.0f;
        move[i].secondary_value = 0.0f;
        move[i].min_value = 0.0f;
        move[i].max_value = 0.0f;
        move[i].min_territory = 0.0f;
        move[i].max_territory = 0.0f;
        move[i].randomness_scaling = 1.0f;
        for (int j = 0; j < 120; j++) {
            move[i].reason[j] = 0;
        }
        move[i].move_safety = 0;
        move[i].worthwhile_threat = 0;
        move[i].random_number = 0.0f;
    }
    target = 0;
}