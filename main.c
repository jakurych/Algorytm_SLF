#include <stdio.h>

int main() {
    printf("Algorytm SLF\n");
    puts("Podaj ilość wierzchołków");
    int il_w;
    scanf("%d", &il_w);
    puts("Podaj ilość gałęzi");
    int il_g;
    scanf("%d", &il_g);
    int macierz[il_w][il_g];
    puts("Wprowadz binarną macierz incydencji: ");
    int i, j;
    int wyniki[il_w];

    for (j = 0; j < il_w; j++) {
        for (i = 0; i < il_g; i++) {
            //if(i>j)
            printf("Wpisz element na pozycji (%d,%d) (x,y) \n", i + 1, j + 1);
            scanf("%d", &macierz[i][j]);
        }
    }
    puts("Wpisana macierz:");
    for (j = 0; j < il_w; j++) {
        for (i = 0; i < il_g; i++) {
            printf(" %d ", macierz[i][j]);
        }
        printf(" wierzchołek nr %d \n", j + 1);
    }

    //sumowanie
    for (i = 0; i < il_w; i++) {
        wyniki[i] = 0;
    }

    for (j = 0; j < il_w; j++) {
        for (i = 0; i < il_g; i++) {

            wyniki[j] += macierz[i][j];

        }

    }

    puts("\nWierzchołki i ich stopnie:\n");

    for (i = 0; i < il_w; i++) {
        printf("Stopień wierzchołka %d: %d\n", i + 1, wyniki[i]);
    }
    //algorytm kolorowania

    puts("\nKolory wierzchołków:\n");
    int temp = 0;
    int k=1;
    for (i = 0; i < il_w; i++) {
        if (temp < wyniki[i]) {
            printf("Wierzchołek/Kolor: %d / %d\n", i + 1, k+1);
            k++;
        } else if (temp == wyniki[i]) {
            printf("Wierzchołek/Kolor: %d / %d\n", i + 1, k);
        } else if (temp > wyniki[i]) {
            printf("Wierzchołek/Kolor: %d / %d\n", i + 1, k-1);
            k--;
        }
        temp = wyniki[i];


    }


    return 0;
}
