#include <inttypes.h>

int LevelScale4x4Luma_Intra[6][4][4];
int LevelScale4x4Chroma_Intra[2][6][4][4];
int LevelScale4x4Luma_Inter[6][4][4];
int LevelScale4x4Chroma_Inter[2][6][4][4];
int InvLevelScale4x4Luma_Intra[6][4][4];
int InvLevelScale4x4Chroma_Intra[2][6][4][4];
int InvLevelScale4x4Luma_Inter[6][4][4];
int InvLevelScale4x4Chroma_Inter[2][6][4][4];

const int quant_coef[6][4][4] = {
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    },
    {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    },
    {
        {33, 34, 35, 36},
        {37, 38, 39, 40},
        {41, 42, 43, 44},
        {45, 46, 47, 48}
    },
    {
        {49, 50, 51, 52},
        {53, 54, 55, 56},
        {57, 58, 59, 60},
        {61, 62, 63, 64}
    },
    {
        {65, 66, 67, 68},
        {69, 70, 71, 72},
        {73, 74, 75, 76},
        {77, 78, 79, 80}
    },
    {
        {81, 82, 83, 84},
        {85, 86, 87, 88},
        {89, 90, 91, 92},
        {93, 94, 95, 96}
    }
};

const int dequant_coef[6][4][4] = {
    {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    },
    {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}
    },
    {
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 3, 3}
    },
    {
        {4, 4, 4, 4},
        {4, 4, 4, 4},
        {4, 4, 4, 4},
        {4, 4, 4, 4}
    },
    {
        {5, 5, 5, 5},
        {5, 5, 5, 5},
        {5, 5, 5, 5},
        {5, 5, 5, 5}
    },
    {
        {6, 6, 6, 6},
        {6, 6, 6, 6},
        {6, 6, 6, 6},
        {6, 6, 6, 6}
    }
};

int i;
int j;
int k;

void init_vars() {
    for (int k = 0; k < 6; k++) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                LevelScale4x4Luma_Intra[k][j][i] = 0;
                InvLevelScale4x4Luma_Intra[k][j][i] = 0;
                LevelScale4x4Chroma_Intra[0][k][j][i] = 0;
                InvLevelScale4x4Chroma_Intra[0][k][j][i] = 0;
                LevelScale4x4Chroma_Intra[1][k][j][i] = 0;
                InvLevelScale4x4Chroma_Intra[1][k][j][i] = 0;
                LevelScale4x4Luma_Inter[k][j][i] = 0;
                InvLevelScale4x4Luma_Inter[k][j][i] = 0;
                LevelScale4x4Chroma_Inter[0][k][j][i] = 0;
                InvLevelScale4x4Chroma_Inter[0][k][j][i] = 0;
                LevelScale4x4Chroma_Inter[1][k][j][i] = 0;
                InvLevelScale4x4Chroma_Inter[1][k][j][i] = 0;
            }
        }
    }
    i = 0;
    j = 0;
    k = 0;
}