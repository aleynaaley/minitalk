# UNIX
Unix, bir işletim sistemi ailesidir.
Unix, komut satırı arayüzü ve bir dizi komut satırı aracı kullanarak çalışır. Kullanıcılar, dosya yönetimi, işlem yönetimi, ağ iletişimi ve diğer sistem yönetimi görevlerini gerçekleştirmek için bu araçları kullanabilirler.
Unix'in açık kaynaklı birçok türevi bulunmaktadır, en popüler olanlarından biri Linux'tur.
Linux, Unix benzeri bir işletim sistemidir ve genellikle sunucular, masaüstü bilgisayarlar ve diğer cihazlar için kullanılır. Unix ve Unix benzeri işletim sistemleri, bilgisayar bilimleri ve bilgi teknolojileri dünyasında geniş bir kullanım alanına sahiptir.

# Sinyal Nedir?
Unix ve Unix benzeri işletim sistemlerinde sinyaller bulunmaktadır. Sinyaller, işletim sisteminin işlem yönetimi ve iletişimi için önemli bir mekanizmadır. Bir işletim sistemi, bir süreci veya işlemi durdurmak, devam ettirmek, sonlandırmak veya başka eylemler gerçekleştirmek için sinyalleri kullanabilir.
Yani C programlama dilinde sinyaller, işletim sistemi veya kullanıcı tarafından bir programın çalışması sırasında gönderilen, programın normal işleyişini etkileyen olayları temsil eder.
- SIGINT (Ctrl + C): Bu sinyal, kullanıcı programı çalışırken Ctrl + C tuş kombinasyonunu kullanarak programı sonlandırmak için gönderilir.
- SIGSEGV (Segmentation Fault): Bu sinyal, programın bir bellek erişimi hatası (segmentasyon hatası) yapması durumunda gönderilir. Bu genellikle geçersiz bir bellek bölgesine erişmeye çalıştığında veya bellek erişim kısıtlamalarını aştığında gerçekleşir.
- SIGILL (Illegal Instruction): Bu sinyal, bir programın geçersiz bir talimatı çalıştırmaya çalıştığında gönderilir. Bu, genellikle CPU'nun işlemci talimatlarını yanlış yorumladığında veya programın çalışma zamanında uygun olmayan bir talimatı işlemeye çalıştığında meydana gelir.genellikle işletim sistemi veya işlemci tarafından oluşturulan bir sinyaldir ve genellikle programın düzgün çalışmamasının bir sonucudur
- SIGTERM: Bu sinyal, bir programın sonlandırılması için gönderilir. Örneğin, sistem kapatıldığında veya belirli bir işlem sonlandırılmak istendiğinde gönderilebilir.
- SIGKILL: Bu sinyal, bir programı zorla sonlandırmak için gönderilir. Diğer sinyallerden farklı olarak, SIGKILL programın normal sonlandırılmasını beklemeksizin hemen sonlandırır.
- SIGUSR1 ve SIGUSR2 (Kullanıcı Tanımlı Sinyaller): Bu sinyaller, kullanıcı tarafından belirli eylemler için tanımlanabilir. Programın belirli bir noktasında kullanıcı tarafından tanımlanan özel bir eylemi tetiklemek için kullanılabilirler.

# sinyalleri kullanarak veri değişim programı yazmak
 ```bash
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
 ```
