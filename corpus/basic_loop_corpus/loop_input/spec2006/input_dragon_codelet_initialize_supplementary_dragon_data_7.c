#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char Intersection;

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};

Intersection board[421];
struct dragon_data dragon[400];
int number_of_dragons;
int str;
int origin;

void init_vars() {
    const int BOARD_SIZE = 421;
    const int DRAGON_SIZE = 400;
    
    memset(board, 0, sizeof(board));
    memset(dragon, 0, sizeof(dragon));
    
    number_of_dragons = 0;
    str = 0;
    origin = 0;
    
    for (int i = 0; i < DRAGON_SIZE; i++) {
        dragon[i].origin = (i * 7) % DRAGON_SIZE;
        dragon[i].id = -1;
        dragon[i].color = i % 3;
    }
    
    for (int i = 21; i < BOARD_SIZE; i++) {
        if (i % 7 == 0) {
            board[i] = 3;
        } else if (i % 13 == 0) {
            board[i] = 0;
        } else {
            board[i] = 1;
        }
    }
    
    number_of_dragons = 50;
}