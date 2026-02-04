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
int pos;
int dragons[400];
int distances[400];

void init_vars() {
    const int BOARD_SIZE = 421;
    const int DRAGON_COUNT = 400;
    const int N = 19;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i >= (N + 2) && i < (N + 1) * (N + 1)) {
            board[i] = (i % 4);
        } else {
            board[i] = 0;
        }
    }

    for (int i = 0; i < DRAGON_COUNT; i++) {
        dragon[i].color = i % 3;
        dragon[i].id = i;
        dragon[i].origin = i;
        dragon[i].size = (i % 10) + 1;
        dragon[i].effective_size = (float)(i % 15);
        dragon[i].crude_status = i % 2;
        dragon[i].owl_threat_status = i % 3;
        dragon[i].owl_status = i % 2;
        dragon[i].owl_attack_point = (i + 1) % 400;
        dragon[i].owl_attack_code = i % 5;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = (i + 2) % 400;
        dragon[i].owl_defense_point = (i + 3) % 400;
        dragon[i].owl_defense_code = i % 5;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = (i + 4) % 400;
        dragon[i].status = i % 3;
        dragon[i].owl_attack_kworm = i % 2;
        dragon[i].owl_defense_kworm = i % 2;
    }

    for (int i = 0; i < DRAGON_COUNT; i++) {
        dragons[i] = -2;
        distances[i] = -2;
    }

    pos = 0;
}