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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary index array to access board and dragon in a non-sequential, indirect manner.
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    int indices[380]; // Large enough to hold all valid indices
    int count = 0;

    // Precompute shuffled access order (simple increment with offset modulation)
    for (int i = start; i < end; i++) {
        indices[count++] = (i * 7) % (end - start) + start; // pseudo-shuffle indices
    }

    // Traverse using indirect addressing
    for (int idx = 0; idx < count; idx++) {
        str = indices[idx];
        if (str >= end) continue; // safety bound check
        if ((board[str] != 3))
            dragon[str].status = dragon[dragon[str].origin].status;
    }
}
