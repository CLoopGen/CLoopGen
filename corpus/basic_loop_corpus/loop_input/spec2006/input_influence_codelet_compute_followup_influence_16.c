#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    float white_permeability_copy[400];  // padding to avoid overflow
    float black_permeability_copy[400];  // padding
    float white_permeability_pad[320];   // extra padding to reach larger size
    float black_permeability_pad[320];
    float territory_value[400];
    float territory_value_pad[320];
    int territory_segmentation[400];
    int moyo_segmentation[400];
    int area_segmentation[400];
    int region_type[1084];
    int region_size[1084];
    float region_territorial_value[1084];
    int number_of_regions;
    int is_territorial_influence;
    int non_territory[400];
    int captured;
    int color_to_move;
    int queue[361];
    int intrusion_counter;
    struct intrusion_data intrusions[722];
};

Intersection board[421];
struct influence_data *q;
int ii;
int color;
int int_permeabilities[400];

void init_vars() {
    // Initialize board: set all positions to 3 except boundaries
    for (int i = 0; i < 421; i++) {
        board[i] = 3;
    }
    
    // Simulate a standard 19x19 Go board with padding
    // Board layout: (19+2) x (19+2) = 21x21 = 441, but array is 421? Adjusting.
    // Assuming valid indices from 21+1 to (21*19)+19 = [22..418]
    for (int row = 1; row <= 19; row++) {
        for (int col = 1; col <= 19; col++) {
            int idx = row * 21 + col;
            if (idx < 421) {
                board[idx] = 0;  // empty
            }
        }
    }

    // Allocate and initialize q
    q = (struct influence_data*)calloc(1, sizeof(struct influence_data));
    
    // Initialize permeability values to fractional amounts to simulate real use
    for (int i = 0; i < 400; i++) {
        q->white_permeability[i] = 0.5f + (i % 7) * 0.07f;
        q->black_permeability[i] = 0.5f + (i % 11) * 0.05f;
    }

    // Initialize other arrays to prevent undefined behavior
    for (int i = 0; i < 400; i++) {
        q->white_influence[i] = 0.1f;
        q->black_influence[i] = 0.1f;
        q->white_strength[i] = 1.0f;
        q->black_strength[i] = 1.0f;
        q->white_attenuation[i] = 0.9f;
        q->black_attenuation[i] = 0.9f;
        q->territory_value[i] = 0.0f;
        q->territory_segmentation[i] = 0;
        q->moyo_segmentation[i] = 0;
        q->area_segmentation[i] = 0;
        q->non_territory[i] = 0;
        int_permeabilities[i] = 0;
    }

    for (int i = 0; i < 1084; i++) {
        q->region_type[i] = 0;
        q->region_size[i] = 1;
        q->region_territorial_value[i] = 0.0f;
    }

    for (int i = 0; i < 361; i++) {
        q->queue[i] = 0;
    }

    for (int i = 0; i < 722; i++) {
        q->intrusions[i].source_pos = -1;
        q->intrusions[i].strength_pos = -1;
        q->intrusions[i].strength = 0.0f;
        q->intrusions[i].attenuation = 1.0f;
    }

    q->number_of_regions = 0;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 1;
    q->intrusion_counter = 0;

    // Set color for testing: alternate based on time or fixed
    color = 1;  // ensure defined

    // Ensure loop bounds are safe: ii from 21 to 400 (since (19+1)*(19+1)=400)
    // Our data sizes (400) match the expected access range
}