#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#define __STDC_FORMAT_MACROS


void insertionSort(uint64_t array[], int N) {

    int i,j;
    uint64_t key; //elemanları alıyoruz.

    for(i = 1; i < N ; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0  && array[j] > key) {
            array[j + 1 ] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;

    }

}



//tek bir N olarak dizi uzunluğu aldım çünkü soruda aynı uzunlukta olduğu varsayıldı.
void copyAndPaste(uint64_t *firstArray, uint64_t *secondArray, int N )  {

    int i = 0;
    for (i = 0; i < N ; i++) {
        secondArray[i] = firstArray[i] ; //ilk arraydeki tüm elemanlar ikinci arraya atıldı.
    }

    insertionSort(secondArray,N);

}

int main() {

    int i;
    //Baslangic arrayi.
    uint64_t firstArray[] = {5, 9, 31, 7, 13, 1, 12, 18, 15, 10};
    int N = sizeof(firstArray) / sizeof(firstArray[0]); //C programlama dilinde count-length gibi ifadeler olmadığı için
    //arrayin boyutunu böyle buldum.

    uint64_t secondArray[N]; //aynı uzunlukta, yeni bir array oluşturuldu.


    printf("**** First Array ****\n");
    for ( i = 0; i < N; ++i) {
        printf("%"PRIu64" ", firstArray[i]);
    }


    copyAndPaste(firstArray,secondArray,N);


    printf("\n**** Second Array ****\n");
    for ( i = 0; i < N; ++i) {
        printf("%"PRIu64" - ",secondArray[i]);
    }


    return 0;
}
