//ERHAN OZDOGAN 160201039


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
int ogrenci_sayisi_bul();
struct ogrenci{

char ad[50];
char soyad[50];
int kayitsirasi;
char ogretim_turu[5];
char no[10];
char adtemp[50];
int sonnumara;
};


int main(){
    baslangic:
    printf("");//Hatayi gideriyor

    clock_t basla, dur;
    restart:
    basla=clock();


    int ogrencisayisi=ogrenci_sayisi_bul();
//Dosya Acildi
    FILE *fp;
    fp=fopen("Proje 2 Kaynak ogrenci listesi.txt","r+");
//dizinin boyutu icin ogrenci sayisi hesaplandi

// struct ogrenci tipinde dizi tanimlandi
 struct ogrenci ogrenciler[ogrencisayisi];

 int i,j,k,z;


  //DOSYADAN ALMA ISLEMI //------------------------------------------------------------------------------------------------------------------

    for(i=0;i<ogrencisayisi;i++){
        fscanf(fp,"%s",ogrenciler[i].no);
        fscanf(fp,"%s",ogrenciler[i].ad);
        fscanf(fp,"%s",ogrenciler[i].soyad);
        fscanf(fp,"%d",&ogrenciler[i].kayitsirasi);
        fscanf(fp,"%s",ogrenciler[i].ogretim_turu);
    }
    fclose(fp);

    int en_buyuk_kayit_sirasi=0;

    for(i=0; i<ogrencisayisi; i++){
        if(ogrenciler[i].kayitsirasi>en_buyuk_kayit_sirasi){
            en_buyuk_kayit_sirasi=ogrenciler[i].kayitsirasi;
        }



    }
printf("2 veya daha fazla ismi gecen kayitlar silindi:\n\n");

//TEKRAR EDEN ISIMLER SILINDI //-----------------------------------------------------------------------------------------------

char yazilan_ad[100];
for(i=0;i<ogrencisayisi;i++){
    for(j=i+1;j<ogrencisayisi;j++){
            Loop:
            if(strcmp(ogrenciler[i].ad,ogrenciler[j].ad)==0 && strcmp(ogrenciler[i].soyad,ogrenciler[j].soyad)==0){

                if(strcmp(yazilan_ad,ogrenciler[j].ad)!=0){
                  printf("%s %s\n",ogrenciler[j].ad, ogrenciler[j].soyad);
                }
                strcpy(yazilan_ad,ogrenciler[j].ad);

                for(k=j;k<ogrencisayisi;k++){
                strcpy(ogrenciler[k].ad,ogrenciler[k+1].ad);
                strcpy(ogrenciler[k].soyad,ogrenciler[k+1].soyad);
                strcpy(ogrenciler[k].ogretim_turu,ogrenciler[k+1].ogretim_turu);
                strcpy(ogrenciler[k].no,ogrenciler[k+1].no);
                ogrenciler[k].kayitsirasi=ogrenciler[k+1].kayitsirasi;
                }
                ogrencisayisi--;
               goto Loop;

            }
        }
     }

//OGRENCI NUMARALARI ATANDI //-------------------------------------------------------------------------------------------------------------

for(i=0;i<ogrencisayisi;i++){
    if(strcmp(ogrenciler[i].no,"-")==0){
            if(strcmp(ogrenciler[i].ogretim_turu,"II")==0){
        ogrenciler[i].sonnumara=1702000+(ogrenciler[i].kayitsirasi);
    }
    else if(strcmp(ogrenciler[i].ogretim_turu,"I")==0){
        ogrenciler[i].sonnumara=1701000+ogrenciler[i].kayitsirasi;
    }
    }
    else{
        ogrenciler[i].sonnumara=atoi(ogrenciler[i].no);
    }
}
    int en_buyuk_bo_numara=0, en_buyuk_io_numara=0;

    for(i=0; i<ogrencisayisi; i++){
        if(ogrenciler[i].kayitsirasi>en_buyuk_kayit_sirasi){
            en_buyuk_kayit_sirasi=ogrenciler[i].kayitsirasi;
        }


        if(strcmp(ogrenciler[i].ogretim_turu,"I")==0){
            if(ogrenciler[i].sonnumara>en_buyuk_bo_numara){
                en_buyuk_bo_numara=ogrenciler[i].sonnumara;
            }
        }
        if(strcmp(ogrenciler[i].ogretim_turu,"II")==0){
            if(ogrenciler[i].sonnumara>en_buyuk_io_numara){
                en_buyuk_io_numara=ogrenciler[i].sonnumara;
            }
        }
    }

  //OGRENCI NUMARALARINA GORE SIRALANDI //------------------------------------------------------------------------------------------------------------

  int tempno, tempksirasi;
  char tempad[50], tempsoyad[50], tempot[5];

  for(i=0; i<ogrencisayisi; i++){
    for(j=0; j<ogrencisayisi; j++){

        if(ogrenciler[i].sonnumara<ogrenciler[j].sonnumara){
            tempno=ogrenciler[i].sonnumara;
            ogrenciler[i].sonnumara=ogrenciler[j].sonnumara;
            ogrenciler[j].sonnumara=tempno;

            strcpy(tempad,ogrenciler[i].ad);
            strcpy(ogrenciler[i].ad,ogrenciler[j].ad);
            strcpy(ogrenciler[j].ad,tempad);

            strcpy(tempsoyad,ogrenciler[i].soyad);
            strcpy(ogrenciler[i].soyad,ogrenciler[j].soyad);
            strcpy(ogrenciler[j].soyad,tempsoyad);

            strcpy(tempot,ogrenciler[i].ogretim_turu);
            strcpy(ogrenciler[i].ogretim_turu,ogrenciler[j].ogretim_turu);
            strcpy(ogrenciler[j].ogretim_turu,tempot);

            tempksirasi=ogrenciler[i].kayitsirasi;
            ogrenciler[i].kayitsirasi=ogrenciler[j].kayitsirasi;
            ogrenciler[j].kayitsirasi=tempksirasi;
        }
    }
  }
//BIRINCI VE IKINCI OGRETIM OGRENCI SAYISI BULMA //--------------------------------------------------------------------------------------

    int birincios=0, ikincios=0;
    for(i=0; i<ogrencisayisi; i++){
    if(strcmp(ogrenciler[i].ogretim_turu,"I")==0){
        birincios++;
    }
    else if(strcmp(ogrenciler[i].ogretim_turu,"II")==0){
        ikincios++;
    }
  }


//OGRENCILERI BIRINCI VE IKINCI OGRETIM OLARAK AYIRMA //---------------------------------------------------------------------------------------------

    struct ogrenci b_ogrenciler[birincios];
    struct ogrenci i_ogrenciler[ikincios];
    k=0, z=0;
    for(i=0; i<ogrencisayisi; i++){
    if(strcmp(ogrenciler[i].ogretim_turu,"I")==0){
        b_ogrenciler[k].sonnumara=ogrenciler[i].sonnumara;
        strcpy(b_ogrenciler[k].ad,ogrenciler[i].ad);
        strcpy(b_ogrenciler[k].soyad,ogrenciler[i].soyad);
        b_ogrenciler[k].kayitsirasi=ogrenciler[i].kayitsirasi;
        strcpy(b_ogrenciler[k].ogretim_turu,ogrenciler[i].ogretim_turu);
        k++;
    }
    else if(strcmp(ogrenciler[i].ogretim_turu,"II")==0){
        i_ogrenciler[z].sonnumara=ogrenciler[i].sonnumara;
        strcpy(i_ogrenciler[z].ad,ogrenciler[i].ad);
        strcpy(i_ogrenciler[z].soyad,ogrenciler[i].soyad);
        i_ogrenciler[z].kayitsirasi=ogrenciler[i].kayitsirasi;
        strcpy(i_ogrenciler[z].ogretim_turu,ogrenciler[i].ogretim_turu);
        z++;
        }
    }

    //BIRINCI VE IKINCI OGRETIMLER  KAYIT SIRALARI VE NUMARALARI GUNCELLENDI //--------------------------------------------------------------------------

    k=0;
    while(i_ogrenciler[k].kayitsirasi==0){
    k++;
    }

    for(i=1;i<ikincios;i++){
            i_ogrenciler[i+k-1].kayitsirasi=i;
            i_ogrenciler[i+k-1].sonnumara=1702000+i_ogrenciler[i+k-1].kayitsirasi;
    }
    FILE *birinci,*ikinci,*port;

ikinci=fopen("Ikinci Ogretimler Sirali.txt","w");
    for(i=0;i<ikincios;i++){
        fprintf(ikinci,"%d\t",i_ogrenciler[i].sonnumara);
        fprintf(ikinci,"%s\t",i_ogrenciler[i].ad);
        fprintf(ikinci,"%s\t",i_ogrenciler[i].soyad);
        fprintf(ikinci,"%d\t",i_ogrenciler[i].kayitsirasi);
        fprintf(ikinci,"%s\n",i_ogrenciler[i].ogretim_turu);
    }
     k=0;
    while(b_ogrenciler[k].kayitsirasi==0){
     k++;
    }
    for(i=1;i<birincios;i++){
            b_ogrenciler[i+k-1].kayitsirasi=i;
            b_ogrenciler[i+k-1].sonnumara=1701000+b_ogrenciler[i+k-1].kayitsirasi;
    }
birinci=fopen("Birinci Ogretimler Sirali.txt","w");
    for(i=0;i<birincios;i++){
        fprintf(birinci,"%d\t",b_ogrenciler[i].sonnumara);
        fprintf(birinci,"%s\t",b_ogrenciler[i].ad);
        fprintf(birinci,"%s\t",b_ogrenciler[i].soyad);
        fprintf(birinci,"%d\t",b_ogrenciler[i].kayitsirasi);
        fprintf(birinci,"%s\n",b_ogrenciler[i].ogretim_turu);
    }

    port=fopen("Tum Ogrenciler Sirali.txt","w");
     for(i=0;i<birincios;i++){
        fprintf(port,"%d\t",b_ogrenciler[i].sonnumara);
        fprintf(port,"%s\t",b_ogrenciler[i].ad);
        fprintf(port,"%s\t",b_ogrenciler[i].soyad);
        fprintf(port,"%d\t",b_ogrenciler[i].kayitsirasi);
        fprintf(port,"%s\n",b_ogrenciler[i].ogretim_turu);
    }
    for(i=0;i<ikincios;i++){
        fprintf(port,"%d\t",i_ogrenciler[i].sonnumara);
        fprintf(port,"%s\t",i_ogrenciler[i].ad);
        fprintf(port,"%s\t",i_ogrenciler[i].soyad);
        fprintf(port,"%d\t",i_ogrenciler[i].kayitsirasi);
        fprintf(port,"%s\n",i_ogrenciler[i].ogretim_turu);
    }



    //YENI OGRENCI GIRISI ISTEME //-----------------------------------------------------------------------------------------------

    printf("\nDersi alan ogrenci sayisi I. ogretim: %d, II. ogretim: %d 'dir.",birincios,ikincios);



    int secim;
    printf("\n\n\nBaska ogrenci eklemek ister misiniz? (Evet:1,  Hayir:0)  ");
    scanf("%d",&secim);


    int n;
    char ad_yeni[50], soyad_yeni[50], ot_yeni[50],kisisayisi[10];

    switch(secim){

    case 0:

    break;

    case 1:
        fp=fopen("Proje 2 Kaynak ogrenci listesi.txt","a+");
        tekrargiris:
        printf("Kac Kisi Ekleyeceksiniz: ");
        scanf("%s",kisisayisi);
        if(atoi(kisisayisi)==0){
            printf("\nYanlis Girdiniz Tekrar Giriniz:\n");
            goto tekrargiris;
        }
        else
            n=atoi(kisisayisi);


        fprintf(fp,"\n");
        for(i=0; i<n; i++){
             printf("\n%d. ogrencinin adini yaziniz: ",i+1);
                scanf("%s",&ad_yeni);

                printf("\n%d. ogrencinin soyadini yaziniz: ",i+1);
                scanf("%s",&soyad_yeni);
                int ayniisim=0;
                for(j=0;j<ogrencisayisi;j++){
                    if(strcmp(ad_yeni,ogrenciler[j].ad)==0 && strcmp(soyad_yeni,ogrenciler[j].soyad)==0){
                    ayniisim=1;
                    break;
                }
                }
                if(ayniisim==1){
                    printf("\nOgrenci Zaten Kayitlidir.\n");
                }
                else if(ayniisim==0){
                        otgiris:
                printf("\n%d. ogrencinin ogretim turunu yaziniz (I veya II): ",i+1);
                scanf("%s",&ot_yeni);
                if(strcmp(ot_yeni,"I")!=0 && strcmp(ot_yeni,"II")!=0){
                    printf("\nYanlis Giris Yaptiniz Tekrar Giriniz !!\n");
                    goto otgiris;
                }

                else if(strcmp(ot_yeni,"I")==0){

                    fprintf(fp,"\n%d   ",en_buyuk_bo_numara+1);
                    fflush(fp);
                    en_buyuk_bo_numara++;

                }

               else if(strcmp(ot_yeni,"II")==0){

                    fprintf(fp,"\n%d   ",en_buyuk_io_numara+1);
                    fflush(fp);
                    en_buyuk_io_numara++;


                }
                fprintf(fp,"%s   ",ad_yeni);
                fflush(fp);

                fprintf(fp,"%s   ",soyad_yeni);
                fflush(fp);

                fprintf(fp,"%d   ",en_buyuk_kayit_sirasi+1);
                fflush(fp);
                en_buyuk_kayit_sirasi++;

                fprintf(fp,"%s   ",ot_yeni);
                fflush(fp);
                }
        }
        goto baslangic;




    break;

    default:

            printf("\nYanlis secim yaptiniz. Ogrenci ekleme islemi pas geciliyor.");
    }

// KULLANICIDAN SINIF SAYISI VE KAPASITE ISTEME OGRENCILERI YERLESTIRME //------------------------------------------------------------------------

    int ssayisi;
    sinif_sayisi_alimi:
    printf("\n\nSinif sayisini giriniz: ");
    scanf("%d",&ssayisi);
    if(ssayisi<1){
        goto sinif_sayisi_alimi;
    }

    int b_siniflar[birincios], i_siniflar[ikincios], b_olusturulan_siniflar[birincios], i_olusturulan_siniflar[ikincios];

    printf("Sinif kapasitelerini en az birinci ve ikinci ogretim ogrenci sayisi kadar giriniz:\n");

    int b_siniftoplami, i_siniftoplami;
    kapasite_alimi:
    b_siniftoplami=0;
    i_siniftoplami=0;

    for(i=0; i<ssayisi; i++){
        printf("%d. sinif icin kapasite: ",i+1);
        scanf("%d",&b_siniflar[i]);
        i_siniflar[i]=b_siniflar[i];

        b_siniftoplami=b_siniftoplami+b_siniflar[i];
        i_siniftoplami=i_siniftoplami+i_siniflar[i];
    }

    if(b_siniftoplami<birincios || i_siniftoplami<ikincios){
        printf("Birinci veya ikinci ogretim ogrenci sayisindan az kapasite girildi. Tekrar girin.\n");
        goto kapasite_alimi;
    }

    int b_kalanogrenci=birincios, i_kalanogrenci=ikincios, temp;
    char dosya_adi[50];



    //  ESKI DOSYALARI SILME  /---------------------------------------------------------------------------------------




    for(i=0; i<birincios; i++){
        sprintf(dosya_adi,"1. ogretim - %d. sinif.txt",i+1);
        remove(dosya_adi);
    }

    for(i=0; i<ikincios; i++){
        sprintf(dosya_adi,"2. ogretim - %d. sinif.txt",i+1);
        remove(dosya_adi);
    }


    //OGRENCILERIN DAGITIMI    /----------------------------------------------------------------------------------------


    dagitim_secimi:

    printf("\n\nOgrencileri esit dagitmak icin: 1, en az sinif dagilimi icin 2 yaziniz: ");
    scanf("%d",&secim);

    switch (secim){

    case 1://ESIT DAGITIM
//------------------Birinci ogretim icin------------------------------
            //Ogrenciler esit bir sekilde dagitildi
            for(i=0; i<birincios; i++){
                b_olusturulan_siniflar[i]=0;
                }

            i=b_kalanogrenci;
            while(i>0){
                for(j=0; j<ssayisi; j++){
                    if(b_olusturulan_siniflar[j] < b_siniflar[j]){
                            if(i>0){
                                b_olusturulan_siniflar[j]++;
                                i--;

                            }
                            /*
                            else{
                                break;
                            }
                            */


                    }

                }
            }
            printf("Esit dagilim sonucu olusan birinci ogretim siniflari: ");
            for(i=0; i<ssayisi; i++){
            printf("%d    ",b_olusturulan_siniflar[i]);
            }


       //Dosyaya yazma------------------
        k=0;
        for(i=0; i<ssayisi; i++){

                sprintf(dosya_adi,"1. ogretim - %d. sinif.txt",i+1);

                FILE *fp;
                fp=fopen(dosya_adi,"w");

                fprintf(fp,"Bu dosyada %d isim yer almali\n\n",b_olusturulan_siniflar[i]);


            for(j=0; j<b_olusturulan_siniflar[i]; j++){


                    fprintf(fp,"%d   ",b_ogrenciler[k].sonnumara);
                    fprintf(fp,"%s   ",b_ogrenciler[k].ad);
                    fprintf(fp,"%s   ",b_ogrenciler[k].soyad);
                    fprintf(fp,"%d   ",b_ogrenciler[k].kayitsirasi);
                    fprintf(fp,"%s\n",b_ogrenciler[k].ogretim_turu);
                    k++;

            }


        }

//----------------------------------------------------------------------

//-------------------ikinci ogretim icin--------------------------------

          //Ogrenciler esit bir sekilde dagitildi
            for(i=0; i<ikincios; i++){
                i_olusturulan_siniflar[i]=0;
                }

            i=i_kalanogrenci;
            while(i>0){
                for(j=0; j<ssayisi; j++){
                    if(i_olusturulan_siniflar[j] < i_siniflar[j]){
                            if(i>0){
                                i_olusturulan_siniflar[j]++;
                                i--;

                            }
                            /*
                            else{
                                break;
                            }
                            */


                    }

                }
            }
            printf("\nEsit dagilim sonucu olusan ikinci ogretim siniflari: ");
            for(i=0; i<ssayisi; i++){
            printf("%d    ",i_olusturulan_siniflar[i]);
            }

        //Dosyaya yazma------------------
        k=0;
        for(i=0; i<ssayisi; i++){

                sprintf(dosya_adi,"2. ogretim - %d. sinif.txt",i+1);

                FILE *fp;
                fp=fopen(dosya_adi,"w");

                fprintf(fp,"Bu dosyada %d isim yer almali\n\n",i_olusturulan_siniflar[i]);


            for(j=0; j<i_olusturulan_siniflar[i]; j++){


                    fprintf(fp,"%d   ",i_ogrenciler[k].sonnumara);
                    fprintf(fp,"%s   ",i_ogrenciler[k].ad);
                    fprintf(fp,"%s   ",i_ogrenciler[k].soyad);
                    fprintf(fp,"%d   ",i_ogrenciler[k].kayitsirasi);
                    fprintf(fp,"%s\n",i_ogrenciler[k].ogretim_turu);
                    k++;

            }


        }

        break;

    case 2://EN AZ SINIFLI DAGITIM
//-----------Birinci ogretim-----------------
        for(i=0; i<ssayisi; i++){
            b_olusturulan_siniflar[i]=0;
            }


        //Sinif kapasiteleri buyukten kucuge dogru siralandi
        for(i=0; i<ssayisi; i++){
            for(j=0; j<ssayisi; j++){
                if(b_siniflar[i]>b_siniflar[j]){
                    temp=b_siniflar[i];
                    b_siniflar[i]=b_siniflar[j];
                    b_siniflar[j]=temp;
                }
            }
        }
        j=0;
        for(i=0; i<ssayisi; i++){
            while(b_kalanogrenci>0){
                if(b_olusturulan_siniflar[j] < b_siniflar[j] && b_kalanogrenci>0){
                    b_olusturulan_siniflar[j]++;
                    b_kalanogrenci--;

                }
                else{
                    j++;
                    break;
                }

            }



        }
        printf("En az sinif dagilim sonucu olusan birinci ogretim siniflari: ");
        for(i=0; i<ssayisi; i++){
        printf("%d     ",b_olusturulan_siniflar[i]);
        }



        //Dosyaya yazma------------------
        k=0;
        for(i=0; i<ssayisi; i++){

                sprintf(dosya_adi,"1. ogretim - %d. sinif.txt",i+1);

                FILE *fp;
                fp=fopen(dosya_adi,"w");

                fprintf(fp,"Bu dosyada %d isim yer almali\n\n",b_olusturulan_siniflar[i]);


            for(j=0; j<b_olusturulan_siniflar[i]; j++){


                    fprintf(fp,"%d   ",b_ogrenciler[k].sonnumara);
                    fprintf(fp,"%s   ",b_ogrenciler[k].ad);
                    fprintf(fp,"%s   ",b_ogrenciler[k].soyad);
                    fprintf(fp,"%d   ",b_ogrenciler[k].kayitsirasi);
                    fprintf(fp,"%s\n",b_ogrenciler[k].ogretim_turu);
                    k++;

            }


        }



//-----------------------------------------------

//-----------Ikinci ogretim--------------------

        for(i=0; i<ssayisi; i++){
            i_olusturulan_siniflar[i]=0;
            }


        //Sinif kapasiteleri buyukten kucuge dogru siralandi
        for(i=0; i<ssayisi; i++){
            for(j=0; j<ssayisi; j++){
                if(i_siniflar[i]>i_siniflar[j]){
                    temp=i_siniflar[i];
                    i_siniflar[i]=i_siniflar[j];
                    i_siniflar[j]=temp;
                }
            }
        }
        j=0;
        for(i=0; i<ssayisi; i++){
            while(i_kalanogrenci>0){
                if(i_olusturulan_siniflar[j] < i_siniflar[j] && i_kalanogrenci>0){
                    i_olusturulan_siniflar[j]++;
                    i_kalanogrenci--;

                }
                else{
                    j++;
                    break;
                }

            }



        }
        printf("\nEn az sinif dagilim sonucu olusan ikinci ogretim siniflari: ");
        for(i=0; i<ssayisi; i++){
        printf("%d     ",i_olusturulan_siniflar[i]);
        }




        //Dosyaya yazma------------------
        k=0;
        for(i=0; i<ssayisi; i++){

                sprintf(dosya_adi,"2. ogretim - %d. sinif.txt",i+1);

                FILE *fp;
                fp=fopen(dosya_adi,"w");

                fprintf(fp,"Bu dosyada %d isim yer almali\n\n",i_olusturulan_siniflar[i]);


            for(j=0; j<i_olusturulan_siniflar[i]; j++){


                    fprintf(fp,"%d   ",i_ogrenciler[k].sonnumara);
                    fprintf(fp,"%s   ",i_ogrenciler[k].ad);
                    fprintf(fp,"%s   ",i_ogrenciler[k].soyad);
                    fprintf(fp,"%d   ",i_ogrenciler[k].kayitsirasi);
                    fprintf(fp,"%s\n",i_ogrenciler[k].ogretim_turu);
                    k++;

            }


        }
//----------------------------------------------

        break;

    default:
        printf("Yanlis secim yaptiniz. Tekrar girin: ");
        goto dagitim_secimi;
    }


    dur=clock();
    printf("\n\n Gecen sure >> %d saniye \n",(dur-basla)/CLOCKS_PER_SEC);



        int restart;
        while(restart !=-1 || restart!=1){
        printf("Cikmak icin -1 Tekrar Etmek icin 1 Giriniz.");
        scanf("%d",&restart);
        if(restart==-1)
            return 0;
        else if(restart == 1)
            goto restart;
        }



return 0;
}



//-------------------------------------------------------------------------------------------------------------
//-------------------------------OGRENCI SAYISI BULAN FONKSIYON------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
int ogrenci_sayisi_bul(){
   //Dosya Acildi
    FILE *fp;
    fp=fopen("Proje 2 Kaynak ogrenci listesi.txt","r");
// Ogrenci Sayisi Bulundu
    int karakterler[200000],ogrencisayisi=1,i=0;
   while(!feof(fp)){
        fscanf(fp,"%c",&karakterler[i]);
        if(karakterler[i]=='\n'){
            ogrencisayisi++;
        }
        i++;

    }
    fclose(fp);

return ogrencisayisi;
}

