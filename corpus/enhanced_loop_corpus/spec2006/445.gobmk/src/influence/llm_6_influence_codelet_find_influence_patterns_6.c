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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if ((board[ii] != 3) && q->safe[ii]) {
            int k;
            float temp_white[8] = {0};
            float temp_black[8] = {0};
            int update_flag[8] = {0};
            for (k = 0; k < 8; k++) {
                int d = delta[k];
                if ((board[ii + d] != 3) && !q->safe[ii + d]) {
                    float reduction = (k < 4) ? 0.25 : 0.65000000000000002;
                    if (board[ii] == 2) {
                        temp_white[k] = q->white_permeability[ii + d] * reduction;
                        update_flag[k] = 1;
                    } else {
                        temp_black[k] = q->black_permeability[ii + d] * reduction;
                        update_flag[k] = 1;
                    }
                }
            }
            for (k = 0; k < 8; k++) {
                if (update_flag[k]) {
                    int d = delta[k];
                    if (board[ii] == 2)
                        q->white_permeability[ii + d] = temp_white[k];
                    else
                        q->black_permeability[ii + d] = temp_black[k];
                }
            }
        }
    }
}
