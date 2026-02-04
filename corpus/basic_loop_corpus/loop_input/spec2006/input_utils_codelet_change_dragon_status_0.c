#include <stdio.h>
#include <inttypes.h>

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
int status;
int pos;
int origin;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4); 
    }
    for (int i = 0; i < 400; i++) {
        dragon[i].origin = (i % 100);
        dragon[i].status = 0;
    }
    status = 1;
    origin = 50; 
}