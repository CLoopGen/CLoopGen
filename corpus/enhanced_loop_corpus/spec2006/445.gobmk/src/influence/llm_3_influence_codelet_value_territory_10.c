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
    // Variant 2: Indirect Memory Access via Index Array (Queue-based Access)
    // Use q->queue as an indirect index array to access board and influence data.
    // We fill the queue with valid indices first, then iterate over them.

    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int queue_ptr = 0;

    // Populate queue with relevant indices
    for (int temp_idx = start; temp_idx < end; temp_idx++) {
        if ((board[temp_idx] != 3) && !q->safe[temp_idx]) {
            q->queue[queue_ptr++] = temp_idx;
        }
    }

    // Process elements using indirect access through q->queue
    for (ii = 0; ii < queue_ptr; ii++) {
        int idx = q->queue[ii];  // Indirect access

        if (q->territory_value[idx] > 0. && (q->non_territory[idx] & 1))
            q->territory_value[idx] = 0.;
        if (q->territory_value[idx] < 0. && (q->non_territory[idx] & 2))
            q->territory_value[idx] = 0.;
        if (board[idx] == 2)
            q->territory_value[idx] += 1.;
        else if (board[idx] == 1)
            q->territory_value[idx] -= 1.;
    }
}
