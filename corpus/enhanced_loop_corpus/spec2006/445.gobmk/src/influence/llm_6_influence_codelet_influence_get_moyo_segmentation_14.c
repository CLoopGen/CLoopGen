#include <stdio.h>

#include <inttypes.h>

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


extern  struct influence_data *q;
extern struct moyo_data *moyos;
extern int min_moyo_id;
extern int max_moyo_id;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = min_moyo_id; j <= max_moyo_id; j++) {
        int idx = j - min_moyo_id + 1;
        // Introduce a WAW dependency by writing to same location in non-constant order
        moyos->owner[idx] = 0; // Write 1: initialize
        moyos->size[idx] = q->region_size[j];
        moyos->territorial_value[idx] = q->region_territorial_value[j];
        if (q->region_type[j] & 1)
            moyos->owner[idx] = 2;
        else
            moyos->owner[idx] = 1; // Write 2: final value depends on conditional, creates WAW within iteration
        // Loop-carried dependence introduced via intrusion_counter update based on prior iteration's moyo data
        if (idx > 1 && moyos->owner[idx - 1] == 2) {
            q->intrusion_counter++; // WAR: write after read of shared state, loop-carried through intrusion_counter
        }
    }
}
