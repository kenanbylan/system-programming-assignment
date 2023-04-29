#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int fd[2], n;
    pid_t pid;
    char names[10][50];

    // pstudent.txt ve fstudents.txt dosyalarını aç
    FILE *p_file = fopen("pstudent.txt", "r");
    FILE *f_file = fopen("fstudents.txt", "r");
    if (p_file == NULL || f_file == NULL) {
        printf("Dosya açma hatası!\n");
        exit(1);
    }


    for (int i = 0; i < 5; i++) {
        fgets(names[i], 50, p_file);
    }

    for (int i = 10 - 5; i < 10; i++) {
        fgets(names[i], 50, f_file);
    }

    // ogrenciler.txt dosyasını aç
    FILE *o_file = fopen("ogrenciler.txt", "w");
    if (o_file == NULL) {
        printf("Dosya açma hatası!\n");
        exit(1);
    }

    // Boru oluştur
    if (pipe(fd) == -1) {
        printf("Boru oluşturma hatası!\n");
        exit(1);
    }

    // Çocuk işlem oluştur
    pid = fork();
    if (pid < 0) {
        printf("Çocuk işlem oluşturma hatası!\n");
        exit(1);
    }
    if (pid == 0) {  // Çocuk işlem
        // Borudan oku ve ogrenciler.txt dosyasına yaz
        char buf[1024];
        n = read(fd[0], buf, 1024);
        fwrite(buf, sizeof(char), n, o_file);
        fclose(o_file);
        close(fd[0]);
        close(fd[1]);
        exit(0);
    } else {  // Ebeveyn işlem
        // Boruya yaz
        char buf[1024];
        int bytes_written = 0;
        for (int i = 0; i < 10; i++) {
            bytes_written += sprintf(buf + bytes_written, "%s", names[i]);
        }
        write(fd[1], buf, bytes_written);
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
    }

    // Dosyaları kapat
    fclose(p_file);
    fclose(f_file);
    return 0;
}
