#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

struct aftermath_data {
    int white_captured;
    int black_captured;
    int white_prisoners;
    int black_prisoners;
    int white_territory;
    int black_territory;
    int white_area;
    int black_area;
    int white_control[400];
    int black_control[400];
    int final_status[400];
};

Intersection board[421];
int pos;
struct aftermath_data *a;

void init_vars() {
    a = (struct aftermath_data*)calloc(1, sizeof(struct aftermath_data));
    
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 3 == 0) ? 3 : (i % 3 == 1) ? 1 : 2;
    }
    
    for (int i = 0; i < 400; i++) {
        a->white_control[i] = (i % 7 == 0);
        a->black_control[i] = (i % 11 == 0);
        a->final_status[i] = 0;
    }
    
    a->white_captured = 0;
    a->black_captured = 0;
    a->white_prisoners = 0;
    a->black_prisoners = 0;
    a->white_territory = 0;
    a->black_territory = 0;
    a->white_area = 0;
    a->black_area = 0;
}