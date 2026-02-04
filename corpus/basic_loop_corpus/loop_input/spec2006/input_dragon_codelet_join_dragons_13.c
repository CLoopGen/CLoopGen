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
int d1;
int d2;
int ii;
int origin;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4);
    }
    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 2;
        dragon[i].id = i;
        dragon[i].origin = (i % 50) + 1;
        dragon[i].size = (i % 30) + 1;
        dragon[i].effective_size = (float)(i % 25) + 1.5f;
        dragon[i].crude_status = i % 4;
        dragon[i].owl_threat_status = i % 3;
        dragon[i].owl_status = i % 2;
        dragon[i].owl_attack_point = (i + 10) % 19;
        dragon[i].owl_attack_code = i % 4;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = (i + 15) % 19;
        dragon[i].owl_defense_point = i % 19;
        dragon[i].owl_defense_code = i % 3;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = (i + 5) % 19;
        dragon[i].status = i % 4;
        dragon[i].owl_attack_kworm = i % 10;
        dragon[i].owl_defense_kworm = i % 10;
    }
    d1 = 25;
    d2 = 30;
    origin = 100;
}