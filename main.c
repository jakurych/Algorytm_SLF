#include <stdio.h>
#include <stdbool.h>

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

    puts("\nKolory wierzchołków:");
    puts("(Liczba określa kolor)\n");
    //wynik[i] = stopień grafu
    //znaleźć największą wartość -> przypisać kolor -> znaleźć kolejną największą -> przypisać kolor

    int temp[il_w];
    int a;
    for (i = 0; i < il_w; i++)  //przepisanie tablicy
    {
        temp[i] = wyniki[i];

    }

    for (i = 0; i < il_w - 1; i++) {
        for (j = i + 1; j < il_w; j++) {
            if (temp[i] < temp[j]) {
                a = temp[i];
                temp[i] = temp[j];
                temp[j] = a;
            }
        }
    }
    /*  for (i = 0; i < il_w; ++i) {
          printf("%d\n", temp[i]);
      }*/

    bool exit;
    for (i = 0; i < il_w; i++) {
        exit = true;
        for (j = 0; j < il_w && exit; j++) {
            if (wyniki[i] == temp[j]) {
                printf("Wierzchołek/Kolor: %d/%d \n", i+1, j + 1);
                exit = false;


            }
        }
    }

    return 0;
}
