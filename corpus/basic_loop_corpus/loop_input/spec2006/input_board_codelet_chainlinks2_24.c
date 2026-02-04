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
int adj[160];
int lib = 1;
struct string_data *s = &string[0];
struct string_data *t = &string[0];
int k = 0;
int neighbors = 0;

void init_vars() {
    for (int i = 0; i < 240; i++) {
        string[i].color = i * 3;
        string[i].size = (i % 15) + 1;
        string[i].origin = i * 17;
        string[i].liberties = (i % 5) + 1;
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 100;
        }
        string[i].neighbors = (i % 10) + 1;
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i + j) % 240;
        }
        string[i].mark = i % 2;
    }

    for (int i = 0; i < 160; i++) {
        adj[i] = -1;
    }

    s = &string[5];
    lib = 3;
    neighbors = 0;
}