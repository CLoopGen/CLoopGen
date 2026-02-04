#include <stdio.h>
#include <inttypes.h>

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

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};

struct dragon_data2 {
    int origin;
    int adjacent[10];
    int neighbors;
    int hostile_neighbors;
    int moyo_size;
    float moyo_territorial_value;
    int safety;
    float weakness;
    float weakness_pre_owl;
    int escape_route;
    struct eyevalue genus;
    int heye;
    int lunch;
    int semeai;
    int semeai_margin_of_safety;
    int surround_status;
    int surround_size;
};

#define NUM_DRAGONS 65536

struct dragon_data dragon[NUM_DRAGONS];
int number_of_dragons = NUM_DRAGONS;
struct dragon_data2 dragon2_data[NUM_DRAGONS];
struct dragon_data2 *dragon2 = dragon2_data;
int lively_white_dragons;
int lively_black_dragons;
int d;

void init_vars() {
    for (int i = 0; i < NUM_DRAGONS; i++) {
        dragon[i].color = (i % 3 == 0) ? 1 : ((i % 3 == 1) ? 2 : 0);
        dragon[i].crude_status = (i % 4 != 0) ? 1 : 0;
        dragon[i].origin = i;

        dragon2_data[i].origin = (i + (i % 7)) % NUM_DRAGONS;

        for (int j = 0; j < 10; j++) {
            dragon2_data[i].adjacent[j] = (i + j) % NUM_DRAGONS;
        }
        dragon2_data[i].neighbors = i % 15;
        dragon2_data[i].hostile_neighbors = i % 8;
        dragon2_data[i].moyo_size = i % 100;
        dragon2_data[i].moyo_territorial_value = 0.1f * (i % 100);
        dragon2_data[i].safety = i % 5;
        dragon2_data[i].weakness = 0.01f * (i % 100);
        dragon2_data[i].weakness_pre_owl = 0.01f * ((i + 10) % 100);
        dragon2_data[i].escape_route = i % 20;
        dragon2_data[i].genus.a = i % 256;
        dragon2_data[i].genus.b = (i + 1) % 256;
        dragon2_data[i].genus.c = (i + 2) % 256;
        dragon2_data[i].genus.d = (i + 3) % 256;
        dragon2_data[i].heye = i % 5;
        dragon2_data[i].lunch = i % 3;
        dragon2_data[i].semeai = i % 2;
        dragon2_data[i].semeai_margin_of_safety = i % 10;
        dragon2_data[i].surround_status = i % 4;
        dragon2_data[i].surround_size = i % 50;
    }

    lively_white_dragons = 0;
    lively_black_dragons = 0;
    d = 0;
}