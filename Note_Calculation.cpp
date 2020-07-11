#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

struct Ogrenci{
    int no;
    string adSoyad;
    float vize1;
    float vize2;
    float finall;
    float ort;
};

/*
	Vektoru siralarken, ogrencileri karsilastirmak icin
	onlarin ortalama degerlerini baz aliyoruz.
	Boylece ortalamasi en buyuk olan, en uste cikacak.
*/
bool sirala(const Ogrenci &o1, const Ogrenci &o2)
{
    return o1.ort > o2.ort;
}


/*
	Ogrenci vektorunu parametre olarak alan sinif_ortalamasi fonksiyonu
	vektordeki tum ogrencileri gezip, onlarin ortalamalarini toplam
	degiskeninde sakliyor. Son olarak ise toplam degiskeninin ogrenci
	sayisina bolunmus halini donduruyor.
*/
float sinif_ortalamasi(vector<Ogrenci> &ogrenciler){
    float toplam = 0;
    for(int i = 0; i < ogrenciler.size(); i++){
        toplam += ogrenciler[i].ort;
    }
    return toplam/ogrenciler.size();
}


/*
	standart_sapma fonksiyonu, parametre olarak vektoru ve sinif ortalamasini aliyoruz
	vektordeki tum ogrencilerin ortalamalarindan, sinif ortalamasini cikartiyor
	ve olusan farkin karesini alip sonucu farklarinKareleriToplami degiskeninde sakliyor.
	son olarak, bu degiskeni n-1'e bolup sonucun karekokunu donduruyor.
*/
float standart_sapma(vector<Ogrenci> &ogrenciler, float sinifOrtalamasi){
    float farklarinKareleriToplami = 0;
    for(int i = 0; i < ogrenciler.size(); i++){
        float fark = ogrenciler[i].ort - sinifOrtalamasi;
        farklarinKareleriToplami += (fark * fark);
    }
    return sqrt(farklarinKareleriToplami/(ogrenciler.size()-1));
}


/*
	medyan fonksiyonu, ogrenci vektorunu aliyor. bu fonksiyonu
	vektoru siraladiktan sonra cagirdigimiz icin, medyan hesabinda
	ihtiyac duyulan siralama islemini tekrar yapmaya ihtiyac duymuyoruz.
	eger ogrenci sayisi tek ise, orta indisteki ogrencinin ortalamasini donduruyor.
	eger cift ise, en ortadaki iki degeri toplayip ikiye bolunmus halini donduruyor.
*/
float medyan(vector<Ogrenci> &ogrenciler){
    if(ogrenciler.size()%2 != 0){
        return ogrenciler[ogrenciler.size()/2].ort;
    } else{
        return (ogrenciler[ogrenciler.size()/2-1].ort + ogrenciler[ogrenciler.size()/2].ort) / 2;
    }
}

/*
	yine bu fonksiyonu vektoru siraladiktan sonra cagirdigimiz icin,
	en basarili ogrenci sifirinci indiste yer aliyor.
	bu nedenle sifirinci indisteki ogrencinin degerlerini ekrana yaziyor.
*/
void en_yuksegi_bas(vector<Ogrenci> &ogrenciler){
    std::string adsoyad = ogrenciler[0].adSoyad;
    printf("%d#%s#%.1f#%.1f#%.1f#%.1f", ogrenciler[0].no, adsoyad.c_str(), ogrenciler[0].vize1, ogrenciler[0].vize2, ogrenciler[0].finall, ogrenciler[0].ort);
}

/*
	ustteki ile ayni mantik, en basarisiz olan en sonda yer aldigi icin,
	son indisli ogrencinin bilgilerini ekrana yaziyor.
*/
void en_dusugu_bas(vector<Ogrenci> &ogrenciler){
    std::string adsoyad = ogrenciler[ogrenciler.size()-1].adSoyad;
    printf("%d#%s#%.1f#%.1f#%.1f#%.1f", ogrenciler[ogrenciler.size()-1].no, adsoyad.c_str(), ogrenciler[ogrenciler.size()-1].vize1, ogrenciler[ogrenciler.size()-1].vize2, ogrenciler[ogrenciler.size()-1].finall, ogrenciler[ogrenciler.size()-1].ort);
}

/*
	klasik toString fonksiyonu. parametre olarak aldigi ogrenciler vektorunun
	icini dolasip, tum ogrencilerin degerlerini ekrana basiyor.
*/
void sirayla_ekrana_bas(vector<Ogrenci> &ogrenciler){
    for(int i = 0; i < ogrenciler.size(); i++){
        std::string adsoyad = ogrenciler[i].adSoyad;
        printf("%d#%s#%.1f#%.1f#%.1f#%.1f\n", ogrenciler[i].no, adsoyad.c_str(), ogrenciler[i].vize1, ogrenciler[i].vize2, ogrenciler[i].finall, ogrenciler[i].ort);
    }
}

/*
	harfnotu fonksiyonu, parametre olarak harf notunu hesaplayacagi
	ogrenciyi aliyor, ve gerekli kosullara gore uygun harf notunu string olarak
	donduruyor.
*/
std::string harfnotu(Ogrenci ogr){
    if(ogr.ort >= 90)
        return "AA";
    if(ogr.ort >= 85)
        return "BA";
    if(ogr.ort >= 75)
        return "CB";
    if(ogr.ort >= 70)
        return "CC";
    if(ogr.ort >= 65)
        return "DC";
    if(ogr.ort >= 50)
        return "DD";
    if(ogr.ort >= 0)
        return "FF";
}

