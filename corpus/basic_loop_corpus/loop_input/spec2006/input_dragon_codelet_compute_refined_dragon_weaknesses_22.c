#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    const size_t total_data_size = 64 * 1024 * 1024; // Target ~64 MB of data
    const size_t struct_size = sizeof(struct dragon_data2);
    number_of_dragons = total_data_size / struct_size;
    if (number_of_dragons == 0) number_of_dragons = 1;

    dragon2 = (struct dragon_data2*)calloc(number_of_dragons, sizeof(struct dragon_data2));
    if (!dragon2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < number_of_dragons; i++) {
        dragon2[i].origin = i;
        for (int j = 0; j < 10; j++) {
            dragon2[i].adjacent[j] = (i + j) % number_of_dragons;
        }
        dragon2[i].neighbors = 4;
        dragon2[i].hostile_neighbors = i % 3;
        dragon2[i].moyo_territorial_value = 1.0f + i * 0.5f;
        dragon2[i].safety = i % 100;
        dragon2[i].weakness = 0.1f * (i % 10);
        dragon2[i].weakness_pre_owl = dragon2[i].weakness + 0.05f;
        dragon2[i].escape_route = (i * 7) % 20;
        dragon2[i].genus.a = (unsigned char)(i % 256);
        dragon2[i].genus.b = (unsigned char)((i + 1) % 256);
        dragon2[i].genus.c = (unsigned char)((i + 2) % 256);
        dragon2[i].genus.d = (unsigned char)((i + 3) % 256);
        dragon2[i].heye = i % 5;
        dragon2[i].lunch = (i + 5) % 10;
        dragon2[i].semeai = i % 2;
        dragon2[i].semeai_margin_of_safety = (i % 8) - 4;
        dragon2[i].surround_status = i % 4;
        dragon2[i].surround_size = (i * i) % 100;
    }
}