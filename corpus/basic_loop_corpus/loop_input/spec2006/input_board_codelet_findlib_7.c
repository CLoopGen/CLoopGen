#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char Intersection;

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

Intersection board[421];
struct string_data string[240];
int next_stone[400];
int ml[400];
int liberty_mark;
int maxlib;
int *libs;
int k;
int liberties;
int s;
int pos;

void init_vars() {
    liberty_mark = 1;
    maxlib = 200;
    libs = (int*)malloc(maxlib * sizeof(int));
    s = 5;
    string[s].origin = 100;
    liberties = 150;
    for (int i = 0; i < 421; i++) {
        board[i] = 0;
    }
    for (int i = 0; i < 400; i++) {
        next_stone[i] = i + 1;
        ml[i] = 0;
    }
    next_stone[399] = 0;
    for (int i = 0; i < 240; i++) {
        string[i].origin = (i * 10) % 400;
        string[i].liberties = 20;
    }
}