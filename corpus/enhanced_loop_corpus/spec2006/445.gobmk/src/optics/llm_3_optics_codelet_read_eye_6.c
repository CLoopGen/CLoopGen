#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};


struct half_eye_data {
    float value;
    char type;
    int num_attacks;
    int attack_point[4];
    int num_defends;
    int defense_point[4];
};


extern Intersection board[421];
extern int pos;
extern struct eye_data eye[400];
extern struct half_eye_data heye[400];
extern int pos2;
extern int ko_halfeye;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – traverse array with a stride of 3 for irregular access pattern
    // This changes spatial locality and simulates non-sequential cache behavior
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int stride = 3;

    // Use a strided iteration to access memory non-consecutively
    for (pos2 = start; pos2 < end; pos2 += stride) {
        // Ensure we don't go out of bounds in the conditionals
        if ((board[pos2] != 3) && eye[pos2].origin == pos && heye[pos2].type == 2 && heye[pos2].value < 3.) {
            if (ko_halfeye != 0) {
                ko_halfeye = 0;
                break;
            }
            ko_halfeye = pos2;
        }
    }

    // Secondary pass with offset to cover missed indices due to stride
    for (pos2 = start + 1; pos2 < end; pos2 += stride) {
        if ((board[pos2] != 3) && eye[pos2].origin == pos && heye[pos2].type == 2 && heye[pos2].value < 3.) {
            if (ko_halfeye != 0) {
                ko_halfeye = 0;
                break;
            }
            ko_halfeye = pos2;
        }
    }

    // Third pass for full coverage
    for (pos2 = start + 2; pos2 < end; pos2 += stride) {
        if ((board[pos2] != 3) && eye[pos2].origin == pos && heye[pos2].type == 2 && heye[pos2].value < 3.) {
            if (ko_halfeye != 0) {
                ko_halfeye = 0;
                break;
            }
            ko_halfeye = pos2;
        }
    }
}
