#include <stdio.h>
#include <inttypes.h>

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

int number_of_dragons;
struct dragon_data2 *dragon2;
int d;

void init_vars() {
    number_of_dragons = 5000000; // Approx. 200 MB of data (each struct ~40 bytes)
    dragon2 = (struct dragon_data2*)__builtin_malloc(number_of_dragons * sizeof(struct dragon_data2));

    for (int i = 0; i < number_of_dragons; i++) {
        dragon2[i].origin = i;
        for (int j = 0; j < 10; j++) {
            dragon2[i].adjacent[j] = (i + j) % 100;
        }
        dragon2[i].neighbors = 4;
        dragon2[i].hostile_neighbors = 2;
        dragon2[i].moyo_size = 100;
        dragon2[i].moyo_territorial_value = 30.5f;
        dragon2[i].safety = 75;
        dragon2[i].weakness = 0.25f + (i % 100) / 1000.0f;
        dragon2[i].escape_route = 3;
        dragon2[i].genus.a = 1;
        dragon2[i].genus.b = 2;
        dragon2[i].genus.c = 3;
        dragon2[i].genus.d = 4;
        dragon2[i].heye = 1;
        dragon2[i].lunch = 0;
        dragon2[i].semeai = 1;
        dragon2[i].semeai_margin_of_safety = 5;
        dragon2[i].surround_status = 2;
        dragon2[i].surround_size = 20;
    }
}