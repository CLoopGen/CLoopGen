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

struct dragon_data2 *dragon2;
int a = 0;
int b = 5;
int i;

#define DRAGON2_COUNT (1 << 20)  // ~16MB of dragon_data2, sufficient for ~0.01s runtime

void init_vars() {
    dragon2 = (struct dragon_data2*)calloc(DRAGON2_COUNT, sizeof(struct dragon_data2));
    if (!dragon2) exit(1);

    for (int idx = 0; idx < DRAGON2_COUNT; idx++) {
        dragon2[idx].origin = idx;
        dragon2[idx].neighbors = 10;
        dragon2[idx].hostile_neighbors = rand() % 5;
        dragon2[idx].moyo_size = rand() % 100;
        dragon2[idx].moyo_territorial_value = rand() / (float)RAND_MAX * 100.0f;
        dragon2[idx].safety = rand() % 10;
        dragon2[idx].weakness = rand() / (float)RAND_MAX * 50.0f;
        dragon2[idx].weakness_pre_owl = rand() / (float)RAND_MAX * 50.0f;
        dragon2[idx].escape_route = rand() % 20;
        dragon2[idx].genus.a = rand() % 256;
        dragon2[idx].genus.b = rand() % 256;
        dragon2[idx].genus.c = rand() % 256;
        dragon2[idx].genus.d = rand() % 256;
        dragon2[idx].heye = rand() % 8;
        dragon2[idx].lunch = rand() % 3;
        dragon2[idx].semeai = rand() % 2;
        dragon2[idx].semeai_margin_of_safety = rand() % 15;
        dragon2[idx].surround_status = rand() % 4;
        dragon2[idx].surround_size = rand() % 50;

        for (int j = 0; j < 10; j++) {
            dragon2[idx].adjacent[j] = rand() % 100;
        }
        // Ensure that for a=0, 'b' is NOT in the adjacent list to force full loop iteration
        if (idx == 0) {
            for (int j = 0; j < 10; j++) {
                if (dragon2[0].adjacent[j] == b) {
                    // Replace duplicate with a value != b
                    dragon2[0].adjacent[j] = (b + 1) % 100;
                }
            }
        }
    }

    a = 0;
    b = 5;
    i = 0;
}