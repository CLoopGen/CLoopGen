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


extern int delta[8];
extern Intersection board[421];
extern struct influence_data *q;
extern int ii;
extern float first_guess[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++)
    if ((board[ii] != 3)) {
        if (!q->safe[ii]) {
            for (k = 0; k < 4; k++) {
                if (!(board[ii + delta[k]] != 3))
                    continue;
                if (q->territory_value[ii] > 0.) {
                    if (!q->safe[ii + delta[k]]) {
                        float neighbor_val = q->black_permeability[ii + delta[k]] * first_guess[ii + delta[k]] + (1. - q->black_permeability[ii + delta[k]]) * first_guess[ii];
                        q->territory_value[ii] = ((0) < (((q->territory_value[ii]) < (neighbor_val) ? (q->territory_value[ii]) : (neighbor_val))) ? (((q->territory_value[ii]) < (neighbor_val) ? (q->territory_value[ii]) : (neighbor_val))) : (0));
                    }
                } else {
                    if (!q->safe[ii + delta[k]]) {
                        float neighbor_val = q->white_permeability[ii + delta[k]] * first_guess[ii + delta[k]] + (1 - q->white_permeability[ii + delta[k]]) * first_guess[ii];
                        q->territory_value[ii] = ((0) < (((q->territory_value[ii]) < (neighbor_val) ? (neighbor_val) : (q->territory_value[ii]))) ? (0) : (((q->territory_value[ii]) < (neighbor_val) ? (neighbor_val) : (q->territory_value[ii]))));
                    }
                }
            }
        }
    }

}
