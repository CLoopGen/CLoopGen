#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};


extern Intersection board[421];
extern struct dragon_data dragon[400];
extern int d1;
extern int d2;
extern int ii;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Loop Splitting and Sequential Traversal
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    // Process elements in forward order with direct indexing, ensuring consecutive memory access on `dragon` and `board`
    for (ii = start; ii < end; ii++) {
        Intersection b_val = board[ii];
        struct dragon_data *d_ptr = &dragon[ii];
        if ((b_val != 3) && (d_ptr->origin == d1 || d_ptr->origin == d2)) {
            d_ptr->origin = origin;
        }
    }
}
