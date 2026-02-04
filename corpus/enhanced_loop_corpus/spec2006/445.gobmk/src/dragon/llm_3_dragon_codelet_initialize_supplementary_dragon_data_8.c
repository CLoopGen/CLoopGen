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
    // Variant 2: Strided access with step size of 2, forward and backward indexing
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    int stride = 2;
    int i;

    // First pass: forward strided access
    for (i = start; i < end; i += stride) {
        if (!(board[i] != 3))
            continue;
        if (((board[i]) == 1 || (board[i]) == 2) && dragon[i].origin == i) {
            dragon2[dragon[i].id].origin = i;
        }
    }

    // Second pass: backward strided access to cover remaining indices
    for (i = start + 1; i < end; i += stride) {
        if (!(board[i] != 3))
            continue;
        if (((board[i]) == 1 || (board[i]) == 2) && dragon[i].origin == i) {
            dragon2[dragon[i].id].origin = i;
        }
    }
}
