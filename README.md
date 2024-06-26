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

# Kullanılan Bazı Fonksiyonlar 
# getpid()
 Fonksiyon, çağrılan işlemin kimlik numarasını (process ID veya PID olarak da bilinir) döndürür. Bu işlev, genellikle benzersiz geçici dosya adları oluşturan rutinler tarafından kullanılır.
 ```bash
#include <stdio.h>
#include <unistd.h>

int main(void) {
    // Çağrılan fonksiyonun işlem kimliğini saklamak için değişken
    pid_t process_id;

    // çağrılan fonksiyonun işlem kimliğini döndürecek
    process_id = getpid();

    // İşlem kimliğini yazdırma
    printf("İşlem kimliği: %d\n", process_id);

    return 0;
}

 ```
Bu kod parçası, çalıştırıldığında, çağrılan işlemin işlem kimliğini ekrana yazdırır. Bu işlem kimliği, işletim sistemi tarafından otomatik olarak atanır ve her işlem için benzersizdir. Fonksiyonun döndürdüğü değer pid_t tipindedir, bu tip genellikle unsigned int türünde bir veri tipidir.

# signal()
  Bir sinyalin nasıl işleneceğini belirlemek için kullanılır.
 ```bash

void (*signal(int sig, void (*func)(int)))(int);

 ```
- sig: Sinyal numarasını temsil eder ve SIG makroları ile uyumludur.
- func: Sinyal oluştuğunda çağrılacak fonksiyonu temsil eder. Eğer func SIG_DFL ise, varsayılan işleyici çağrılır. Eğer func SIG_IGN ise, sinyal yok sayılır. Eğer func bir fonksiyona işaret ederse, bir sinyal algılandığında varsayılan fonksiyon (SIG_DFL) çağrılır, ardından func fonksiyonu çağrılır.
Yani sig ile nerede, ne durumda gelen sinyalleri alacağı diğeri func da bu duurmda ne çalışacağını belirler.

 ```
#include <stdio.h>
#include <signal.h>

// Sinyal işleyici fonksiyonu
void signal_handler(int sig) {
    printf("Ctrl+C tuş kombinasyonuna basıldı!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // SIGINT sinyali (Ctrl+C) için işleyiciyi ayarla
    signal(SIGINT, signal_handler);

    // Sonsuz döngü
    while(1) { }

    return 0;
}
 ```
# exit()
 fonksiyonu, bir programın anında sonlandırılmasını sağlar. Bu fonksiyon, <stdlib.h> başlık dosyasında tanımlıdır.
 ```
  void exit(int status);
 ```
Status parametresi, programın sonlandırılma durumunu belirtir. Genellikle, EXIT_SUCCESS veya EXIT_FAILURE makroları kullanılarak bu durum belirtilir. EXIT_SUCCESS programın başarılı bir şekilde tamamlandığını, EXIT_FAILURE ise bir hata oluştuğunu belirtir.
exit() fonksiyonu çağrıldığında, program anında sonlanır ve kontrol işletim sistemine geri döner. Eğer main() fonksiyonu içinde return anahtar kelimesi kullanılarak bir değer döndürülmemişse, exit() fonksiyonu programın sonlandırılması için kullanılır.

# kill ()
  fonksiyonu, bir işlemi belirtilen bir sinyal ile sonlandırmak veya belirli bir işlem grubuna bir sinyal göndermek için kullanılır. Bu fonksiyon, Unix benzeri işletim sistemlerinde kullanılır ve işlem kontrolü için önemlidir.

 ```
  int kill(pid_t pid, int sig);
 ```

- pid, hedef işlemin süreç kimliğini (PID) belirtir.
- sig, gönderilecek sinyalin numarasını belirtir.
Eğer pid parametresi:
- Pozitif bir değer ise, belirtilen PID'e sahip işlem hedeflenir.
- 0 ise, işlem grubundaki tüm süreçlere sinyal gönderilir.
- 1 ise, belirtilen sinyal, çağıran sürecin yetkilendirmeleri ile uyumlu tüm süreçlere gönderilir.
- -pid değeri ile negatif ise, belirtilen işlem grubundaki tüm süreçlere sinyal gönderilir.
sig parametresi ise gönderilecek olan sinyalin numarasını belirtir. Bu sinyal numaraları POSIX standartlarına göre belirlenmiştir. Örneğin, SIGKILL (9) sinyali bir işlemi acilen sonlandırmak için kullanılabilir.

kill() fonksiyonu, işlemi başarılı bir şekilde sonlandırdıysa 0 değerini döndürür. Eğer bir hata oluşursa, -1 değeri döner ve errno değişkenine ilgili hata kodu atanır.


# usleep()
 fonksiyonu, belirli bir miktar zaman boyunca işlemi uyutarak çalışmasını duraklatır.
 ```
 int usleep(useconds_t microseconds);
 ```
- microseconds, uyuma süresini mikrosaniye cinsinden belirtir.
Fonksiyon çağrıldığında, program belirtilen süre boyunca uyur ve ardından işlemlerine devam eder.
(1 saniye = 1000000 mikrosaniye)

# sleep()
sleep() fonksiyonu, bir programın belirli bir süre boyunca çalışmasını duraklatır. Bu süre saniye cinsinden belirtilir.
 ```
unsigned int sleep(unsigned int seconds);
 ```
- seconds, duraklatma süresini saniye cinsinden belirtir.
