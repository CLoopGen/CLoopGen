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
extern int int_white_permeabilities[400];
extern int int_black_permeabilities[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (blocked) memory access with loop unrolling for spatial locality
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int i;
    // Align start to multiple of 4 for unrolling
    for (i = start; i + 3 < end; i += 4) {
        int_white_permeabilities[i]   = ((int)((q->white_permeability[i])   * (1 << 12)) + 0.5);
        int_black_permeabilities[i]   = ((int)((q->black_permeability[i])   * (1 << 12)) + 0.5);
        int_white_permeabilities[i+1] = ((int)((q->white_permeability[i+1]) * (1 << 12)) + 0.5);
        int_black_permeabilities[i+1] = ((int)((q->black_permeability[i+1]) * (1 << 12)) + 0.5);
        int_white_permeabilities[i+2] = ((int)((q->white_permeability[i+2]) * (1 << 12)) + 0.5);
        int_black_permeabilities[i+2] = ((int)((q->black_permeability[i+2]) * (1 << 12)) + 0.5);
        int_white_permeabilities[i+3] = ((int)((q->white_permeability[i+3]) * (1 << 12)) + 0.5);
        int_black_permeabilities[i+3] = ((int)((q->black_permeability[i+3]) * (1 << 12)) + 0.5);
    }
    // Handle remaining elements
    for (; i < end; i++) {
        int_white_permeabilities[i] = ((int)((q->white_permeability[i]) * (1 << 12)) + 0.5);
        int_black_permeabilities[i] = ((int)((q->black_permeability[i]) * (1 << 12)) + 0.5);
    }
}
