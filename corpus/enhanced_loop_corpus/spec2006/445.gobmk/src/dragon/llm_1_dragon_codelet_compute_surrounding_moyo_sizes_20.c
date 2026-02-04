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
    if (number_of_dragons > 0) {
        d = 0;
        for (; d < number_of_dragons; d += 2) {
            int idx1 = d;
            int idx2 = d + 1;

            int this_moyo_size1 = (int)(0.01 + moyo_sizes[dragon2[idx1].origin]);
            float this_moyo_value1 = moyo_values[dragon2[idx1].origin];
            if (this_moyo_size1 < dragon2[idx1].moyo_size) {
                dragon2[idx1].moyo_size = this_moyo_size1;
                dragon2[idx1].moyo_territorial_value = this_moyo_value1;
            }

            if (idx2 < number_of_dragons) {
                int this_moyo_size2 = (int)(0.01 + moyo_sizes[dragon2[idx2].origin]);
                float this_moyo_value2 = moyo_values[dragon2[idx2].origin];
                if (this_moyo_size2 < dragon2[idx2].moyo_size) {
                    dragon2[idx2].moyo_size = this_moyo_size2;
                    dragon2[idx2].moyo_territorial_value = this_moyo_value2;
                }
            }
        }
    }
}
