#include <stdio.h>
#include <stdint.h>


void DumpHex (void * pData, int byteLen){

    //Bellekteki her baytın adresine uint8_t pointer aracılığıyla erişim yapılabilir hale getirir.
    //Bu sayede, p pointer'ı aracılığıyla bellekteki baytlara erişim yapılabilir.
    uint8_t* p = (uint8_t*)pData;


    printf("The %d bytes starting at %p are: ", byteLen, pData);
    for (int i = 0; i < byteLen; ++i) {
        printf("%02X ", *(p + i)); //uint8_t tipindeki bir sayı iki basamaklı hexadecimal formatında yazarız.
    }
    
    printf("\n");

}

int main() {

    char charVal = '0';
    int32_t intVal = 1;
    float floatVal = 1.0;
    double doubleVal = 1.0;


    typedef struct {
        char charVal;
        int32_t intVal;
        float floatVal;
        double doubleVal;
    } Ex2Struct; Ex2Struct structVal = { '0', 1, 1.0, 1.0 };



    DumpHex(&charVal, sizeof(char));
    DumpHex(&intVal, sizeof(int32_t));
    DumpHex(&floatVal, sizeof(float));
    DumpHex(&doubleVal, sizeof(double));
    DumpHex(&structVal, sizeof(structVal));


    return 0;

}
