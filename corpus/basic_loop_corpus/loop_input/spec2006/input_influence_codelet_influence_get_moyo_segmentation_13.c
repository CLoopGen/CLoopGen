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

struct moyo_data {
    int number;
    int segmentation[400];
    int size[361];
    int owner[361];
    float territorial_value[361];
};

Intersection board[421];
struct influence_data *q;
struct moyo_data *moyos;
int ii;
int min_moyo_id;

void init_vars() {
    // Allocate and initialize influence_data and moyo_data on heap to allow flexible initialization
    static struct influence_data q_storage;
    static struct moyo_data moyos_storage;
    
    q = &q_storage;
    moyos = &moyos_storage;
    
    // Initialize board: set all elements to 0 except boundaries (set to 3)
    for (int i = 0; i < 421; i++) {
        if (i < 21 || i % 21 == 0 || (i + 1) % 21 == 0 || i >= 400)
            board[i] = 3;
        else
            board[i] = 0;
    }
    
    // Initialize q->moyo_segmentation with sample data in range [0,10]
    for (int i = 0; i < 400; i++) {
        q->moyo_segmentation[i] = (i * 7 + 13) % 11;  // values from 0 to 10
    }
    
    // Set min_moyo_id to a reasonable offset (e.g., 5)
    min_moyo_id = 5;
    
    // Zero out moyos->segmentation initially
    for (int i = 0; i < 400; i++) {
        moyos->segmentation[i] = 0;
    }
    
    // Initialize other fields to avoid undefined behavior if accessed elsewhere
    q->number_of_regions = 100;
    q->is_territorial_influence = 1;
    q->captured = 0;
    q->color_to_move = 1;
    q->intrusion_counter = 0;
}