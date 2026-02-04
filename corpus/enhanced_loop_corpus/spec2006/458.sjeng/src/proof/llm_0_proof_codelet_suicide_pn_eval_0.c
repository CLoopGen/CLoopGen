#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int j;
extern int a;
extern int i;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1, a = 1; a <= piece_count; j++) {
        for (int level2 = 0; level2 < 1; level2++) { // Artificially increased nesting depth
            i = pieces[j];
            if (!i)
                continue;
            else
                a++;
            switch (board[i]) {
              case 1:
              case 11:
              case 7:
              case 5:
              case 9:
              case 3:
                wp++;
                break;
              case 2:
              case 12:
              case 8:
              case 6:
              case 10:
              case 4:
                bp++;
                break;
            }
            if (wp && bp)
                break;
        }
        if (wp && bp)
            break;
    }
}
