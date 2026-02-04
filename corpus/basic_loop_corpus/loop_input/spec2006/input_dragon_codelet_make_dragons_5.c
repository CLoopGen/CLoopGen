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
        board[i] = (i < 400) ? ((i % 7 == 0) ? 3 : (i % 5)) : 0;
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 3;
        dragon[i].id = i;
        dragon[i].origin = (i > 0) ? ((i * 17) % 400) : 0;
        dragon[i].size = i % 100;
        dragon[i].effective_size = (float)(i % 50);
        dragon[i].crude_status = i % 4;
        dragon[i].owl_threat_status = i % 3;
        dragon[i].owl_status = i % 2;
        dragon[i].owl_attack_point = (i + 19) % 400;
        dragon[i].owl_attack_code = i % 5;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = (i + 23) % 400;
        dragon[i].owl_defense_point = (i + 11) % 400;
        dragon[i].owl_defense_code = i % 5;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = (i + 13) % 400;
        dragon[i].status = i % 8;
        dragon[i].owl_attack_kworm = i % 10;
        dragon[i].owl_defense_kworm = i % 10;
    }

    str = 0;
}