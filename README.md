# NoteCalculation

In this project, C ++, STL (Standard Template Library) vector class has been applied. The passing average of the students was calculated.

## Not Hesapalama Programı

Bu projede, C ++, STL (Standart Şablon Kütüphanesi) vektör sınıfı uygulanmıştır. Öğrencilerin geçme ortalaması hesaplandı.

- Aşağıda dosya formatı verilen Notlar.dat dosyasının içinde ki bilgileri içerecek şekilde proje oluşturulmuştur.
- C++ programı argüman dosyası olarak “Notlar.dat” dosyasını alıyor. Sonuçları ise “Sonuclar.dat” dosyasına yazıyor.
- C++, STL (Standart Şablon Kütüphanesi) ‘nden vektör sınıfını kullanarak gerçekleştirilmiştir.
- Vektör içerisinde öğrenci nesneleri şu yapıda tutulmuştur.

     ![nesne](https://user-images.githubusercontent.com/66306220/87234177-3737a500-c3d7-11ea-8a32-5381118ab0c9.png)
- Program sınıftaki her öğrencinin geçme ortalamasını hesaplayabiliyor. Ortalama hesabını Vize1=%20, Vize2=%30, Final=%50 olacak şekilde hesaplanmıştır.
- Ortalaması en fazla olan ve en düşük olan öğrencinin bilgilerini ekrana yazdırılmıştır.
-	Ortalamaya göre büyükten küçüğe doğru sıralayıp sıralı listeleyi ekrana yazdırılmıştır.
-	Sınıfın genel ortalaması üzerinden, standart sapması ve medyanı hesaplanmıştır.
-	“Sonuclar.dat” dosyasına ilk satırına bulunan değerleri Ort:50,8 Standart Sapma: 25.28 Medyan:43.75, üçüncü satırdan itibaren ise ortalamaya göre büyükten küçüğe doğru sıralanan sıralı listeyi tüm bilgiler ile birlikte ortalamaları ve harf notlarını da eklenmiştir. 

      (AA:90-100, BA:85-90, BB:80-85, CB:75-80, CC:70-75, DC:65-70, DD:50-60, FF:0-50 aralıklarını baz alınmıştır.)
     
     
      ![notlarvesonuclar](https://user-images.githubusercontent.com/66306220/87234296-32bfbc00-c3d8-11ea-8c36-83ca065bb81c.png)

## Çalıştırma

g++ GNU ortamında derleme yapınız. Dosya adı Note_Calculation.cpp şeklindedir. Örneğin proje Note_Calculation.cpp için program konsoldan aşağıdaki şekilde derlenip çalıştırılabilir. Bu işlem sonunda Proje.exe adında dosya oluşur. Yukarıda istenilen tüm işlemleri gerçekleştirilmiştir.
 ```
>> g++ Note_Calculation.cpp –o Proje 
>> Proje.exe Notlar.dat Sonuclar.dat

 ```
