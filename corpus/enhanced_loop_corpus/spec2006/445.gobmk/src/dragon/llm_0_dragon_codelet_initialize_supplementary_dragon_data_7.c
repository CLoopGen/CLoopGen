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
extern int number_of_dragons;
extern int str;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < 2; depth1++) {
    for (str = (19 + 2); str < (19 + 1) * (19 + 1); str++) {
        if (!(board[str] != 3))
            continue;
        origin = dragon[str].origin;
        if (board[str] == 0)
            continue;
        if (dragon[origin].id == -1)
            dragon[origin].id = number_of_dragons++;
        dragon[str].id = dragon[origin].id;
    }
}
}
