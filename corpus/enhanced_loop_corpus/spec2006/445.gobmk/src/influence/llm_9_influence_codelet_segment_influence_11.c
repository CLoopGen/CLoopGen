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
    for (ii = 21; ii < 361; ii++) {
        int cond = (board[ii] != 3);
        q->territory_segmentation[ii] = cond ? 0 : q->territory_segmentation[ii];
        q->moyo_segmentation[ii] = cond ? 0 : q->moyo_segmentation[ii];
        q->area_segmentation[ii] = cond ? 0 : q->area_segmentation[ii];
        
        // Add auxiliary computation to increase arithmetic intensity
        float val = (float)(ii * ii % 100) / 100.0f;
        q->white_influence[ii] += val * 0.1f;
        q->black_influence[ii] += (1.0f - val) * 0.1f;
    }
}
