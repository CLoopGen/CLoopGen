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
extern struct influence_data *q;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int end = 361;
    for (ii = start; ii < end; ii += 2) {
        if ((board[ii] != 3) && (ii % 19 < 17)) {
            q->territory_segmentation[ii] = 0;
            q->moyo_segmentation[ii] = 0;
            q->area_segmentation[ii] = 0;
            q->territory_value[ii] = 0.0f;
            q->non_territory[ii] = 1;
        }
    }
}
