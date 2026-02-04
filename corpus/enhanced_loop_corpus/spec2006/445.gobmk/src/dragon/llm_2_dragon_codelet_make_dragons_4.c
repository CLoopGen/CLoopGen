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


extern Intersection board[421];
extern struct dragon_data dragon[400];
extern int str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal using a temporary pointer to improve spatial locality
    struct dragon_data *d_ptr = dragon + (19 + 2);
    Intersection *b_ptr = board + (19 + 2);
    for (int idx = (19 + 2); idx < (19 + 1) * (19 + 1); idx++) {
        if (*(b_ptr++) != 3) {
            struct dragon_data *dd = d_ptr;
            *d_ptr = dragon[dd->origin];
        }
        d_ptr++;
    }
}
