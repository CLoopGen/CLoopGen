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



void loop() {
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to use strided iteration over the board,
    // processing every 2nd or 4th element first, then filling in gaps.
    // This helps expose memory-level parallelism and can improve prefetching.

    // First pass: even indices
    for (ii = 21; ii < 361; ii += 2) {
        if (board[ii] != 3 && !q->safe[ii]) {
            float tv = q->territory_value[ii];
            int updated = 0;
            float result_val = tv;

            for (k = 0; k < 4; k++) {
                int nb = ii + delta[k];
                if (board[nb] == 3) continue;
                if (q->safe[nb]) continue;

                float neighbor_val;
                if (tv > 0.0f) {
                    neighbor_val = q->black_permeability[nb] * first_guess[nb] + 
                                  (1.0f - q->black_permeability[nb]) * first_guess[ii];
                    result_val = (result_val < neighbor_val) ? result_val : neighbor_val;
                } else {
                    neighbor_val = q->white_permeability[nb] * first_guess[nb] + 
                                  (1.0f - q->white_permeability[nb]) * first_guess[ii];
                    result_val = (result_val > neighbor_val) ? result_val : neighbor_val;
                }
                updated = 1;
            }

            if (updated) {
                q->territory_value[ii] = (0.0f < result_val) ? ((tv > 0.0f) ? result_val : ((0.0f > result_val) ? result_val : 0.0f)) : 0.0f;
            }
        }
    }

    // Second pass: odd indices
    for (ii = 22; ii < 361; ii += 2) {
        if (board[ii] != 3 && !q->safe[ii]) {
            float tv = q->territory_value[ii];
            int updated = 0;
            float result_val = tv;

            for (k = 0; k < 4; k++) {
                int nb = ii + delta[k];
                if (board[nb] == 3) continue;
                if (q->safe[nb]) continue;

                float neighbor_val;
                if (tv > 0.0f) {
                    neighbor_val = q->black_permeability[nb] * first_guess[nb] + 
                                  (1.0f - q->black_permeability[nb]) * first_guess[ii];
                    result_val = (result_val < neighbor_val) ? result_val : neighbor_val;
                } else {
                    neighbor_val = q->white_permeability[nb] * first_guess[nb] + 
                                  (1.0f - q->white_permeability[nb]) * first_guess[ii];
                    result_val = (result_val > neighbor_val) ? result_val : neighbor_val;
                }
                updated = 1;
            }

            if (updated) {
                q->territory_value[ii] = (0.0f < result_val) ? ((tv > 0.0f) ? result_val : ((0.0f > result_val) ? result_val : 0.0f)) : 0.0f;
            }
        }
    }
}
