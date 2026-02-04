#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int i;
extern int j;
extern int a;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_wp = 0, temp_bp = 0;
    for (j = 1, a = 1; (a <= piece_count); j++) {
        i = pieces[j];
        if (!i)
            continue;
        else
            a++;
        // Introduce temporary variables to eliminate WAW dependency on wp/bp
        switch (board[i]) {
          case 1:
          case 11:
          case 7:
          case 9:
          case 3:
            temp_wp++;
            break;
          case 2:
          case 12:
          case 8:
          case 10:
          case 4:
            temp_bp++;
            break;
        }
        // Only update global counters after checking both
        wp += temp_wp;
        bp += temp_bp;
        temp_wp = 0;
        temp_bp = 0;
        if (wp && bp)
            break;
    }
}
