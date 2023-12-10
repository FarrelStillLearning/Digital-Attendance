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

struct nimNamaData {
    int nim;
    char nama[50];
};

struct Dosen {
    char nama[50];
};

struct  dosen[100]{
        {"Liptia Venica. S.T., M.T."},
        {"Dewi Indri Hadi Putri, S.Pd., M.T."},
        {"Suprih Widodo, S.Si., M.T."},
        {"Nadia Tiara Antik Sari, M.Pd."},
        {"Diky Zakaria, S.Pd. M.T."},
        {"Mahmudah Salwa Gianti, S.Si., M.Eng."},
        {"Dewi Indri Hadi Putri, S.Pd., M.T."},
        {"Hisny Fajjrussalam, M.Pd"},
        {"Diky Zakaria, S.Pd. M.T."},
    };

struct nim, nama[MAX_MURID][50]{
        {2312388, "Farrel Shidqi Lazuardi"},
        {2312601, "Andre Saputra"},
        {2310303, "Ilmi Nurwahidah"},
        {2311156, "Riyadhil Haqqy Arifin"},
        {2312169, "Randi Sunarto"},
        {2309650, "Alfarizi Khoerul Rizal"},
    };

char mataKuliah[MAX_KELAS][50] = {
        "Pemrograman Dasar",
        "Dasar Listrik",
        "Teknik Digital",
        "Matematika",
        "Bahasa Inggris",
        "Pengantar TIK",
        "Elektronika Dasar",
        "Fisika Teknik",
        "Pendidikan Agama Islam",
};
