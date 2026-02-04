#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    srand(time(NULL));

    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? ((rand() % 3) + 1) : 0;
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = rand() % 3;
        dragon[i].id = i;
        dragon[i].origin = (rand() % 400);
        dragon[i].size = rand() % 100;
        dragon[i].effective_size = (float)(rand() % 1000) / 10.0f;
        dragon[i].crude_status = rand() % 5;
        dragon[i].owl_threat_status = rand() % 3;
        dragon[i].owl_status = rand() % 3;
        dragon[i].owl_attack_point = rand() % 400;
        dragon[i].owl_attack_code = rand() % 10;
        dragon[i].owl_attack_certain = rand() % 2;
        dragon[i].owl_second_attack_point = rand() % 400;
        dragon[i].owl_defense_point = rand() % 400;
        dragon[i].owl_defense_code = rand() % 10;
        dragon[i].owl_defense_certain = rand() % 2;
        dragon[i].owl_second_defense_point = rand() % 400;
        dragon[i].status = rand() % 4;
        dragon[i].owl_attack_kworm = rand() % 50;
        dragon[i].owl_defense_kworm = rand() % 50;
    }

    str = 0;
}