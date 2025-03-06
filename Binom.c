#include <stdio.h>
#include <stdlib.h>

short readBinomLine() {
    short line;
    printf("Please enter a binomial line: ");
    scanf("%hd", &line);
    return line;
}

void Binom(short line) {
    int* BinomArray = (int*)malloc(line * sizeof(int));
    int* FaceBinomArray = (int*)malloc(line * sizeof(int));
    BinomArray[0] = 1;
    short j;

    printf("\n\tBinomial expansion\n");
    for (short i = 1; i <= line; i++) {
        for (short k = 0; k < line - i; k++) {
            printf("  ");
        }

        for (short r = 0; r < i; r++) {
            FaceBinomArray[r] = BinomArray[r];
        }

        for (j = 1; j < i; j++) {
            BinomArray[j] = FaceBinomArray[j - 1] + FaceBinomArray[j];
            BinomArray[i - 1] = 1;
        }

        for (short k = 0; k < j; k++) {
            printf("%4d", BinomArray[k]);
        }
        printf("\n\n");
    }

    free(BinomArray);
    free(FaceBinomArray);
}

int main() {
    Binom(readBinomLine());
    
}