int main(int argc, char** argv)
{
	// once ogrenciler vektorumuzu olusturuyoruz
    vector<Ogrenci> ogrenciler;
	
	// ogrenci sayimiz birden basliyor. dosyayi, dolayisiyla ogrencileri okudukca
	// sayiyi arttiracagiz.
    int ogrNo = 1;
	
	// inputten gelen dosyayi ifstream ile actik.
    ifstream dosya(argv[1]);
	
	// input dosyasinin icerdigi satir sayisi boyunca donen dongu
	// her satir donusunde, dosyadaki satiri okuyup line'in icine atiyor
    for(string line; getline(dosya, line); ){
		int no;
        int i;
        std::string noStr = "";
		// satirda # karakteri gorene kadar ilerliyoruz.
		// gordugumuzde, geldigimiz nokta bize ogrenci numarasini verecek.
        for(i = 0; line[i] != '#'; i++){
            noStr += line[i];
        }
		// ogrenci numarasini stringe ceviriyoruz.
        no = atoi(noStr.c_str());

        std::string adSoyad = "";
        int j;
		// az once kaldigimiz # karakterinin bir ilerisinden ilerlemeye devam ediyoruz.
		// bu sefer sirada gorecegimiz #'e kadar olan kisim, bize ad soyad'i verecek.
        for(j = i + 1; line[j] != '#'; j++){
            adSoyad += line[j];
        }

        float vize1;
        std::string vize1Str = "";
        int k;
		// bu sefer # gordugumuzde, vize1 degerini almis olacagiz
        for(k = j + 1; line[k] != '#'; k++){
            vize1Str += line[k];
        }
        vize1 = (float)atoi(vize1Str.c_str());

        float vize2;
        std::string vize2Str = "";
        int l;
		// kaldigimiz yerden vize2 degeri icin devam ediyoruz
        for(l = k + 1; line[l] != '#'; l++){
            vize2Str += line[l];
        }
        vize2 = (float)atoi(vize2Str.c_str());

        float finall;
        std::string finalStr = "";
        int m;
		// son olarak final degeri icin donuyoruz.
		// bu sefer # gorene kadar ilerleyemeyiz.
		// cunku satirin sonunda bir baska # degeri yok. satirin length'i kadar ilerliyoruz.
        for(m = l + 1; m < line.length(); m++){
            finalStr += line[m];
        }
        finall = (float)atoi(finalStr.c_str());
		
		// butun degerleri topladik. ortalamayi hesapliyoruz.
        float ortalama = (vize1 * 20 / 100.0) + (vize2 * 30 / 100.0) + (finall * 50 / 100.0);
		
		// yeni bir ogrenci olusturup, az once buldugumuz degerleri atiyoruz.
        Ogrenci yeniOgrenci;
        yeniOgrenci.no = ogrNo;
        yeniOgrenci.adSoyad = adSoyad;
        yeniOgrenci.vize1 = vize1;
        yeniOgrenci.vize2 = vize2;
        yeniOgrenci.finall = finall;
        yeniOgrenci.ort = ortalama;
		
		// ve ogrencimizi vektorumuze ekliyoruz.
        ogrenciler.push_back(yeniOgrenci);
		
		// son islem, ogrenci sayisini arttirmak.
        ogrNo++;
    }
	
	// dosyayi okuma, ve ogrencileri ekleme islemi bitince
	// ogrencileri, yukarida olusturdugumuz, ortalama degerine gore
	// karsilastiran sirala fonksiyonu yardimiyla siraliyoruz
    std::sort(ogrenciler.begin(), ogrenciler.end(), sirala);
	
	// sinif ortalamasini fonksiyondan cekiyoruz
    float sinifOrtalamasi = sinif_ortalamasi(ogrenciler);
    // standart sapmayi fonksiyondan cekiyoruz
	float standartSapma = standart_sapma(ogrenciler, sinifOrtalamasi);
    // medyani fonksiyondan cekiyoruz
	float medyanDegeri = medyan(ogrenciler);

	// belirtildigi uzere, en basarili ve en basarisiz ogrenciyi ekrana yaziyoruz.
    cout << "Ortalamasi en yuksek olan ogrenci: " << endl;
    en_yuksegi_bas(ogrenciler);
    cout << "\n\nOrtalamasi en dusuk olan ogrenci: " << endl;
    en_dusugu_bas(ogrenciler);
    cout << "\n\n" << endl;

	// ogrencileri basari sirasina gore ekrana yaziyoruz.
    sirayla_ekrana_bas(ogrenciler);
	
	// simdi sira, Sonuclar.dat dosyasini olusturmakta.
	// terminalden gelen dosya ismini, argv[2] ile aliyor, o isimde dosya olusturuyoruz.
    FILE *dosyaOutput = fopen(argv[2], "ab+");
    
	// dosyanin en basina, ortalama, standart sapma ve medyan degerlerini yaziyoruz.
	fprintf(dosyaOutput, "Ort:%.2f Standart Sapma: %.2f Medyan:%.2f\n\n", sinifOrtalamasi, standartSapma, medyanDegeri);
    
	// son olarak, butun ogrencilerin bilgilerini dosyaya ekliyoruz.
	for(int i = 0; i < ogrenciler.size(); i++){
        std::string adsoyad = ogrenciler[i].adSoyad;
        std::string harfNotu = harfnotu(ogrenciler[i]);
        fprintf(dosyaOutput, "%d#%s#%.1f#%.1f#%.1f#%.1f#%s\n", ogrenciler[i].no, adsoyad.c_str(), ogrenciler[i].vize1, ogrenciler[i].vize2, ogrenciler[i].finall, ogrenciler[i].ort, harfNotu.c_str());
    }
}
