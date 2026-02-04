#include <stdio.h>

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


extern struct influence_data *q;
extern int ii;
extern int int_white_influence[400];
extern int int_black_influence[400];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
    q->white_influence[ii] = (((float)(int_white_influence[ii])) / (1 << 12));
    q->black_influence[ii] = (((float)(int_black_influence[ii])) / (1 << 12));
}

}
