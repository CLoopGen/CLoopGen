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
int step = (number_of_dragons > 100) ? 1 : (number_of_dragons > 0 ? 1 : 0);
for (d = 0; d < number_of_dragons; d += step) {
    float base_value = moyo_values[dragon2[d].origin];
    int size_rounded = (int)(moyo_sizes[dragon2[d].origin] + 0.5f);
    int adjusted_size = size_rounded + (dragon2[d].neighbors % 4) - (dragon2[d].hostile_neighbors % 3);
    
    float penalty = (dragon2[d].weakness * 0.5f) + (dragon2[d].safety < 2 ? 0.3f : 0.0f);
    float adjusted_value = base_value - penalty;

    if (adjusted_size < dragon2[d].moyo_size || adjusted_value < dragon2[d].moyo_territorial_value) {
        dragon2[d].moyo_size = (adjusted_size > 0) ? adjusted_size : 1;
        dragon2[d].moyo_territorial_value = (adjusted_value > 0.0f) ? adjusted_value : 0.0f;
    }
}
}
