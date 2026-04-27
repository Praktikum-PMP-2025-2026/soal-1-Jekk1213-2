/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman
 * Modul            : 03 - Structures and Dynamic Array
 * Hari, Tanggal    : Senin, 27 April 2026       
 * Nama/NIM         : Dzaky Raihan Nugraha/13224062
 * Deskripsi        : Mengurutkan data berdasarkan nama, massa, dan kemurnian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structnya mengenai meteorit mulai dari nama, massa, dan kemurnian
typedef struct {
    char nama[100];
    int massa;
    int kemurnian;
} Meteorit;

//bagian inputin datanya
void inputData(Meteorit ray[], int n){
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            scanf("%s %d %d", ray[i].nama, &ray[i].massa, &ray[i].kemurnian);
        }
    }
}

void tukerMeteorit(Meteorit *a, Meteorit *b) { //proses sorting biasa pakai temp
    Meteorit temp=*a;
    *a=*b;
    *b=temp; 
}

//proses urut-urut biasa kayak bubble sort
void urutMeteorit(Meteorit ray[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(ray[j].kemurnian<ray[j+1].kemurnian){ //bagian ini makin besar makin edan
                tukerMeteorit(&ray[j], &ray[j+1]);
            }
            else if(ray[j].kemurnian==ray[j+1].kemurnian){ //bagian ini justru makin kecil makin edan
                if(ray[j].massa>ray[j+1].massa){
                    tukerMeteorit(&ray[j], &ray[j+1]);
                }
                else if(ray[j].massa==ray[j+1].massa){ //kalau sama run ke proses urutan huruf
                    if(strcomp(ray[j].nama, ray[j+1].nama)>0){
                        tukerMeteorit(&ray[j], &ray[j+1]);
                    }
                }
            }
        }
    }
}

void meteoritDisplay(Meteorit ray[], int n){
    int limit=3;
    if(n<3){
        limit=n; //it means, kalau datanya kurang dari 3, yaudah gt tampilin yg ada
    }
    for(int i=0; i<limit; i++){
        printf("%s %d %d\n", ray[i].nama, &ray[i].massa, &ray[i].kemurnian);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    if(n<=0){
        return 0; // gak ada apa apa maksudnya
    }

    Meteorit *isi=(Meteorit*)malloc(n*sizeof(Meteorit));

    //calling all void CIHUUYYYY
    inputData(isi, n);
    urutinMeteorit(isi, n);
    meteoritDisplay(isi, n);
}
