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
int close_black_worms[400][4];
int number_close_black_worms[400];
int close_white_worms[400][4];
int number_close_white_worms[400];
struct dragon_data dragon[400];
int pos;
int k;
int moyo_color[400];
float territory_value[400];
float moyo_sizes[400];
float moyo_values[400];

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? 3 : 0;
    }

    for (int i = 0; i < 400; i++) {
        number_close_black_worms[i] = 3;
        number_close_white_worms[i] = 4;
        moyo_color[i] = (i % 3 == 0) ? 1 : ((i % 3 == 1) ? 2 : 0);
        territory_value[i] = 0.5f + (i % 50) * 0.01f;
        moyo_sizes[i] = 0.0f;
        moyo_values[i] = 0.0f;

        for (int j = 0; j < 4; j++) {
            close_black_worms[i][j] = (i + j) % 400;
            close_white_worms[i][j] = (i + j + 100) % 400;
        }
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].origin = i;
        dragon[i].color = (i % 2) + 1;
    }

    pos = 0;
    k = 0;
}