#include <stdio.h>

#include <inttypes.h>

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


extern Intersection board[421];
extern  struct influence_data *q;
extern int ii;
extern int min_moyo_id;
extern int max_moyo_id;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index remapping using a precomputed access pattern
    int indices[400];
    int count = 0;
    for (int temp_idx = (19 + 2); temp_idx < (19 + 1) * (19 + 1); ++temp_idx) {
        indices[count++] = temp_idx;
    }
    for (int idx = 0; idx < count; ++idx) {
        int i = indices[idx]; // Indirect access through index array
        if ((board[i] != 3)) {
            if (q->moyo_segmentation[i] != 0) {
                min_moyo_id = ((min_moyo_id) < (q->moyo_segmentation[i]) ? (min_moyo_id) : (q->moyo_segmentation[i]));
                max_moyo_id = ((max_moyo_id) < (q->moyo_segmentation[i]) ? (q->moyo_segmentation[i]) : (max_moyo_id));
            }
        }
    }
}
