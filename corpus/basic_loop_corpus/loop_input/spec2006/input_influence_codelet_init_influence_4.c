#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

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
char safe_stones[400];
float strength[400];
int ii;
float attenuation;
unsigned char board[421];

void init_vars() {
    q = (struct influence_data*)calloc(1, sizeof(struct influence_data));
    if (!q) exit(1);

    attenuation = 0.5f;

    for (int i = 0; i < 400; i++) {
        safe_stones[i] = (i % 2);
        strength[i] = 50.0f + (i % 50);
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4); 
    }

    ii = 0;
}