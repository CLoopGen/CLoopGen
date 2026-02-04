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


struct moyo_data {
    int number;
    int segmentation[400];
    int size[361];
    int owner[361];
    float territorial_value[361];
};


extern  struct influence_data *q;
extern struct moyo_data *moyos;
extern int min_moyo_id;
extern int max_moyo_id;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = min_moyo_id; i <= max_moyo_id; i++) {
    int index = i - min_moyo_id + 1;
    int type_flag = q->region_type[i] & 1;
    moyos->size[index] = q->region_size[i];
    moyos->territorial_value[index] = q->region_territorial_value[i];
    moyos->owner[index] = type_flag ? 2 : 1;
}
}
