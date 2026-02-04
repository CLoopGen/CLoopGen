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
int string_number[400];
int string_mark;
int adj[160];
struct string_data *s;
int n;

void init_vars() {
    for (int i = 0; i < 240; i++) {
        string[i].color = i * 31;
        string[i].size = (i * 17) % 100 + 1;
        string[i].origin = i * 5;
        string[i].liberties = (i * 3) % 20;
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 240;
        }
        string[i].neighbors = (i * 7) % 80 + 1;
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i * j) % 240;
        }
        string[i].mark = 0;
    }

    for (int i = 0; i < 400; i++) {
        string_number[i] = i % 240;
    }

    string_mark = 1;

    for (int i = 0; i < 160; i++) {
        adj[i] = 0;
    }

    s = &string[100];
}