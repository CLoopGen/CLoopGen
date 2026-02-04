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
    int i, j;
    const int N = 19;
    for (i = 1; i < N; i++) {
        for (j = 1; j < N; j++) {
            str = i * (N + 1) + j;
            if (str >= 400) continue;
            if (board[str] != 3) {
                int origin_idx = dragon[str].origin;
                if (origin_idx >= 0 && origin_idx < 400) {
                    dragon[str].status = dragon[origin_idx].status;
                }
            }
        }
    }
}
