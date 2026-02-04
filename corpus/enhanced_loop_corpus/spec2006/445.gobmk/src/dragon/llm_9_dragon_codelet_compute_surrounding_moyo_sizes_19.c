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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3))
        continue;
    if (moyo_color[pos] == board[pos])
        continue;

    int adjusted_count = 0;
    float effective_value = (territory_value[pos] < 1.0f) ? territory_value[pos] : 1.0f;

    if (moyo_color[pos] == 1) {
        adjusted_count = (number_close_white_worms[pos] < 6) ? number_close_white_worms[pos] + 1 : 5;
        for (k = 0; k < number_close_white_worms[pos]; k++) {
            int w = close_white_worms[pos][k];
            int dr = dragon[w].origin;
            moyo_sizes[dr] += 2.0f / adjusted_count;
            moyo_values[dr] += effective_value * 1.5f / adjusted_count;
        }
    }
    else if (moyo_color[pos] == 2) {
        adjusted_count = (number_close_black_worms[pos] < 6) ? number_close_black_worms[pos] + 1 : 5;
        for (k = 0; k < number_close_black_worms[pos]; k++) {
            int w = close_black_worms[pos][k];
            int dr = dragon[w].origin;
            moyo_sizes[dr] += 2.0f / adjusted_count;
            moyo_values[dr] += effective_value * 1.5f / adjusted_count;
        }
    }
}
}
