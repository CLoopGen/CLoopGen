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


extern Intersection board[421];
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern struct dragon_data2 *dragon2;
extern int color;
extern char safe_stones[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1) - 10; ii++) {
        Intersection b_val = board[ii];
        if ((b_val == 1 || b_val == 2)) {
            int d_id = dragon[ii].id;
            struct dragon_data2 *d2_ptr = &dragon2[d_id];
            int d_safety = d2_ptr->safety;
            int condition_met = 0;

            if (d_safety == 5)
                condition_met = 1;
            else if (worm[ii].inessential) {
                if ((d_safety != 0 && d_safety != 6 && d_safety != 2) ||
                    (d_safety == 2 && b_val == color))
                    condition_met = 1;
            }

            if (condition_met)
                safe_stones[ii] = 1;
            else
                safe_stones[ii] = 0; // Additional computation: explicit reset
        } else {
            safe_stones[ii] = 0;
        }
    }
    // Artificially increase computational load with a small unrolled secondary pass
    for (int jj = (19 + 2); jj < (19 + 2) + 5; jj++) {
        if (safe_stones[jj] && dragon2[dragon[jj].id].weakness > 0.5f)
            safe_stones[jj] = 0;
    }
}
