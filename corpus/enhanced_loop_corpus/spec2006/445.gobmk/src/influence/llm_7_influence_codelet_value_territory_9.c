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
    // Eliminate loop-carried dependence by unrolling and reordering operations
    // Also introduce WAR dependency via speculative update with conditional rollback

    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1) - 4; ii += 4) { // Process 4 iterations at a time
        int indices[4] = {ii, ii+1, ii+2, ii+3};
        float speculative_update[4];
        char valid_update[4] = {0};

        for (int j = 0; j < 4; j++) {
            int curr_ii = indices[j];
            if (curr_ii >= (19 + 1) * (19 + 1)) break;

            if ((board[curr_ii] != 3) && !q->safe[curr_ii]) {
                speculative_update[j] = q->territory_value[curr_ii];
                valid_update[j] = 1;

                for (k = 0; k < 4; k++) {
                    int neighbor = curr_ii + delta[k];
                    if (!(board[neighbor] != 3)) continue;

                    if (q->territory_value[curr_ii] > 0.) {
                        if (!q->safe[neighbor]) {
                            float neighbor_val = q->black_permeability[neighbor] * first_guess[neighbor] + 
                                                (1. - q->black_permeability[neighbor]) * first_guess[curr_ii];
                            float min_val = (q->territory_value[curr_ii] < neighbor_val) ? q->territory_value[curr_ii] : neighbor_val;
                            speculative_update[j] = (0 < min_val) ? min_val : 0;
                        }
                    } else {
                        if (!q->safe[neighbor]) {
                            float neighbor_val = q->white_permeability[neighbor] * first_guess[neighbor] + 
                                                (1 - q->white_permeability[neighbor]) * first_guess[curr_ii];
                            float max_val = (q->territory_value[curr_ii] < neighbor_val) ? neighbor_val : q->territory_value[curr_ii];
                            speculative_update[j] = (0 < max_val) ? 0 : max_val;
                        }
                    }
                }
            }
        }

        // Apply updates in reverse order to create WAR pattern (write after read)
        for (int j = 3; j >= 0; j--) {
            if (valid_update[j]) {
                q->territory_value[indices[j]] = speculative_update[j];
            }
        }
    }

    // Handle remaining elements sequentially (tail case)
    for (; ii < (19 + 1) * (19 + 1); ii++) {
        if ((board[ii] != 3)) {
            if (!q->safe[ii]) {
                for (k = 0; k < 4; k++) {
                    if (!(board[ii + delta[k]] != 3))
                        continue;
                    if (q->territory_value[ii] > 0.) {
                        if (!q->safe[ii + delta[k]]) {
                            float neighbor_val = q->black_permeability[ii + delta[k]] * first_guess[ii + delta[k]] + 
                                                (1. - q->black_permeability[ii + delta[k]]) * first_guess[ii];
                            q->territory_value[ii] = ((0) < (((q->territory_value[ii]) < (neighbor_val) ? (q->territory_value[ii]) : (neighbor_val))) ? 
                                                    (((q->territory_value[ii]) < (neighbor_val) ? (q->territory_value[ii]) : (neighbor_val))) : (0));
                        }
                    } else {
                        if (!q->safe[ii + delta[k]]) {
                            float neighbor_val = q->white_permeability[ii + delta[k]] * first_guess[ii + delta[k]] + 
                                                (1 - q->white_permeability[ii + delta[k]]) * first_guess[ii];
                            q->territory_value[ii] = ((0) < (((q->territory_value[ii]) < (neighbor_val) ? (neighbor_val) : (q->territory_value[ii]))) ? 
                                                    (0) : (((q->territory_value[ii]) < (neighbor_val) ? (neighbor_val) : (q->territory_value[ii]))));
                        }
                    }
                }
            }
        }
    }
}
