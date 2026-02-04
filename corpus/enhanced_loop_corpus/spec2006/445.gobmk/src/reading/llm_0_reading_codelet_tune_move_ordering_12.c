#include <stdio.h>

#include <inttypes.h>

extern int defend_lib_score[6];
extern int defend_not_adjacent_lib_score[5];
extern int defend_capture_score[6];
extern int defend_atari_score[6];
extern int defend_save_score[6];
extern int defend_open_score[5];
extern int attack_own_lib_score[5];
extern int attack_string_lib_score[6];
extern int attack_capture_score[6];
extern int attack_save_score[6];
extern int attack_open_score[5];
extern int params[67];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k1;
for (k1 = 0; k1 < 6; k1++) {
    k = k1;
    defend_lib_score[k] = params[k];
    if (k < 5) {
        defend_not_adjacent_lib_score[k] = params[k + 6];
        defend_open_score[k] = params[k + 29];
        attack_own_lib_score[k] = params[k + 34];
        if (k < 5)
            attack_open_score[k] = params[k + 57];
    }
    defend_capture_score[k] = params[k + 11];
    defend_atari_score[k] = params[k + 17];
    defend_save_score[k] = params[k + 23];
    attack_string_lib_score[k] = params[k + 39];
    attack_capture_score[k] = params[k + 45];
    attack_save_score[k] = params[k + 51];
}
}
