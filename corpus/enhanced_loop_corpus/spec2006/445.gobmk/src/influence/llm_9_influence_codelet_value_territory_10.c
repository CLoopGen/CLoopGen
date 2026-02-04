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
int start = (19 + 2);
int end = (19 + 1) * (19 + 1);
int mid = (start + end) / 2;

for (ii = start; ii < end; ii++) {
    if ((board[ii] != 3) && !q->safe[ii]) {
        float *tv = &q->territory_value[ii];
        int nt = q->non_territory[ii];
        
        // Duplicate checks with slight arithmetic variation to increase intensity
        if (*tv > 0.001f) {
            if (nt & 1) *tv = 0.;
        } else if (*tv < -0.001f) {
            if (nt & 2) *tv = 0.;
        }

        // Apply influence adjustments with extra arithmetic
        float delta = (board[ii] == 2) ? 0.8f : (board[ii] == 1) ? -0.8f : 0.0f;
        *tv = (*tv * 0.95f) + delta; // Dampened update increases computation per iteration

        // Additional dummy operation to increase computational load
        q->white_influence[ii] += 0.01f * q->black_influence[ii];
    }
}
}
