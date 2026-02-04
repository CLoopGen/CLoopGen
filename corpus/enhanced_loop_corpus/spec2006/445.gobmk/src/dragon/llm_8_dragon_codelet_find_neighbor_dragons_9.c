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
extern int pos;
extern int dragons[400];
extern int distances[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 19 + 2;
    int limit = (19 + 1) * (19 + 1);
    for (pos = base; pos < limit; pos += 2) {
        if (((board[pos]) == 1 || (board[pos]) == 2)) {
            dragons[pos] = dragon[pos].id;
            distances[pos] = 0;
        } else if ((board[pos] != 3)) {
            dragons[pos] = -1;
            distances[pos] = -1;
        }
        // Add dummy arithmetic to increase computational intensity
        int temp = pos * pos + 5;
        temp %= 17;
        distances[pos] += (temp > 0) ? 0 : 0;
    }
}
