#include <stdio.h>
#include <stdlib.h>
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
int maxlib = 20;
int *libs;
int k;
int liberties = 20;
int s = 0;

void init_vars() {
    for (int i = 0; i < 240; i++) {
        string[i].color = i % 3;
        string[i].size = (i + 1) % 15;
        string[i].origin = i % 100;
        string[i].liberties = 20;
        string[i].neighbors = (i + 10) % 160;
        string[i].mark = i % 2;
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i + j) % 100;
        }
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i + j) % 240;
        }
    }
    libs = (int*)malloc(20 * sizeof(int));
    s = 120;
    maxlib = 20;
    liberties = 20;
}