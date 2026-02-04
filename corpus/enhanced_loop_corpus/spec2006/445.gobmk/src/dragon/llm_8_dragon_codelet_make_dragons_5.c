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
    int base = 19;
    int start = base + 2;
    int limit = (base + 1) * (base + 1);
    for (str = start; str < limit; str += 2) {
        if ((board[str] != 3) && (str < 400)) {
            dragon[str].status = dragon[dragon[str].origin].status;
            dragon[str + 1].status = dragon[dragon[str + 1].origin].status;
        }
    }
}
