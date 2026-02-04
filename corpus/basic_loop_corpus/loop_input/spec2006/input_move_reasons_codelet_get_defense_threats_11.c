#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int pos = 0;
int max_strings = STRINGS_ARRAY_SIZE;
int strings[STRINGS_ARRAY_SIZE];
int k = 0;
int num_strings = 0;

void init_vars() {
    // Initialize pos to a valid index in move[]
    pos = 13;  // arbitrary valid index within [0,399]

    // Initialize max_strings to actual array size
    max_strings = STRINGS_ARRAY_SIZE;

    // Reset counters
    num_strings = 0;
    k = 0;

    // Seed for pseudo-random initialization
    srand(time(NULL));

    // Initialize move array
    for (int i = 0; i < MOVE_ARRAY_SIZE; i++) {
        struct move_data* md = &move[i];
        md->value = rand() / (float)RAND_MAX;
        md->final_value = rand() / (float)RAND_MAX;
        md->additional_ko_value = rand() / (float)RAND_MAX;
        md->territorial_value = rand() / (float)RAND_MAX;
        md->strategical_value = rand() / (float)RAND_MAX;
        md->maxpos_shape = rand() / (float)RAND_MAX;
        md->maxneg_shape = rand() / (float)RAND_MAX;
        md->numpos_shape = rand() % 10;
        md->numneg_shape = rand() % 10;
        md->followup_value = rand() / (float)RAND_MAX;
        md->influence_followup_value = rand() / (float)RAND_MAX;
        md->reverse_followup_value = rand() / (float)RAND_MAX;
        md->secondary_value = rand() / (float)RAND_MAX;
        md->min_value = rand() / (float)RAND_MAX;
        md->max_value = rand() / (float)RAND_MAX;
        md->min_territory = rand() / (float)RAND_MAX;
        md->max_territory = rand() / (float)RAND_MAX;
        md->randomness_scaling = rand() / (float)RAND_MAX;
        md->move_safety = rand() % 2;
        md->worthwhile_threat = rand() % 2;
        md->random_number = rand() / (float)RAND_MAX;

        // Initialize reason[] array with valid indices or -1 terminators
        int num_reasons = rand() % 120;
        for (int j = 0; j < 120; j++) {
            if (j < num_reasons) {
                md->reason[j] = rand() % MOVE_REASONS_SIZE;
            } else {
                md->reason[j] = -1;
            }
        }
    }

    // Initialize move_reasons array
    for (int i = 0; i < MOVE_REASONS_SIZE; i++) {
        move_reasons[i].type = (i % 16);  // Ensure some entries match (8|1)=9
        move_reasons[i].what = i * 3;
        move_reasons[i].status = rand() % 3;
    }

    // Ensure at least some entries have type == 9 (8|1)
    for (int i = 0; i < MOVE_REASONS_SIZE; i += 23) {
        move_reasons[i].type = 9;
    }

    // Clear strings array
    memset(strings, 0, sizeof(strings));
}