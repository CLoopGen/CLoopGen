#include <stdio.h>
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
int ml[400];
int liberty_mark;
int s;
int k;
int s2;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 0 : 1;
    }

    for (int i = 0; i < 240; i++) {
        string[i].color = i % 3;
        string[i].size = (i * 7) % 100 + 1;
        string[i].origin = (i * 17) % 421;
        string[i].liberties = (i == 0) ? 0 : (i % 5 == 0) ? 20 : (i % 19);
        string[i].neighbors = (i * 3) % 161;
        string[i].mark = (i % 11 == 0) ? 1 : 0;
        
        for (int j = 0; j < 20; j++) {
            string[i].libs[j] = (i * 13 + j * 19) % 400;
        }
        for (int j = 0; j < 160; j++) {
            string[i].neighborlist[j] = (i * 7 + j * 11) % 240;
        }
    }

    for (int i = 0; i < 400; i++) {
        ml[i] = (i % 13 == 0) ? 100 : 0;
    }

    liberty_mark = 100;
    s = 1;
    s2 = 2;
}