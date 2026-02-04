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

struct move_data move[MOVE_ARRAY_SIZE];
struct move_reason move_reasons[MOVE_REASONS_SIZE];
int pos = 0;
int type = 0;
int what = 0;
int k = 0;
int n = -1;

void init_vars() {
    for (int i = 0; i < MOVE_ARRAY_SIZE; i++) {
        struct move_data* m = &move[i];
        m->value = 0.0f;
        m->final_value = 0.0f;
        m->additional_ko_value = 0.0f;
        m->territorial_value = 0.0f;
        m->strategical_value = 0.0f;
        m->maxpos_shape = 0.0f;
        m->maxneg_shape = 0.0f;
        m->numpos_shape = 0;
        m->numneg_shape = 0;
        m->followup_value = 0.0f;
        m->influence_followup_value = 0.0f;
        m->reverse_followup_value = 0.0f;
        m->secondary_value = 0.0f;
        m->min_value = 0.0f;
        m->max_value = 0.0f;
        m->min_territory = 0.0f;
        m->max_territory = 0.0f;
        m->randomness_scaling = 1.0f;
        m->move_safety = 0;
        m->worthwhile_threat = 0;
        m->random_number = 0.0f;
        for (int j = 0; j < 120; j++) {
            m->reason[j] = (j < 50) ? j * 2 : -1;
        }
    }

    for (int i = 0; i < MOVE_REASONS_SIZE; i++) {
        struct move_reason* mr = &move_reasons[i];
        mr->type = i % 16;
        mr->what = i % 32;
        mr->status = 1;
    }

    pos = 0;
    type = 8;
    what = 16;
    k = 0;
    n = -1;
}