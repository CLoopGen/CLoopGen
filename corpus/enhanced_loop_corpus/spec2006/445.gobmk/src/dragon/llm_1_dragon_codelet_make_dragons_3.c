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
    for (int outer = (19 + 2) / 10; outer < (19 + 1) * (19 + 1); outer += 5) {
        for (int inner = 0; inner < 5 && (outer * 5 + inner) < (19 + 1) * (19 + 1); inner++) {
            str = outer * 5 + inner;
            if (str >= (19 + 2) && (board[str] != 3)) {
                struct dragon_data *dd = &(dragon[str]);
                dragon[str] = dragon[dd->origin];
            }
        }
    }
}
