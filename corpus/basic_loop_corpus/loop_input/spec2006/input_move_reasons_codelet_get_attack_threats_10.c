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

#define MOVE_ARRAY_SIZE 400
#define MOVE_REASONS_SIZE 1000
#define STRINGS_ARRAY_SIZE 256000

struct move_data move[MOVE_ARRAY_SIZE];
struct move_reason move_reasons[MOVE_REASONS_SIZE];
int pos = 399; // point to a valid index in move[]
int max_strings = STRINGS_ARRAY_SIZE;
int strings[STRINGS_ARRAY_SIZE];
int k;
int num_strings;

void init_vars() {
    // Initialize move array
    for (int i = 0; i < MOVE_ARRAY_SIZE; i++) {
        move[i].value = 0.0f;
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
        move[i].move_safety = 0;
        move[i].worthwhile_threat = 0;
        move[i].random_number = 0.0f;
        
        // Initialize reason array: fill with valid indices or -1 at end
        for (int j = 0; j < 120; j++) {
            if (j < 60) {
                move[i].reason[j] = j * 2 + i % 10; // map to valid move_reasons index
            } else {
                move[i].reason[j] = -1; // terminate early in loop
            }
        }
    }

    // Initialize move_reasons
    for (int i = 0; i < MOVE_REASONS_SIZE; i++) {
        move_reasons[i].type = (i % 3 == 0) ? (2 | 1) : (i % 5); // ensure some match (2|1)
        move_reasons[i].what = i * 3;
        move_reasons[i].status = 1;
    }

    // Initialize control variables
    pos = 399; // valid index in move[] array
    max_strings = STRINGS_ARRAY_SIZE;
    num_strings = 0;
    k = 0;
}