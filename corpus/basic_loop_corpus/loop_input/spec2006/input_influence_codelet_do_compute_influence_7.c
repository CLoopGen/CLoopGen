#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

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
    float white_permeability_copy[400]; // extra to prevent overlap
    float black_permeability_copy[400]; // extra to prevent overlap
    float white_permeability_pad[321];  // padding to extend array size safely
    float black_permeability_pad[321]; // padding to extend array size safely
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
int int_white_permeabilities[400 + 321];
int int_black_permeabilities[400 + 321];

void init_vars() {
    q = (struct influence_data*)malloc(sizeof(struct influence_data));
    if (!q) exit(1);

    for (int i = 0; i < 400; i++) {
        q->white_permeability[i] = 0.25f + 0.5f * (i % 7) / 7.0f;
        q->black_permeability[i] = 0.25f + 0.5f * (i % 11) / 11.0f;
    }
    for (int i = 0; i < 321; i++) {
        q->white_permeability_pad[i] = 0.25f + 0.5f * ((i + 100) % 7) / 7.0f;
        q->black_permeability_pad[i] = 0.25f + 0.5f * ((i + 100) % 11) / 11.0f;
    }

    q->number_of_regions = 500;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 0;
    q->intrusion_counter = 0;

    for (int i = 0; i < 361; i++) {
        q->queue[i] = i;
    }

    for (int i = 0; i < 722; i++) {
        q->intrusions[i].source_pos = i % 361;
        q->intrusions[i].strength_pos = i % 400;
        q->intrusions[i].strength = 0.1f * (i % 10);
        q->intrusions[i].attenuation = 0.05f * (i % 20);
    }

    for (int i = 0; i < 400; i++) {
        q->territory_segmentation[i] = i % 5;
        q->moyo_segmentation[i] = i % 4;
        q->area_segmentation[i] = i % 3;
        q->territory_value[i] = 0.1f * (i % 10);
        q->non_territory[i] = i % 2;
    }

    for (int i = 0; i < 1084; i++) {
        q->region_type[i] = i % 10;
        q->region_size[i] = 10 + (i % 100);
        q->region_territorial_value[i] = 0.01f * (i % 1000);
    }

    for (int i = 0; i < 400; i++) {
        q->white_influence[i] = 0.1f * (i % 10);
        q->black_influence[i] = 0.1f * (i % 10);
        q->white_strength[i] = 0.2f * (i % 5);
        q->black_strength[i] = 0.2f * (i % 5);
        q->white_attenuation[i] = 0.05f * (i % 10);
        q->black_attenuation[i] = 0.05f * (i % 10);
    }

    for (int i = 0; i < 400; i++) {
        int_white_permeabilities[i] = 0;
        int_black_permeabilities[i] = 0;
    }
}