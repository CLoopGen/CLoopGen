#include <stdio.h>
#include <inttypes.h>

int defend_lib_score[6];
int defend_not_adjacent_lib_score[5];
int defend_capture_score[6];
int defend_atari_score[6];
int defend_save_score[6];
int defend_open_score[5];
int attack_own_lib_score[5];
int attack_string_lib_score[6];
int attack_capture_score[6];
int attack_save_score[6];
int attack_open_score[5];
int params[67];
int k;

void init_vars() {
    for (int i = 0; i < 6; i++) {
        defend_lib_score[i] = 0;
        defend_capture_score[i] = 0;
        defend_atari_score[i] = 0;
        defend_save_score[i] = 0;
        attack_string_lib_score[i] = 0;
        attack_capture_score[i] = 0;
        attack_save_score[i] = 0;
    }

    for (int i = 0; i < 5; i++) {
        defend_not_adjacent_lib_score[i] = 0;
        defend_open_score[i] = 0;
        attack_own_lib_score[i] = 0;
        attack_open_score[i] = 0;
    }

    for (int i = 0; i < 67; i++) {
        params[i] = i * 3;
    }

    k = 0;
}