#include <stdio.h>

#include <inttypes.h>

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


extern int board_size;
extern struct eye_data eye[400];
extern int m;
extern int n;
extern int mini;
extern int maxi;
extern int minj;
extern int maxj;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major traversal, access elements with a fixed stride across the board
    // Simulate a strided access by jumping in steps and using modulo arithmetic to stay within bounds
    int idx;
    for (idx = 0; idx < board_size * board_size; idx += 4) { // Stride of 4
        int m_idx = (idx / board_size) % board_size;
        int n_idx = (idx % board_size);
        if (eye[((19 + 2) + m_idx * (19 + 1) + n_idx)].origin != origin)
            continue;
        if (m_idx < mini)
            mini = m_idx;
        if (m_idx > maxi)
            maxi = m_idx;
        if (n_idx < minj)
            minj = n_idx;
        if (n_idx > maxj)
            maxj = n_idx;
    }
    // Final pass on remaining indices to ensure correctness
    for (idx = 1; idx < board_size * board_size; idx++) {
        if (idx % 4 == 0) continue; // Skip already processed
        int m_idx = (idx / board_size) % board_size;
        int n_idx = idx % board_size;
        if (eye[((19 + 2) + m_idx * (19 + 1) + n_idx)].origin != origin)
            continue;
        if (m_idx < mini)
            mini = m_idx;
        if (m_idx > maxi)
            maxi = m_idx;
        if (n_idx < minj)
            minj = n_idx;
        if (n_idx > maxj)
            maxj = n_idx;
    }
}
