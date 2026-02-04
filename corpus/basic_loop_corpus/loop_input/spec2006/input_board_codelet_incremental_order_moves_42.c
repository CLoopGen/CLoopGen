#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};

struct string_data string[240];
int saved_stones_storage;
int *saved_stones = &saved_stones_storage;
int s = 120;
int r;
struct string_data *t;

void init_vars() {
    for (int i = 0; i < 240; i++) {
        string[i].color = i * 37;
        string[i].size = (i % 50) + 1;
        string[i].origin = i * 19;
        string[i].liberties = (i % 4) + 1;
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 361;
        }
        string[i].neighbors = (i % 160) + 1;
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i + j * 17) % 240;
        }
        string[i].mark = i % 2;
    }

    saved_stones_storage = 0;
    s = 120;
    r = 0;
    t = &string[0];
}