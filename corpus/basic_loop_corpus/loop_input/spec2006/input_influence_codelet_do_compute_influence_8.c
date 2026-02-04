#include <stdio.h>
#include <inttypes.h>
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

struct influence_data *q;
int ii;
int int_white_influence[400];
int int_black_influence[400];

void init_vars() {
    q = (struct influence_data*)malloc(sizeof(struct influence_data));
    if (!q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(q->safe, 0, sizeof(q->safe));
    memset(q->white_influence, 0, sizeof(q->white_influence));
    memset(q->black_influence, 0, sizeof(q->black_influence));
    memset(q->white_strength, 0, sizeof(q->white_strength));
    memset(q->black_strength, 0, sizeof(q->black_strength));
    memset(q->white_attenuation, 0, sizeof(q->white_attenuation));
    memset(q->black_attenuation, 0, sizeof(q->black_attenuation));
    memset(q->white_permeability, 0, sizeof(q->white_permeability));
    memset(q->black_permeability, 0, sizeof(q->black_permeability));
    memset(q->territory_segmentation, 0, sizeof(q->territory_segmentation));
    memset(q->moyo_segmentation, 0, sizeof(q->moyo_segmentation));
    memset(q->area_segmentation, 0, sizeof(q->area_segmentation));
    memset(q->region_type, 0, sizeof(q->region_type));
    memset(q->region_size, 0, sizeof(q->region_size));
    memset(q->region_territorial_value, 0, sizeof(q->region_territorial_value));
    memset(q->territory_value, 0, sizeof(q->territory_value));
    memset(q->non_territory, 0, sizeof(q->non_territory));
    memset(q->queue, 0, sizeof(q->queue));
    memset(q->intrusions, 0, sizeof(q->intrusions));

    q->number_of_regions = 0;
    q->is_territorial_influence = 0;
    q->captured = 0;
    q->color_to_move = 0;
    q->intrusion_counter = 0;

    for (int i = 0; i < 400; i++) {
        int_white_influence[i] = rand() % 8192;
        int_black_influence[i] = rand() % 8192;
    }

    ii = 0;
}