#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

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

Intersection board[421];
struct influence_data *q;
int ii;

void init_vars() {
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? ((rand() % 3) + 1) : 3;
    }

    q = (struct influence_data*)calloc(1, sizeof(struct influence_data));
    if (!q) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    q->number_of_regions = 100;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 1;
    q->intrusion_counter = 0;

    for (int i = 0; i < 400; i++) {
        q->territory_segmentation[i] = i % 5;
        q->moyo_segmentation[i] = i % 4;
        q->area_segmentation[i] = i % 3;
        q->territory_value[i] = (float)(rand()) / RAND_MAX;
        q->non_territory[i] = rand() % 2;
        q->white_influence[i] = (float)(rand()) / RAND_MAX;
        q->black_influence[i] = (float)(rand()) / RAND_MAX;
        q->white_strength[i] = (float)(rand()) / RAND_MAX;
        q->black_strength[i] = (float)(rand()) / RAND_MAX;
        q->white_attenuation[i] = 0.8f + ((float)(rand()) / RAND_MAX) * 0.2f;
        q->black_attenuation[i] = 0.8f + ((float)(rand()) / RAND_MAX) * 0.2f;
        q->white_permeability[i] = (float)(rand()) / RAND_MAX;
        q->black_permeability[i] = (float)(rand()) / RAND_MAX;
    }

    for (int i = 0; i < 1084; i++) {
        q->region_type[i] = i % 4;
        q->region_size[i] = (i + 1) * 2;
        q->region_territorial_value[i] = (float)(rand()) / RAND_MAX;
    }

    for (int i = 0; i < 361; i++) {
        q->queue[i] = rand() % 400;
    }

    for (int i = 0; i < 722; i++) {
        q->intrusions[i].source_pos = rand() % 400;
        q->intrusions[i].strength_pos = rand() % 400;
        q->intrusions[i].strength = (float)(rand()) / RAND_MAX;
        q->intrusions[i].attenuation = 0.5f + ((float)(rand()) / RAND_MAX) * 0.5f;
    }

    ii = 0;
}