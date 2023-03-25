#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Kenan Baylan 171420005 */

int main(int argc, char *argv[]) {

    int row = 1;
    char line[1000];
    int count = 0;

    //argc ve *argv parametreleri terminalden derlerken alacağımız parametreleri ifade eder.
    if (argc < 3) {
        printf("Usage: program_name search_string file_name\n");
        return 1;
    }

    //programı cli üzerinden derlerken aldığımız parametleri pointera eşitledim.
    char *search_string = argv[1];
    char *file_name = argv[2];

    //testçtxt dosyası üzerinde dosya işlemleri.
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }


    while (fgets(line, 1000, fp) != NULL) {
        /*
         * Strstr() işlevi, string1'deki string2'nin ilk oluşumunun başlangıcına bir işaretçi döndürür.
         * String2 string1'de görünmüyorsa, strstr() işlevi NULL döndürür.
         * String2 sıfır uzunluğa sahip bir dizeye işaret ederse, strstr() işlevi string1'i döndürür.
         */

        char *pos = strstr(line, search_string);
        int col = 1;
        while (pos != NULL) {
            printf("'%s' found at %d.row %d.column.\n", search_string, row, (int)(pos - line + 1));
            pos = strstr(pos + 1, search_string);
            col++;
            count++;
        }
        row++;
    }

    printf("Total %d '%s' were found.\n", count , search_string);

    fclose(fp);
    return 0;
}
