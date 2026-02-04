#include <stdio.h>
#include <inttypes.h>

struct worm_data {
    int color;
    int size;
    float effective_size;
    int origin;
    int liberties;
    int liberties2;
    int liberties3;
    int liberties4;
    int lunch;
    int cutstone;
    int cutstone2;
    int genus;
    int inessential;
    int invincible;
    int unconditional_status;
    int attack_points[10];
    int attack_codes[10];
    int defense_points[10];
    int defense_codes[10];
    int attack_threat_points[10];
    int attack_threat_codes[10];
    int defense_threat_points[10];
    int defense_threat_codes[10];
};

struct worm_data worm[400];
int pos;
int k;
int num_stones;
int stones[361];

void init_vars() {
    pos = 50;
    num_stones = 361;
    
    for (int i = 0; i < 361; i++) {
        stones[i] = i;
    }
    
    stones[100] = 399;
    stones[200] = 400;
    
    for (int i = 0; i < 400; i++) {
        worm[i].color = i * 31;
        worm[i].size = i * 17;
        worm[i].effective_size = i * 1.5f;
        worm[i].origin = i * 7;
        worm[i].liberties = i * 11;
        worm[i].liberties2 = i * 13;
        worm[i].liberties3 = i * 19;
        worm[i].liberties4 = i * 23;
        worm[i].lunch = i * 5;
        worm[i].cutstone = i * 3;
        worm[i].cutstone2 = i * 2;
        worm[i].genus = i * 1;
        worm[i].inessential = i * 4;
        worm[i].invincible = i * 8;
        worm[i].unconditional_status = i * 9;
        
        for (int j = 0; j < 10; j++) {
            worm[i].attack_points[j] = i * 10 + j;
            worm[i].attack_codes[j] = i * 10 + j + 1;
            worm[i].defense_points[j] = i * 10 + j + 2;
            worm[i].defense_codes[j] = i * 10 + j + 3;
            worm[i].attack_threat_points[j] = i * 10 + j + 4;
            worm[i].attack_threat_codes[j] = i * 10 + j + 5;
            worm[i].defense_threat_points[j] = i * 10 + j + 6;
            worm[i].defense_threat_codes[j] = i * 10 + j + 7;
        }
    }
}