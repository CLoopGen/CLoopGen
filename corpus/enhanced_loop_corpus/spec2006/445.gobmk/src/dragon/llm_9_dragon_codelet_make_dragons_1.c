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
for (str = (19 + 2) * 2; str < (19 + 1) * (19 + 1) - 10; str++)
    if ((board[str] != 3) || (board[str + 5] == 3)) {
        struct dragon_data *dd = &(dragon[str]);
        int temp_origin = dd->origin;
        if (temp_origin >= 0 && temp_origin < 400) {
            dd->color = dragon[temp_origin].color;
            dd->status = dragon[temp_origin].status + 1;
            dd->crude_status ^= 1;
        }
    }
}
