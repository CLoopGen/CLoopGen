#include <stdio.h>
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
    float white_permeability_copy[400];
    float black_permeability_copy[400];
    float white_permeability_temp[400];
    float black_permeability_temp[400];
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

int delta[8] = { -21, -1, 21, 1, -20, -22, 20, 22 };
Intersection board[421];
struct influence_data *q;
int ii;

void init_vars() {
    q = (struct influence_data*)malloc(sizeof(struct influence_data));
    if (!q) return;

    memset(q, 0, sizeof(struct influence_data));

    for (int i = 0; i < 400; i++) {
        q->safe[i] = 1;
        q->white_permeability[i] = 1.0f;
        q->black_permeability[i] = 1.0f;
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400 + 21) ? 2 : 3;
    }

    for (int i = 0; i < 8; i++) {
        int d = delta[i];
        for (int j = 19 + 2; j < (19 + 1) * (19 + 1); j++) {
            if (j + d >= 0 && j + d < 421) {
                if ((j >= 21 && j < 400 + 21) && ((j + d) < 21 || (j + d) >= 400 + 21)) {
                    board[j] = 2;
                    q->safe[j] = 1;
                    q->safe[j + d] = 0;
                }
            }
        }
    }

    q->number_of_regions = 10;
    q->is_territorial_influence = 1;
    q->color_to_move = 2;
    q->intrusion_counter = 0;
}