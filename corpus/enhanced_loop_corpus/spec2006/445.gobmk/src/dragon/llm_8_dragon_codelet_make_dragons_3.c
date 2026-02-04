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
    for (str = (19 + 2); str < (19 + 1) * (19 + 1); str += 2)
        if ((board[str] != 3)) {
            struct dragon_data *dd = &(dragon[str]);
            int origin_index = dd->origin;
            // Increase arithmetic operations: simulate size scaling and status adjustment
            dragon[str].size = (dragon[origin_index].size * 3 + 1) / 2;
            dragon[str].effective_size = dragon[origin_index].effective_size * 1.5f;
            dragon[str].status = (dragon[origin_index].status + 4) % 7;
            dragon[str].crude_status = (dragon[origin_index].crude_status ^ 3) & 7;
        }
}
