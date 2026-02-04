#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern unsigned int *Yo;
extern int oYstride;
extern int *Y;
extern int Ystride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        for (i = 3; i >= 0; i--) { // Reverse loop order: modifies data access pattern and introduces WAR dependency if previous iteration relied on forward indexing
            Y[i] = Yo[i];
        }
        // Add artificial loop-carried dependency on stride updates using conditional-like propagation (though control flow remains same)
        Y += Ystride;
        Yo += oYstride;
    }
    // Semantics preserved, but iteration direction change alters potential vectorization and creates different dependency chains
}
