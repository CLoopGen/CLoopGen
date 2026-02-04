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
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
    if (board[ii] != 3 && !q->safe[ii]) {
        int has_effect = 0;
        for (k = 0; k < 4; k++) {
            int nb = ii + delta[k];
            if (board[nb] == 3 || q->safe[nb]) {
                continue;
            }
            has_effect = 1;
            break;
        }
        if (!has_effect) {
            continue;
        }
        for (k = 0; k < 4; k++) {
            int nb = ii + delta[k];
            if (board[nb] == 3) {
                continue;
            }
            if (!q->safe[nb]) {
                float val = first_guess[nb] * ((q->territory_value[ii] > 0.0) ? 
                            q->black_permeability[nb] : q->white_permeability[nb]) +
                           first_guess[ii] * (1.0 - ((q->territory_value[ii] > 0.0) ? 
                            q->black_permeability[nb] : q->white_permeability[nb]));
                if (q->territory_value[ii] > 0.0) {
                    float candidate = (q->territory_value[ii] < val) ? q->territory_value[ii] : val;
                    q->territory_value[ii] = (candidate > 0) ? candidate : 0;
                } else {
                    float candidate = (q->territory_value[ii] < val) ? val : q->territory_value[ii];
                    q->territory_value[ii] = (0 < candidate) ? 0 : candidate;
                }
            }
        }
    }
}
}
