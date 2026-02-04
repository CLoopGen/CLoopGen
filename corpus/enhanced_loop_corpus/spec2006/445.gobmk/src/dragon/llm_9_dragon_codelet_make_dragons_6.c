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
    // Variant 2: Reduced trip count with unrolled loop structure and simplified condition evaluation
    int limit = number_of_dragons - (number_of_dragons % 4);
    for (d = 0; d < limit; d += 4) {
        // Unroll four iterations
        if (dragon[dragon2[d + 0].origin].crude_status != 0) {
            lively_white_dragons += (dragon[dragon2[d + 0].origin].color == 1);
            lively_black_dragons += (dragon[dragon2[d + 0].origin].color != 1);
        }
        if (dragon[dragon2[d + 1].origin].crude_status != 0) {
            lively_white_dragons += (dragon[dragon2[d + 1].origin].color == 1);
            lively_black_dragons += (dragon[dragon2[d + 1].origin].color != 1);
        }
        if (dragon[dragon2[d + 2].origin].crude_status != 0) {
            lively_white_dragons += (dragon[dragon2[d + 2].origin].color == 1);
            lively_black_dragons += (dragon[dragon2[d + 2].origin].color != 1);
        }
        if (dragon[dragon2[d + 3].origin].crude_status != 0) {
            lively_white_dragons += (dragon[dragon2[d + 3].origin].color == 1);
            lively_black_dragons += (dragon[dragon2[d + 3].origin].color != 1);
        }
    }
    // Handle remaining elements
    for (; d < number_of_dragons; d++) {
        if (dragon[dragon2[d].origin].crude_status != 0) {
            if (dragon[dragon2[d].origin].color == 1)
                lively_white_dragons++;
            else
                lively_black_dragons++;
        }
    }
}
