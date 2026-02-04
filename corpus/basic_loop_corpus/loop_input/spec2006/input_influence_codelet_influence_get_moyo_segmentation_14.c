#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intrusion_data {
    int source_pos;
    int strength_pos;
    float strength;
    float attenuation;
};

struct influence_data {
    char safe[400];
    float white_influence[400];
    float black_influence[400];
    float white_strength[400];
    float black_strength[400];
    float white_attenuation[400];
    float black_attenuation[400];
    float white_permeability[400];
    float black_permeability[400];
    int territory_segmentation[400];
    int moyo_segmentation[400];
    int area_segmentation[400];
    int region_type[1084];
    int region_size[1084];
    float region_territorial_value[1084];
    int number_of_regions;
    int is_territorial_influence;
    float territory_value[400];
    int non_territory[400];
    int captured;
    int color_to_move;
    int queue[361];
    int intrusion_counter;
    struct intrusion_data intrusions[722];
};

struct moyo_data {
    int number;
    int segmentation[400];
    int size[361];
    int owner[361];
    float territorial_value[361];
};

struct influence_data *q;
struct moyo_data *moyos;
int min_moyo_id;
int max_moyo_id;
int i;

void init_vars() {
    q = (struct influence_data *)calloc(1, sizeof(struct influence_data));
    moyos = (struct moyo_data *)calloc(1, sizeof(struct moyo_data));

    min_moyo_id = 100;
    max_moyo_id = 360;

    for (int idx = 0; idx < 1084; idx++) {
        q->region_size[idx] = idx * 2;
        q->region_territorial_value[idx] = idx * 0.5f;
        q->region_type[idx] = (idx % 2) ? 1 : 0;
    }

    for (int idx = 0; idx < 400; idx++) {
        q->safe[idx] = (char)(idx % 127);
        q->white_influence[idx] = idx * 0.1f;
        q->black_influence[idx] = idx * 0.1f;
        q->white_strength[idx] = idx * 0.2f;
        q->black_strength[idx] = idx * 0.2f;
        q->white_attenuation[idx] = 0.5f;
        q->black_attenuation[idx] = 0.5f;
        q->white_permeability[idx] = 0.3f;
        q->black_permeability[idx] = 0.3f;
        q->territory_segmentation[idx] = idx;
        q->moyo_segmentation[idx] = idx;
        q->area_segmentation[idx] = idx;
        q->territory_value[idx] = idx * 0.1f;
        q->non_territory[idx] = 0;
    }

    for (int idx = 0; idx < 361; idx++) {
        q->queue[idx] = idx;
    }

    for (int idx = 0; idx < 722; idx++) {
        q->intrusions[idx].source_pos = idx;
        q->intrusions[idx].strength_pos = idx;
        q->intrusions[idx].strength = idx * 0.1f;
        q->intrusions[idx].attenuation = 0.7f;
    }

    q->number_of_regions = 1084;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 1;

    moyos->number = max_moyo_id - min_moyo_id + 1;

    for (int idx = 0; idx < 400; idx++) {
        moyos->segmentation[idx] = idx;
    }

    for (int idx = 0; idx < 361; idx++) {
        moyos->size[idx] = 0;
        moyos->owner[idx] = 0;
        moyos->territorial_value[idx] = 0.0f;
    }
}