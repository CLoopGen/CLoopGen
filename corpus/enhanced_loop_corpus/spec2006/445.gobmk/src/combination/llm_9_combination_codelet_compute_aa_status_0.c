#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct worm_data {
    int color;
    int size;
    float effective_size;
    int origin;
    int liberties;
    int liberties2;
    int liberties3;
    int liberties4;
    int lunch;
    int cutstone;
    int cutstone2;
    int genus;
    int inessential;
    int invincible;
    int unconditional_status;
    int attack_points[10];
    int attack_codes[10];
    int defense_points[10];
    int defense_codes[10];
    int attack_threat_points[10];
    int attack_threat_codes[10];
    int defense_threat_points[10];
    int defense_threat_codes[10];
};


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
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern int aa_status[400];
extern  char safe_stones[400];
extern int other;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = (19 + 1) * (19 + 1);
int step = 1;
for (pos = (19 + 2); pos < limit; pos++) {
    int board_val = board[pos];
    int status_cond = (board_val == other);
    int not_three = (board_val != 3);
    
    if (status_cond) {
        if (safe_stones) {
            char stone_val = safe_stones[pos];
            aa_status[pos] = (stone_val != 0) ? 1 : 0;
        } else {
            int d_status = dragon[pos].status;
            if (d_status == 0)
                aa_status[pos] = 0;
            else if (d_status == 2)
                aa_status[pos] = 2;
            else if (worm[pos].attack_codes[0] != 0) {
                aa_status[pos] = (worm[pos].defense_codes[0] != 0) ? 2 : 0;
            } else
                aa_status[pos] = 1;
        }
    } else if (not_three) {
        aa_status[pos] = 3;
    }
    
    pos += step - 1; // Neutral adjustment, keeps linear flow but adds arithmetic
}
}
