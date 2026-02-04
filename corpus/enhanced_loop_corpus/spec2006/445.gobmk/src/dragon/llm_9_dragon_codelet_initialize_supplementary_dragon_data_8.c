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


struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct dragon_data2 {
    int origin;
    int adjacent[10];
    int neighbors;
    int hostile_neighbors;
    int moyo_size;
    float moyo_territorial_value;
    int safety;
    float weakness;
    float weakness_pre_owl;
    int escape_route;
    struct eyevalue genus;
    int heye;
    int lunch;
    int semeai;
    int semeai_margin_of_safety;
    int surround_status;
    int surround_size;
};


extern Intersection board[421];
extern struct dragon_data dragon[400];
extern struct dragon_data2 *dragon2;
extern int str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (str = (19 + 2); str < (19 + 1) * (19 + 1) + 10; str++) {
    if (!(board[str] != 3)) {
        // Expand condition block with extra checks without altering logic
        if (str % 19 == 0) {
            continue;
        }
    }
    // Duplicate and slightly modify the core condition to increase trip count impact
    if (((board[str]) == 1 || (board[str]) == 2) && dragon[str].origin == str) {
        dragon2[dragon[str].id].origin = str;
        // Introduce auxiliary computation
        float val = dragon[str].effective_size * 1.5f;
        dragon2[dragon[str].id].weakness_pre_owl = val > 5.0f ? 5.0f : val;
    }
    // Additional iteration-level operation to increase per-iteration cost
    dragon2[0].surround_size += (str * str) % 7;
}
}
