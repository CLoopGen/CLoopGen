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

#define MOVE_SIZE 400
#define MOVE_REASONS_SIZE 1000

struct move_data move[MOVE_SIZE];
struct move_reason move_reasons[MOVE_REASONS_SIZE];
int pos = 0;
int type = 0;
int what = 0;
int k = 0;

void init_vars() {
    // Seed for reproducible randomness
    srand(time(NULL));

    // Initialize all move entries
    for (int i = 0; i < MOVE_SIZE; i++) {
        struct move_data* m = &move[i];
        m->value = rand() / (float)RAND_MAX;
        m->final_value = rand() / (float)RAND_MAX;
        m->additional_ko_value = rand() / (float)RAND_MAX;
        m->territorial_value = rand() / (float)RAND_MAX;
        m->strategical_value = rand() / (float)RAND_MAX;
        m->maxpos_shape = rand() / (float)RAND_MAX;
        m->maxneg_shape = rand() / (float)RAND_MAX;
        m->numpos_shape = rand() % 10;
        m->numneg_shape = rand() % 10;
        m->followup_value = rand() / (float)RAND_MAX;
        m->influence_followup_value = rand() / (float)RAND_MAX;
        m->reverse_followup_value = rand() / (float)RAND_MAX;
        m->secondary_value = rand() / (float)RAND_MAX;
        m->min_value = rand() / (float)RAND_MAX;
        m->max_value = rand() / (float)RAND_MAX;
        m->min_territory = rand() / (float)RAND_MAX;
        m->max_territory = rand() / (float)RAND_MAX;
        m->randomness_scaling = rand() / (float)RAND_MAX;
        m->move_safety = rand() % 2;
        m->worthwhile_threat = rand() % 2;
        m->random_number = rand() / (float)RAND_MAX;

        // Initialize reason array with valid indices or -1
        int num_reasons = rand() % 120;
        for (int j = 0; j < 120; j++) {
            if (j < num_reasons) {
                m->reason[j] = rand() % MOVE_REASONS_SIZE;
            } else {
                m->reason[j] = -1;
            }
        }
    }

    // Initialize move_reasons
    for (int i = 0; i < MOVE_REASONS_SIZE; i++) {
        move_reasons[i].type = rand() % 50;
        move_reasons[i].what = rand() % 50;
        move_reasons[i].status = rand() % 3;
    }

    // Set initial values for loop variables to ensure valid access
    pos = rand() % MOVE_SIZE;
    type = move_reasons[rand() % MOVE_REASONS_SIZE].type;
    what = move_reasons[rand() % MOVE_REASONS_SIZE].what;
}