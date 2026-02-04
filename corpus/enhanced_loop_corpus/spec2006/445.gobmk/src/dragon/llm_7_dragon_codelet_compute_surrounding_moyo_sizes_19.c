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
extern int close_black_worms[400][4];
extern int number_close_black_worms[400];
extern int close_white_worms[400][4];
extern int number_close_white_worms[400];
extern struct dragon_data dragon[400];
extern int pos;
extern int k;
extern int moyo_color[400];
extern float territory_value[400];
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_moyo_sizes[400] = {0};
float temp_moyo_values[400] = {0};

for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3))
        continue;
    if (moyo_color[pos] == board[pos])
        continue;

    float t_val = (territory_value[pos] < 1.0f) ? territory_value[pos] : 1.0f;

    if (moyo_color[pos] == 1) {
        for (k = 0; k < number_close_white_worms[pos]; k++) {
            int w = close_white_worms[pos][k];
            int dr = dragon[w].origin;
            int n = (number_close_white_worms[pos] < 5) ? number_close_white_worms[pos] : 5;
            temp_moyo_sizes[dr] += 1.0f / n;
            temp_moyo_values[dr] += t_val / n;
        }
    }
    if (moyo_color[pos] == 2) {
        for (k = 0; k < number_close_black_worms[pos]; k++) {
            int w = close_black_worms[pos][k];
            int dr = dragon[w].origin;
            int n = (number_close_black_worms[pos] < 5) ? number_close_black_worms[pos] : 5;
            temp_moyo_sizes[dr] += 1.0f / n;
            temp_moyo_values[dr] += t_val / n;
        }
    }
}

for (int i = 0; i < 400; i++) {
    moyo_sizes[i] += temp_moyo_sizes[i];
    moyo_values[i] += temp_moyo_values[i];
}
}
