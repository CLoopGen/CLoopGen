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

Intersection board[421];
struct dragon_data dragon[400];
int str;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4 == 0) ? 3 : ((i % 3 == 0) ? 1 : 2);
    }
    
    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 2;
        dragon[i].id = i;
        dragon[i].origin = (i * 7) % 400;
        dragon[i].size = (i % 15) + 1;
        dragon[i].effective_size = (float)((i % 100) + 1) / 10.0f;
        dragon[i].crude_status = i % 3;
        dragon[i].owl_threat_status = (i * 13) % 5;
        dragon[i].owl_status = (i % 6 == 0) ? 4 : (i % 5);
        dragon[i].owl_attack_point = (i * 17) % 400;
        dragon[i].owl_attack_code = (i * 19) % 8;
        dragon[i].owl_attack_certain = (i % 7 == 0) ? 1 : 0;
        dragon[i].owl_second_attack_point = (i * 23) % 400;
        dragon[i].owl_defense_point = (i * 29) % 400;
        dragon[i].owl_defense_code = (i * 31) % 8;
        dragon[i].owl_defense_certain = (i % 11 == 0) ? 1 : 0;
        dragon[i].owl_second_defense_point = (i * 37) % 400;
        dragon[i].status = 0;
        dragon[i].owl_attack_kworm = (i * 41) % 50;
        dragon[i].owl_defense_kworm = (i * 43) % 50;
    }
}