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



void loop() {
    int temp_lively_white = 0;
    int temp_lively_black = 0;
    for (d = 0; d < number_of_dragons; d++) {
        int origin_idx = dragon2[d].origin;
        int color = dragon[origin_idx].color;
        int status = dragon[origin_idx].crude_status;
        if (status != 0) {
            if (color == 1) {
                temp_lively_white++;
            } else {
                temp_lively_black++;
            }
        }
    }
    lively_white_dragons = temp_lively_white;
    lively_black_dragons = temp_lively_black;
}
