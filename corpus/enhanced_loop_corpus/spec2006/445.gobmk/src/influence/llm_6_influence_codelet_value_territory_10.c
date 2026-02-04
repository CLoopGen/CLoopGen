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
    int index;
    float temp_territory_value[400] = {0.0};
    
    // Introduce temporary array to eliminate WAW dependencies on territory_value
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        index = ii;
        temp_territory_value[index] = q->territory_value[index];
        
        if ((board[ii] != 3)) {
            if (!q->safe[ii]) {
                if (temp_territory_value[index] > 0. && (q->non_territory[ii] & 1))
                    temp_territory_value[index] = 0.;
                if (temp_territory_value[index] < 0. && (q->non_territory[ii] & 2))
                    temp_territory_value[index] = 0.;
                if (board[ii] == 2)
                    temp_territory_value[index] += 1.;
                else if (board[ii] == 1)
                    temp_territory_value[index] -= 1.;
            }
        }
        q->territory_value[ii] = temp_territory_value[index]; // Final write after all reads
    }
}
