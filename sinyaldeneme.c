
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signum) {
    printf("Sinyal alındı: %d\n", signum);
    exit(signum);
}

int main() {
    int pid = fork();

    if (pid == 0) { // Çocuk süreç
        while(1) {
            printf("Çocuk süreç bekliyor...\n");
            sleep(1);
        }
    } else if (pid > 0) { // Ana süreç
        sleep(5);
        kill(pid, SIGSTOP); // Çocuk sürece SIGSTOP sinyali gönder
        printf("Çocuk sürece SIGSTOP sinyali gönderildi.\n");
    } else {
        printf("Fork işlemi başarısız oldu.\n");
        return 1;
    }

    return 0;
}
*/


/* 

//Bu C programı, birinci işlem ve ikinci işlem arasında bir Unix sinyali (SIGUSR1) kullanarak 
//bir veri değişimini gerçekleştirir.Birinci işlem, ikinci işleme bir tam sayı gönderir ve ikinci işlem bu sinyali alır.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Sinyal işleyicisi
void handle_signal(int signum) {
    // Sinyal işleyicisinde herhangi bir işlem yapmayacağız.
}

int main() {
    // İkinci işlem için pid
    pid_t pid;

    // İkinci işlemi oluştur
    pid = fork();

    if (pid == -1) {
        // Fork başarısız oldu
        perror("Fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // İkinci işlem
        // Sinyal işleyicisini ayarla
        signal(SIGUSR1, handle_signal);

        // Sinyal bekleyerek dur
        while (1) {
            pause();
        }
    } else {
        // Birinci işlem
        int data_to_send = 42;
        printf("İlk işlem: Gönderilen veri: %d\n", data_to_send);

        // İkinci işleme veri gönder
        kill(pid, SIGUSR1);

        // İkinci işlemin işlemesi için biraz bekleyelim
        sleep(1);
    }

    return 0;
}
*/