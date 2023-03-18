#include "GetPrime.h"
#include <stdio.h>

/*
 * Kenan Baylan 171420005 Odev ile ilgili detaylar komut satırları ile verilmiştir.
 
 */

int main() {
    uint16_t val, getValue;
    printf("Asal karşılığını bulmak için bir sayi giriniz: ");
    scanf("%hu", &val);  //shell üzerinden alınan sayi tutulur.

    getValue = GetPrime(val);
    printf("GetPrime(%u) = %d\n", val, getValue);

    return 0;
}
