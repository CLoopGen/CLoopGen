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
    // Variant 1: Consecutive Memory Access with Loop Unrolling and Stride Simulation
    // Instead of accessing delta[k] for neighbor offsets, we unroll the loop and access neighbors in a more predictable,
    // consecutive pattern where possible. We also restructure to process multiple iterations at once to improve cache locality.
    
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1) - 7; ii += 8) {
        int base_idx[8];
        char safe_vals[8];
        Intersection board_vals[8];
        
        // Precompute indices and values for 8 consecutive positions to enable vectorization
        for (int j = 0; j < 8; j++) {
            base_idx[j] = ii + j;
            safe_vals[j] = q->safe[base_idx[j]];
            board_vals[j] = board[base_idx[j]];
        }

        for (int j = 0; j < 8; j++) {
            int i_idx = base_idx[j];
            if ((board_vals[j] != 3) && safe_vals[j]) {
                for (int k = 0; k < 8; k++) {
                    int d = delta[k];
                    int neighbor = i_idx + d;
                    if ((board[neighbor] != 3) && !q->safe[neighbor]) {
                        float reduction = (k < 4) ? 0.25 : 0.65000000000000002;
                        if (board_vals[j] == 2)
                            q->white_permeability[neighbor] *= reduction;
                        else
                            q->black_permeability[neighbor] *= reduction;
                    }
                }
            }
        }
    }

    // Handle remaining elements
    for (; ii < (19 + 1) * (19 + 1); ii++) {
        if ((board[ii] != 3) && q->safe[ii]) {
            int k;
            for (k = 0; k < 8; k++) {
                int d = delta[k];
                if ((board[ii + d] != 3) && !q->safe[ii + d]) {
                    float reduction = (k < 4) ? 0.25 : 0.65000000000000002;
                    if (board[ii] == 2)
                        q->white_permeability[ii + d] *= reduction;
                    else
                        q->black_permeability[ii + d] *= reduction;
                }
            }
        }
    }
}
