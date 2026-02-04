#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
float moyo_sizes[400];
float moyo_values[400];

void init_vars() {
    const int approx_data_size = 16 * 1024 * 1024; // ~16MB of dragon data
    const int avg_dragon_size = sizeof(struct dragon_data2);
    number_of_dragons = approx_data_size / avg_dragon_size;
    
    if (number_of_dragons > 400) {
        number_of_dragons = 400; // Limit due to moyo_sizes/values arrays
    }

    dragon2 = (struct dragon_data2*)calloc(number_of_dragons, sizeof(struct dragon_data2));
    if (!dragon2) {
        number_of_dragons = 0;
        return;
    }

    for (int i = 0; i < number_of_dragons; i++) {
        dragon2[i].origin = rand() % 400;
        dragon2[i].moyo_size = (rand() % 100) + 50;
        dragon2[i].moyo_territorial_value = 1.0f + (rand() % 100) / 10.0f;

        for (int j = 0; j < 10; j++) {
            dragon2[i].adjacent[j] = -1;
        }
        dragon2[i].neighbors = 0;
        dragon2[i].hostile_neighbors = 0;
        dragon2[i].safety = 0;
        dragon2[i].weakness = 0.0f;
        dragon2[i].weakness_pre_owl = 0.0f;
        dragon2[i].escape_route = 0;
        dragon2[i].genus.a = 0;
        dragon2[i].genus.b = 0;
        dragon2[i].genus.c = 0;
        dragon2[i].genus.d = 0;
        dragon2[i].heye = 0;
        dragon2[i].lunch = -1;
        dragon2[i].semeai = 0;
        dragon2[i].semeai_margin_of_safety = 0;
        dragon2[i].surround_status = 0;
        dragon2[i].surround_size = 0;
    }

    for (int i = 0; i < 400; i++) {
        moyo_sizes[i] = 10.0f + (rand() % 100) / 5.0f;
        moyo_values[i] = 0.5f + (rand() % 100) / 10.0f;
    }

    d = 0;
}