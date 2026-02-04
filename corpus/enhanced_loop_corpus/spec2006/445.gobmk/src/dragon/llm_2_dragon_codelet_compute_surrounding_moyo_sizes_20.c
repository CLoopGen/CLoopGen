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
    // Variant 1: Consecutive (forward) memory access with pointer arithmetic
    struct dragon_data2 *dptr = dragon2;
    float *ms_ptr = moyo_sizes;
    float *mv_ptr = moyo_values;
    int i;
    for (i = 0; i < number_of_dragons; i++) {
        int origin = dptr->origin;
        int this_moyo_size = (int)(0.01 + ms_ptr[origin]);
        float this_moyo_value = mv_ptr[origin];
        if (this_moyo_size < dptr->moyo_size) {
            dptr->moyo_size = this_moyo_size;
            dptr->moyo_territorial_value = this_moyo_value;
        }
        dptr++;
    }
}
