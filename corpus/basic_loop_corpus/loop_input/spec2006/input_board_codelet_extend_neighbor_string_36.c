#include <stdio.h>
#include <inttypes.h>

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
int string_mark;
int s;
int k;

void init_vars() {
    string_mark = 42;
    s = 100; 

    for (int i = 0; i < 240; i++) {
        string[i].color = i * 3;
        string[i].size = i * 2;
        string[i].origin = i * 5;
        string[i].liberties = 10;
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 100;
        }
        string[i].neighbors = (i < 120) ? 80 : 40;
        for (int j = 0; j < string[i].neighborlist[160]; j++) {
            string[i].neighborlist[j] = (i + j) % 240;
        }
        string[i].mark = 0;
    }

    for (int i = 0; i < string[s].neighbors; i++) {
        int neighbor_idx = string[s].neighborlist[i];
        if (neighbor_idx >= 0 && neighbor_idx < 240) {
            string[neighbor_idx].mark = 0;
        }
    }
}