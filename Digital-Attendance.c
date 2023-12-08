#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MURID 100
#define MAX_NIM 10000
#define MAX_KELAS 5

struct Mahasiswa {
    char nama[MAX_MURID][50];
    int nim[MAX_MURID];
    char mataKuliah[MAX_MURID][50];
    char waktuHadir[MAX_MURID][30];
    int dataKehadiran[MAX_MURID];
    char dosen[MAX_KELAS][50];
};