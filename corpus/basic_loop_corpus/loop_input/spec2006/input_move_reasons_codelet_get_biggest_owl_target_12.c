#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

#define DRAGON_SIZE 400
#define MOVE_SIZE 400
#define MOVE_REASONS_SIZE 1000

struct dragon_data dragon[DRAGON_SIZE];
struct move_data move[MOVE_SIZE];
struct move_reason move_reasons[MOVE_REASONS_SIZE];

int pos = 0;
int k = 0;
int biggest_target = 0;
float target_size = 0.0f;

void init_vars() {
    for (int i = 0; i < DRAGON_SIZE; i++) {
        dragon[i].color = rand() % 5;
        dragon[i].id = i;
        dragon[i].origin = rand() % 100;
        dragon[i].size = rand() % 200;
        dragon[i].effective_size = (float)(rand() % 1000) / 10.0f;
        dragon[i].crude_status = rand() % 3;
        dragon[i].owl_threat_status = rand() % 2;
        dragon[i].owl_status = rand() % 2;
        dragon[i].owl_attack_point = rand() % 20;
        dragon[i].owl_attack_code = rand() % 5;
        dragon[i].owl_attack_certain = rand() % 2;
        dragon[i].owl_second_attack_point = rand() % 20;
        dragon[i].owl_defense_point = rand() % 20;
        dragon[i].owl_defense_code = rand() % 5;
        dragon[i].owl_defense_certain = rand() % 2;
        dragon[i].owl_second_defense_point = rand() % 20;
        dragon[i].status = rand() % 3;
        dragon[i].owl_attack_kworm = rand() % 2;
        dragon[i].owl_defense_kworm = rand() % 2;
    }

    for (int i = 0; i < MOVE_SIZE; i++) {
        move[i].value = (float)(rand() % 1000) / 10.0f;
        move[i].final_value = (float)(rand() % 1000) / 10.0f;
        move[i].additional_ko_value = (float)(rand() % 500) / 10.0f;
        move[i].territorial_value = (float)(rand() % 800) / 10.0f;
        move[i].strategical_value = (float)(rand() % 800) / 10.0f;
        move[i].maxpos_shape = (float)(rand() % 200) / 10.0f;
        move[i].maxneg_shape = -(float)(rand() % 200) / 10.0f;
        move[i].numpos_shape = rand() % 10;
        move[i].numneg_shape = rand() % 10;
        move[i].followup_value = (float)(rand() % 700) / 10.0f;
        move[i].influence_followup_value = (float)(rand() % 700) / 10.0f;
        move[i].reverse_followup_value = (float)(rand() % 700) / 10.0f;
        move[i].secondary_value = (float)(rand() % 600) / 10.0f;
        move[i].min_value = (float)(rand() % 300) / 10.0f;
        move[i].max_value = (float)(rand() % 900) / 10.0f;
        move[i].min_territory = (float)(rand() % 400) / 10.0f;
        move[i].max_territory = (float)(rand() % 600) / 10.0f;
        move[i].randomness_scaling = (float)(rand() % 200) / 100.0f;
        for (int j = 0; j < 120; j++) {
            if (j < 50) {
                move[i].reason[j] = rand() % MOVE_REASONS_SIZE;
            } else {
                move[i].reason[j] = -1;
            }
        }
        move[i].move_safety = rand() % 2;
        move[i].worthwhile_threat = rand() % 2;
        move[i].random_number = (float)rand() / RAND_MAX;
    }

    for (int i = 0; i < MOVE_REASONS_SIZE; i++) {
        int type_choice = rand() % 10;
        switch (type_choice) {
            case 0: move_reasons[i].type = 26; break;
            case 1: move_reasons[i].type = 28; break;
            case 2: move_reasons[i].type = 30; break;
            case 3: move_reasons[i].type = 26 | 1; break;
            case 4: move_reasons[i].type = 32; break;
            case 5: move_reasons[i].type = 34; break;
            case 6: move_reasons[i].type = 36; break;
            case 7: move_reasons[i].type = 32 | 1; break;
            case 8: move_reasons[i].type = 38; break;
            default: move_reasons[i].type = rand() % 50; break;
        }
        move_reasons[i].what = rand() % DRAGON_SIZE;
        move_reasons[i].status = rand() % 3;
    }

    pos = rand() % MOVE_SIZE;
    biggest_target = 0;
    target_size = 0.0f;
}