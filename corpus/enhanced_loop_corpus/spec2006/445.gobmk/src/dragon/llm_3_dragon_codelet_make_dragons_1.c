#include <stdio.h>

#include <inttypes.h>

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


typedef unsigned char Intersection;

extern Intersection board[421];
extern struct dragon_data dragon[400];
extern int str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary array to define a non-linear traversal order,
    // simulating indirect or gather-style access patterns.
    // For simplicity and self-containment, we generate indices on-stack.

    int indices[400];
    int count = 0;
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);

    // Precompute reversed access order (indirect pattern)
    for (int i = end - 1; i >= start; i--) {
        indices[count++] = i;
    }

    for (int j = 0; j < count; j++) {
        str = indices[j];
        if ((board[str] != 3)) {
            struct dragon_data *dd = &(dragon[str]);
            dragon[str] = dragon[dd->origin];
        }
    }
}
