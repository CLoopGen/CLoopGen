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
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (!(board[pos] != 3))
            continue;
        for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
            switch (p[pos]) {
              case 1:
                target->hashval[i] ^= white_hash[pos][i];
                break;
              case 2:
                target->hashval[i] ^= black_hash[pos][i];
                break;
              default:
                break;
            }
        }
    }
}
