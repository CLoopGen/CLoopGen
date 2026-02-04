#include <stdio.h>

#include <inttypes.h>

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


extern int number_of_dragons;
extern struct dragon_data2 *dragon2;
extern int d;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (d = 0; d < number_of_dragons; d++) {
    int this_moyo_size = (int)(0.01 + moyo_sizes[dragon2[d].origin]);
    float this_moyo_value = moyo_values[dragon2[d].origin];
    if (this_moyo_size >= dragon2[d].moyo_size) {
        continue;
    }
    dragon2[d].moyo_size = this_moyo_size;
    dragon2[d].moyo_territorial_value = this_moyo_value;
}
}
