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
extern int pos;
extern int dragons[400];
extern int distances[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    // Reverse loop direction to eliminate potential forward loop-carried dependencies
    for (i = (19 + 1) * (19 + 1) - 1; i >= (19 + 2); i--) {
        pos = i;
        if (((board[pos]) == 1 || (board[pos]) == 2)) {
            dragons[pos] = dragon[pos].id;
            distances[pos] = 0;
        } else if ((board[pos] != 3)) {
            dragons[pos] = -1;
            distances[pos] = -1;
        }
    }
}
