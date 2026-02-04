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
    int offset = 1 - min_moyo_id;
    for (i = min_moyo_id; i <= max_moyo_id; i += 2) {
        int j = i + 1;
        int idx1 = i + offset;
        int idx2 = j + offset;

        moyos->size[idx1] = q->region_size[i];
        moyos->territorial_value[idx1] = q->region_territorial_value[i];
        moyos->owner[idx1] = (q->region_type[i] & 1) ? 2 : 1;

        if (j <= max_moyo_id) {
            moyos->size[idx2] = q->region_size[j];
            moyos->territorial_value[idx2] = q->region_territorial_value[j];
            moyos->owner[idx2] = (q->region_type[j] & 1) ? 2 : 1;
        }
    }
    if ((max_moyo_id - min_moyo_id + 1) % 2 == 1) {
        int last_idx = max_moyo_id - min_moyo_id + 1;
        int i_last = max_moyo_id;
        moyos->size[last_idx] = q->region_size[i_last];
        moyos->territorial_value[last_idx] = q->region_territorial_value[i_last];
        moyos->owner[last_idx] = (q->region_type[i_last] & 1) ? 2 : 1;
    }
}
