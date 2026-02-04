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
    Hashvalue local_hashval[1] = {0};
    int end = (19 + 1) * (19 + 1);
    for (pos = (19 + 2); pos < end; pos++) {
        if (!(board[pos] != 3))
            continue;
        switch (p[pos]) {
          default:
          case 0:
            break;
          case 1:
            for (i = 0; i < (64 / (8 * sizeof(long))); i++)
                local_hashval[i] ^= white_hash[pos][i];
            break;
          case 2:
            for (i = 0; i < (64 / (8 * sizeof(long))); i++)
                local_hashval[i] ^= black_hash[pos][i];
            break;
        }
    }
    for (i = 0; i < (64 / (8 * sizeof(long))); i++)
        target->hashval[i] ^= local_hashval[i];
}
