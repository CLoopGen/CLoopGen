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
    float white_permeability_copy[400];  // padding to align offsets
    float black_permeability_copy[400];  // padding
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

int delta[8] = { 1, -1, 19 + 2, -(19 + 2), 2, -2, 20, -20 }; // directional deltas for board neighbors

Intersection board[421];

struct influence_data *q;
int ii;
float first_guess[400];
int k;

void init_vars() {
    // Allocate and initialize q
    static struct influence_data q_data;
    q = &q_data;

    // Initialize board with boundary markers (value 3) and interior as empty (0)
    for (int i = 0; i < 421; i++) {
        if (i < 21 || i >= 400 || (i % 21 == 0) || ((i - 20) % 21 == 0))
            board[i] = 3; // edge or corner sentinel
        else
            board[i] = 0; // playable position
    }

    // Initialize safe array: only center-ish region is unsafe
    for (int i = 0; i < 400; i++) {
        q->safe[i] = 0; // most are unsafe
        q->territory_value[i] = (i % 7) * 0.1f; // small positive values
        first_guess[i] = (i % 5) * 0.2f;
    }

    // Ensure safe[ii + delta[k]] accesses are in bounds by restricting ii range
    // The loop runs from (19+2)=21 to (19+1)*(19+1)=400, which maps 0..399 -> indices 21..400
    // Our board uses offset indexing: playable indices are [21, 400] inclusive in a 421 array

    // Initialize permeability arrays
    for (int i = 0; i < 400; i++) {
        q->black_permeability[i] = 0.5f + (i % 3) * 0.1f;
        q->white_permeability[i] = 0.5f - (i % 3) * 0.1f;
    }

    // Other fields
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
        q->intrusions[i].source_pos = i % 400;
        q->intrusions[i].strength_pos = (i + 100) % 400;
        q->intrusions[i].strength = 0.8f;
        q->intrusions[i].attenuation = 0.95f;
    }

    // Initialize segmentation arrays
    for (int i = 0; i < 400; i++) {
        q->territory_segmentation[i] = i % 10;
        q->moyo_segmentation[i] = i % 12;
        q->area_segmentation[i] = i % 15;
    }
    for (int i = 0; i < 1084; i++) {
        q->region_type[i] = i % 5;
        q->region_size[i] = 10 + (i % 20);
        q->region_territorial_value[i] = (i % 100) * 0.1f;
    }
}