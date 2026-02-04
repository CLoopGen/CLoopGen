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

Intersection board[421];
struct influence_data *q;
int ii;

void init_vars() {
    // Allocate and initialize q
    q = (struct influence_data*)calloc(1, sizeof(struct influence_data));
    
    // Initialize board: set all to 0 except boundaries
    for (int i = 0; i < 421; i++) {
        board[i] = 0;
    }
    
    // Set boundary values (indices that are not in the 19x19 grid with padding)
    // Assuming 19x19 board with 2-padded border, valid indices from (19+2) to (19+1)*(19+1)-1
    for (int i = 0; i < 19+2; i++) {
        board[i] = 3; // Mark as out-of-bounds
    }
    for (int row = 1; row <= 19+1; row++) {
        int idx = row * (19+1);
        if (idx < 421) board[idx] = 3;
        if (idx+1 < 421) board[idx+1] = 3;
    }

    // Initialize safe array randomly
    for (int i = 0; i < 400; i++) {
        q->safe[i] = rand() % 2;
        q->territory_value[i] = ((float)(rand() % 2000 - 1000)) / 1000.0f;
        q->non_territory[i] = rand() % 3;
    }

    // Ensure the loop runs over a significant amount of data
    // The original loop runs from (19+2)=21 to (19+1)*(19+1)=400
    // We already have correct sizing

    // Initialize other fields to plausible values
    q->number_of_regions = 100;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 1;
    q->intrusion_counter = 0;

    // Initialize queue
    for (int i = 0; i < 361; i++) {
        q->queue[i] = i;
    }

    // Initialize intrusions
    for (int i = 0; i < 722; i++) {
        q->intrusions[i].source_pos = rand() % 400;
        q->intrusions[i].strength_pos = rand() % 400;
        q->intrusions[i].strength = ((float)(rand() % 1000)) / 1000.0f;
        q->intrusions[i].attenuation = ((float)(rand() % 1000)) / 1000.0f;
    }

    // Initialize region arrays
    for (int i = 0; i < 1084; i++) {
        q->region_type[i] = i < 100 ? rand() % 4 : 0;
        q->region_size[i] = rand() % 50;
        q->region_territorial_value[i] = ((float)(rand() % 2000 - 1000)) / 1000.0f;
    }
}