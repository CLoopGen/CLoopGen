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
    // Variant 2: Strided access with step size of 2, processing every second element first, then the others
    int stride = 2;
    int phase, d;
    for (phase = 0; phase < stride; phase++) {
        for (d = phase; d < number_of_dragons; d += stride) {
            int this_moyo_size = (int)(0.01 + moyo_sizes[dragon2[d].origin]);
            float this_moyo_value = moyo_values[dragon2[d].origin];
            if (this_moyo_size < dragon2[d].moyo_size) {
                dragon2[d].moyo_size = this_moyo_size;
                dragon2[d].moyo_territorial_value = this_moyo_value;
            }
        }
    }
}
