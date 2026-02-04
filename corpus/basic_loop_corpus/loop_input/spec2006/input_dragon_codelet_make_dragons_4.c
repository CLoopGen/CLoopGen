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
int str;

void init_vars() {
    // Initialize board with values, ensuring some are not 3 to trigger the condition
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 1 : 3;  // Some entries are not 3
    }

    // Initialize dragon array
    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 2;
        dragon[i].id = i;
        dragon[i].origin = (i == 0) ? 0 : (i % 17);  // Ensure origin is within bounds
        if (dragon[i].origin >= 400) {
            dragon[i].origin = 0;
        }
        dragon[i].size = 10 + (i % 15);
        dragon[i].effective_size = 10.0f + (i % 15);
        dragon[i].crude_status = i % 5;
        dragon[i].owl_threat_status = i % 3;
        dragon[i].owl_status = i % 4;
        dragon[i].owl_attack_point = -1;
        dragon[i].owl_attack_code = 0;
        dragon[i].owl_attack_certain = 0;
        dragon[i].owl_second_attack_point = -1;
        dragon[i].owl_defense_point = -1;
        dragon[i].owl_defense_code = 0;
        dragon[i].owl_defense_certain = 1;
        dragon[i].owl_second_defense_point = -1;
        dragon[i].status = i % 3;
        dragon[i].owl_attack_kworm = 0;
        dragon[i].owl_defense_kworm = 0;
    }

    // Ensure all origins point to valid indices
    for (int i = 0; i < 400; i++) {
        if (dragon[i].origin >= 400 || dragon[i].origin < 0) {
            dragon[i].origin = 0;
        }
    }

    // Set str to a safe initial value (will be overwritten in loop)
    str = 0;
}