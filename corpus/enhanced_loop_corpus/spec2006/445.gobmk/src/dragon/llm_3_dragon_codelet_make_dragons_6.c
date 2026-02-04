#include <stdio.h>

#include <inttypes.h>

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


extern struct dragon_data dragon[400];
extern int number_of_dragons;
extern struct dragon_data2 *dragon2;
extern int lively_white_dragons;
extern int lively_black_dragons;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with step size of 2, processing every second element first, then the others
    int d;
    // First pass: even indices
    for (d = 0; d < number_of_dragons; d += 2)
        if (dragon[dragon2[d].origin].crude_status != 0) {
            if (dragon[dragon2[d].origin].color == 1)
                lively_white_dragons++;
            else
                lively_black_dragons++;
        }
    // Second pass: odd indices
    for (d = 1; d < number_of_dragons; d += 2)
        if (dragon[dragon2[d].origin].crude_status != 0) {
            if (dragon[dragon2[d].origin].color == 1)
                lively_white_dragons++;
            else
                lively_black_dragons++;
        }
}
