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
for (str = (19 + 2); str < (19 + 1) * (19 + 1); str++)
    if ((board[str] != 3)) {
        if (((board[str]) == 1 || (board[str]) == 2)) {
            if (dragon[str].owl_status != 4)
                dragon[str].status = dragon[str].owl_status;
            else if (dragon[str].crude_status == 0 || dragon[str].crude_status == 2) {
                dragon[str].status = 3;
            } else {
                dragon[str].status = 1;
            }
        }
    }

}
