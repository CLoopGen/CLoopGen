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
extern int pos;
extern int dragon_status_known;
extern int ii;
extern char goal[400];
extern char escape_value[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride (e.g., step by 3) to simulate non-unit stride access,
    // which may be used to explore different cache behaviors or align with data layout assumptions.
    // Also includes minor reordering of conditions for clarity.

    int base = (19 + 2);
    int limit = (19 + 1) * (19 + 1);
    int stride = 3;
    int pos_color = board[pos];

    for (ii = base; ii < limit; ii += stride) {
        // Ensure index is still valid after striding
        if (ii >= limit) break;

        if (board[ii] != 3)
            continue;

        if (dragon_status_known) {
            struct dragon_data *d = &dragon[ii];
            int status = d->crude_status;
            if (status == 1) {
                escape_value[ii] = 6;
            }
            else if (status == 3) {
                struct dragon_data2 *d2 = &dragon2[d->id];
                if (d2->escape_route > 5 || d2->moyo_size > 5) {
                    escape_value[ii] = 4;
                }
            }
        } else {
            if (worm[ii].attack_codes[0] == 0 && board[ii] == pos_color && !goal[ii]) {
                escape_value[ii] = 2;
            }
        }
    }

    // Handle remaining elements not covered by strided access (cleanup pass with step 1)
    for (ii = base + 1; ii < limit; ii++) {
        if (ii % stride == 0) continue; // Skip already processed
        if (board[ii] != 3) continue;

        if (!dragon_status_known && board[ii] == pos_color && !goal[ii] && worm[ii].attack_codes[0] == 0) {
            escape_value[ii] = 2;
        }
    }
}
