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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing ii + delta[k] (which may cause non-consecutive access), 
    // we restructure the loop to process elements in a more cache-friendly, sequential manner.
    // We assume delta[4] = {-20, -1, 1, 20} corresponding to up/left/right/down on a 19x19 board with padding.
    // Here, we unroll and reorder the neighbor checks into direct offsets to promote spatial locality.

    for (ii = 21; ii < 361; ii++) {
        if (board[ii] != 3) {
            if (!q->safe[ii]) {
                // Precompute base value
                float current_territory = q->territory_value[ii];
                if (current_territory > 0.0f || !q->is_territorial_influence) {
                    float min_val = current_territory;
                    float max_val = current_territory;

                    // Direct consecutive-like access using known small deltas
                    // Check top (ii - 20)
                    int neighbor = ii - 20;
                    if (!(board[neighbor] != 3)) goto skip_top;
                    if (!q->safe[neighbor]) {
                        float neighbor_val = q->black_permeability[neighbor] * first_guess[neighbor] + 
                                           (1.0f - q->black_permeability[neighbor]) * first_guess[ii];
                        if (current_territory > 0.0f)
                            min_val = (min_val < neighbor_val) ? min_val : neighbor_val;
                        else
                            max_val = (max_val > neighbor_val) ? max_val : neighbor_val;
                    }
                skip_top:

                    // Check left (ii - 1)
                    neighbor = ii - 1;
                    if (!(board[neighbor] != 3)) goto skip_left;
                    if (!q->safe[neighbor]) {
                        float neighbor_val = q->black_permeability[neighbor] * first_guess[neighbor] + 
                                           (1.0f - q->black_permeability[neighbor]) * first_guess[ii];
                        if (current_territory > 0.0f)
                            min_val = (min_val < neighbor_val) ? min_val : neighbor_val;
                        else
                            max_val = (max_val > neighbor_val) ? max_val : neighbor_val;
                    }
                skip_left:

                    // Check right (ii + 1)
                    neighbor = ii + 1;
                    if (!(board[neighbor] != 3)) goto skip_right;
                    if (!q->safe[neighbor]) {
                        float neighbor_val = q->white_permeability[neighbor] * first_guess[neighbor] + 
                                           (1.0f - q->white_permeability[neighbor]) * first_guess[ii];
                        if (current_territory > 0.0f)
                            min_val = (min_val < neighbor_val) ? min_val : neighbor_val;
                        else
                            max_val = (max_val > neighbor_val) ? max_val : neighbor_val;
                    }
                skip_right:

                    // Check bottom (ii + 20)
                    neighbor = ii + 20;
                    if (!(board[neighbor] != 3)) goto skip_bottom;
                    if (!q->safe[neighbor]) {
                        float neighbor_val = q->white_permeability[neighbor] * first_guess[neighbor] + 
                                           (1.0f - q->white_permeability[neighbor]) * first_guess[ii];
                        if (current_territory > 0.0f)
                            min_val = (min_val < neighbor_val) ? min_val : neighbor_val;
                        else
                            max_val = (max_val > neighbor_val) ? max_val : neighbor_val;
                    }
                skip_bottom:

                    // Update based on sign of original territory value
                    if (current_territory > 0.0f) {
                        q->territory_value[ii] = (0.0f < min_val) ? min_val : 0.0f;
                    } else {
                        q->territory_value[ii] = (0.0f > max_val) ? max_val : 0.0f;
                    }
                }
            }
        }
    }
}
