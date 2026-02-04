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
for (str = (19 + 2); str < (19 + 1) * (19 + 1); str++) {
    if ((board[str] != 3)) {
        struct dragon_data *dd = &(dragon[str]);
        dd->color = dragon[dd->origin].color;
        dd->id = dragon[dd->origin].id;
        dd->size = dragon[dd->origin].size;
        dd->effective_size = dragon[dd->origin].effective_size;
        dd->crude_status = dragon[dd->origin].crude_status;
        dd->owl_threat_status = dragon[dd->origin].owl_threat_status;
        dd->owl_status = dragon[dd->origin].owl_status;
        dd->owl_attack_point = dragon[dd->origin].owl_attack_point;
        dd->owl_attack_code = dragon[dd->origin].owl_attack_code;
        dd->owl_attack_certain = dragon[dd->origin].owl_attack_certain;
        dd->owl_second_attack_point = dragon[dd->origin].owl_second_attack_point;
        dd->owl_defense_point = dragon[dd->origin].owl_defense_point;
        dd->owl_defense_code = dragon[dd->origin].owl_defense_code;
        dd->owl_defense_certain = dragon[dd->origin].owl_defense_certain;
        dd->owl_second_defense_point = dragon[dd->origin].owl_second_defense_point;
        dd->status = dragon[dd->origin].status;
        dd->owl_attack_kworm = dragon[dd->origin].owl_attack_kworm;
        dd->owl_defense_kworm = dragon[dd->origin].owl_defense_kworm;
    }
}
}
