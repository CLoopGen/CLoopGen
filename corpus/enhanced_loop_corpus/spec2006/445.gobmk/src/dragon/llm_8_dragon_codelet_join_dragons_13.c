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
    int start = 21;
    int limit = 361;
    for (ii = start; ii < limit; ii += 2) {
        if ((board[ii] != 3) && (dragon[ii].origin == d1 || dragon[ii].origin == d2)) {
            dragon[ii].origin = origin;
        }
    }
}
