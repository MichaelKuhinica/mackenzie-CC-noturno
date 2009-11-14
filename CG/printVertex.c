#include <stdio.h>

int main(void) {
    int i;
    int numBarcoFaces = 42;

    int BarcoFaces [][3] = {
        {1, 4, 5},
     {3, 0, 21},
     {0, 2, 20},
     {0, 20, 22},
     {21, 0, 22},
     {18, 21, 22},
     {20, 19, 22},
     {19, 18, 22},
     {8, 3, 21},
     {8, 21, 18},
     {2, 9, 19},
     {2, 19, 20},
     {9, 8, 18},
     {9, 18, 19},
     {17, 15, 16},
     {15, 14, 16},
     {10, 11, 17},
     {10, 17, 16},
     {11, 12, 17},
     {12, 15, 17},
     {13, 10, 16},
     {13, 16, 14},
     {12, 13, 14},
     {12, 14, 15},
     {7, 6, 13},
     {7, 13, 12},
     {6, 8, 13},
     {8, 10, 13},
     {9, 7, 11},
     {7, 12, 11},
     {8, 9, 11},
     {8, 11, 10},
     {2, 5, 7},
     {2, 7, 9},
     {4, 3, 8},
     {4, 8, 6},
     {5, 4, 6},
     {5, 6, 7},
     {2, 0, 5},
     {0, 1, 5},
     {0, 3, 1},
     {3, 4, 1},
    };

    float BarcoVertNorms [][3] = {
            {0.04, -0.16, 0.00},
     {-0.22, -0.16, 0.00},
     {0.35, -0.02, -0.12},
     {0.35, -0.02, 0.12},
     {-0.53, -0.02, 0.12},
     {-0.53, -0.02, -0.12},
     {-0.53, 0.00, 0.12},
     {-0.53, 0.00, -0.12},
     {0.35, 0.00, 0.12},
     {0.35, 0.00, -0.12},
     {0.26, 0.00, 0.06},
     {0.26, 0.00, -0.06},
     {-0.44, 0.00, -0.06},
     {-0.44, 0.00, 0.06},
     {-0.44, 0.10, 0.06},
     {-0.44, 0.10, -0.06},
     {0.14, 0.10, 0.06},
     {0.14, 0.10, -0.06},
     {0.35, 0.00, 0.12},
     {0.35, 0.00, -0.12},
     {0.35, -0.02, -0.12},
     {0.35, -0.02, 0.12},
     {0.46, -0.00, 0.00},
    };
    
    for(i=0; i<numBarcoFaces; i++){
            printf("glBegin(GL_POLYGON);\n");
                printf("\tglVertex3f(%f, %f, %f);\n", BarcoVertNorms[BarcoFaces[i][0]][0], BarcoVertNorms[BarcoFaces[i][0]][1], BarcoVertNorms[BarcoFaces[i][0]][2]);
                printf("\tglVertex3f(%f, %f, %f);\n", BarcoVertNorms[BarcoFaces[i][1]][0], BarcoVertNorms[BarcoFaces[i][1]][1], BarcoVertNorms[BarcoFaces[i][1]][2]);
                printf("\tglVertex3f(%f, %f, %f);\n", BarcoVertNorms[BarcoFaces[i][2]][0], BarcoVertNorms[BarcoFaces[i][2]][1], BarcoVertNorms[BarcoFaces[i][2]][2]);
            printf("glEnd();\n");
    }
}
