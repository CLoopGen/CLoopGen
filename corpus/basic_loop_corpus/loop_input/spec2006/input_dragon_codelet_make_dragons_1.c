#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
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

struct dragon_data dragon[400];

int str;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4 == 0) ? 3 : (i % 3);
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = i * 7;
        dragon[i].id = i;
        dragon[i].origin = (i % 10 == 0) ? i : (i % 100);
        dragon[i].size = i * 3;
        dragon[i].effective_size = i * 1.5f;
        dragon[i].crude_status = i % 5;
        dragon[i].owl_threat_status = i % 2;
        dragon[i].owl_status = i % 3;
        dragon[i].owl_attack_point = i % 20;
        dragon[i].owl_attack_code = i % 8;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = i % 25;
        dragon[i].owl_defense_point = i % 18;
        dragon[i].owl_defense_code = i % 7;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = i % 22;
        dragon[i].status = i % 4;
        dragon[i].owl_attack_kworm = i % 15;
        dragon[i].owl_defense_kworm = i % 16;
    }

    str = 0;
}