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
extern int str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce trip count significantly by looping only over a subset with higher stride
    for (str = (19 + 2); str < (19 + 1) * (19 + 1) / 2; str += 4) {
        // Add multiple conditions to increase control complexity slightly
        if ((board[str] != 3) && (dragon[str].color == 1 || dragon[str].size > 5)) {
            struct dragon_data *dd = &(dragon[str]);
            int origin_idx = dd->origin;
            // Copy entire struct but modify one additional field using arithmetic
            dragon[str] = dragon[origin_idx];
            dragon[str].id = (origin_idx * 7 + 11) % 100;  // Additional computation
        }
    }
}
