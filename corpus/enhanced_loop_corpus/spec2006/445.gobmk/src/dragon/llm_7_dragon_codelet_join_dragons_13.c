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
    // Introduce loop-carried dependence via induction variable with delayed update
    int prev_ii = -1;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if (prev_ii != -1 && (board[prev_ii] != 3) && (dragon[prev_ii].origin == d1 || dragon[prev_ii].origin == d2))
            dragon[prev_ii].origin = origin; // Use previous iteration's value, creating loop-carried RAW/WAW dependency
        prev_ii = ii;
    }
    // Handle last element since loop exits before processing it
    if (prev_ii != -1 && (board[prev_ii] != 3) && (dragon[prev_ii].origin == d1 || dragon[prev_ii].origin == d2))
        dragon[prev_ii].origin = origin;
}
