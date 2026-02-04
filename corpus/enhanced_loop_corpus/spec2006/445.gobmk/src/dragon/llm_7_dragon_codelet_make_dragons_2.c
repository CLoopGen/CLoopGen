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
    int i, base = (19 + 2), limit = (19 + 1) * (19 + 1);
    for (i = base; i < limit; i++) {
        str = limit - 1 - (i - base);
        if ((board[str] != 3)) {
            if (((board[str]) == 1 || (board[str]) == 2)) {
                int owl_st = dragon[str].owl_status;
                int crude_st = dragon[str].crude_status;
                dragon[str].status = (owl_st != 4) ? owl_st : 
                                   (crude_st == 0 || crude_st == 2) ? 3 : 1;
            }
        }
        if (i > base) {
            dragon[str + 1].effective_size += dragon[str].effective_size;
        }
    }
}
