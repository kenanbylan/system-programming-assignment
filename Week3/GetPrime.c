#include "GetPrime.h"
#include <stdbool.h>

//uint_64 girilen sayı değerinin örn: 3 , 3 için asal kontrolu yapılır.
bool prime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

// GetPrime giirlen sayının asal karşılığını bulmaya yarar.
uint64_t GetPrime(uint16_t value) {
    uint64_t i = 2;
    uint16_t count = 0;
    while (count < value) {
        if (prime(i)) {
            count++;
        }
        if (count == value) {
            return i;
        }
        i++;
    }
    return  i-1; //girilen değere göre bir asal sayi döndürürüz.
}
