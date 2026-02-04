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
int limit = (19 + 1) * (19 + 1);
int offset = (19 + 2);
for (str = offset; str < limit; str++) {
    int board_val = board[str];
    if (board_val != 3 && (board_val == 1 || board_val == 2)) {
        struct dragon_data *d = &dragon[str];
        int owl_stat = d->owl_status;
        if (owl_stat != 4) {
            d->status = owl_stat;
        } else {
            int crude = d->crude_status;
            d->status = (crude == 0 || crude == 2) ? 3 : 1;
        }
    }
}
}
