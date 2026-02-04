#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Intersection board[421];
extern Hashvalue white_hash[400][1];
extern Hashvalue black_hash[400][1];
extern Hash_data *target;
extern Intersection *p;
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access pattern over the board array to simulate non-contiguous memory access.
    // This could model tiling or subsampling behavior. We use a stride of 4 for irregular access.
    int size = (19 + 1) * (19 + 1);
    int stride = 4;
    for (pos = (19 + 2); pos < size; pos += stride) {
        if (!(board[pos] != 3))
            continue;
        switch (p[pos]) {
            case 1:
                for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                    target->hashval[i] ^= white_hash[pos][i];
                }
                break;
            case 2:
                for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                    target->hashval[i] ^= black_hash[pos][i];
                }
                break;
            default:
                break;
        }
        // Handle remaining positions within the stride if near boundary
        for (int offset = 1; offset < stride && (pos + offset) < size; offset++) {
            int curr_pos = pos + offset;
            if (!(board[curr_pos] != 3))
                continue;
            switch (p[curr_pos]) {
                case 1:
                    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                        target->hashval[i] ^= white_hash[curr_pos][i];
                    }
                    break;
                case 2:
                    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                        target->hashval[i] ^= black_hash[curr_pos][i];
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
