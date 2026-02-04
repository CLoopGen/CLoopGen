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
extern char goal[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int index;
    // Variant 1: Consecutive memory access with pointer arithmetic to traverse board and related arrays sequentially
    char *safe_ptr = q->safe + (19 + 2);
    Intersection *board_ptr = board + (19 + 2);
    char *goal_ptr = goal + (19 + 2);
    for (index = (19 + 2); index < (19 + 1) * (19 + 1); index++) {
        if ((*board_ptr != 3)) {
            if (*safe_ptr == 2)
                *goal_ptr = 1;
            else
                *goal_ptr = 0;
        }
        // Move pointers forward consecutively
        safe_ptr++;
        board_ptr++;
        goal_ptr++;
    }
}
