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


typedef unsigned char Intersection;

extern struct influence_data *q;
extern  char safe_stones[400];
extern  float strength[400];
extern int ii;
extern float attenuation;
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if (board[ii] != 3) {
            q->white_influence[ii] = 0.;
            q->black_influence[ii] = 0.;
            q->white_attenuation[ii] = attenuation;
            q->black_attenuation[ii] = attenuation;
            q->white_permeability[ii] = 1.;
            q->black_permeability[ii] = 1.;
            q->white_strength[ii] = 0.;
            q->black_strength[ii] = 0.;
            q->non_territory[ii] = 0;

            if ((board[ii] == 1 || board[ii] == 2) && safe_stones[ii]) {
                if (board[ii] == 1) {
                    q->white_strength[ii] = strength ? strength[ii] : 100.;
                    q->black_permeability[ii] = 0.;
                } else {
                    q->black_strength[ii] = strength ? strength[ii] : 100.;
                    q->white_permeability[ii] = 0.;
                }
            } else if (board[ii] == 1 || board[ii] == 2) {
                if (board[ii] == 1)
                    q->white_permeability[ii] = 0.;
                else
                    q->black_permeability[ii] = 0.;
            } else {
                q->safe[ii] = 0;
            }
        }
    }
}
