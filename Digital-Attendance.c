#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MURID 100
#define MAX_NIM 10000
#define MAX_KELAS 20

struct Mahasiswa {
    char nama[MAX_MURID][50];
    int nim[MAX_MURID];
    char mataKuliah[MAX_MURID][50];
    char waktuHadir[MAX_MURID][30];
    char tanggal[MAX_MURID][50];
    int dataKehadiran[MAX_MURID];
    char dosen[MAX_KELAS][50];
};

struct dataNimNama {
    int nim;
    char nama[50];
};

struct Dosen {
    char nama[50];
};

int pendataanKehadiran(struct Mahasiswa *mhsw, int *nomMhsw, const char *mataKuliah,
                        struct dataNimNama nimNamaMap[], int *nomNimNamaMap, struct Dosen dosenMap[], int *nomDosenMap,
                        int totalMahasiswa, int Pilih);

int tampilkanData(struct Mahasiswa *mhsw, int nomMhsw, const char *pilihMataKuliah, int totalMahasiswa, int Pilih,
                    struct Dosen dosenMap[]);

int main() {
    struct Mahasiswa mhsw;
    int nomMhsw = 0;
    int totalMahasiswa = 29;

struct dataNimNama nimNamaMap[MAX_NIM] = {
        {2312388, "Farrel Shidqi Lazuardi"},
        {2312601, "Andre Saputra"},
        {2310303, "Ilmi Nurwahidah"},
        {2311156, "Riyadhil Haqqy Arifin"},
        {2312169, "Randi Sunarto"},
        {2309650, "Alfarizi Khoerul Rizal"},
    };
    int nomNimNamaMap = sizeof(nimNamaMap) / sizeof(nimNamaMap[0]);
    
struct Dosen dosenMap[MAX_KELAS] = {
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
    int nomDosenMap = sizeof(dosenMap) / sizeof(dosenMap[0]);

char pilihMataKuliah[50];
    printf("Silahkan Mengisi Absensi!\n");
    printf("\nPilih mata kuliah hari ini! (Pilih Menu Matakuliah, 0 untuk keluar):\n");
    printf("1. Pemrograman Dasar \n");
    printf("2. Elektronika Dasar\n");
    printf("3. Matematika Dasar\n");
    printf("4. Bahasa Inggris\n");
    printf("5. Dasar Listrik\n");
    printf("6. Fisika Teknik\n");
    printf("7. Teknik Digital\n");
    printf("8. Pendidikan Agama Islam\n");
    printf("9. Pengantar TIK dan literasi TIK\n");
    
    int Pilih;
    scanf("%d", &Pilih);

    if (Pilih == 0) {
        return 0;
    } else if (Pilih < 1 || Pilih > MAX_KELAS) {
        printf("Pilihan tidak sesuai. Silahkan Pilih Menu Yang Ada.\n");
        return 0;
    }

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
    strcpy(pilihMataKuliah, mataKuliah[Pilih - 1]);

 int nomMhswPerSubject[MAX_KELAS] = {0};

    int exitFlag = 0;
    while (!exitFlag) {
        printf("\nMenu Mata Kuliah: %s\n", pilihMataKuliah);
        printf("1. Melakukan Absensi\n");
        printf("2. Melihat Data Absensi\n");
        printf("3. Kembali ke Menu Pilihan Mata Kuliah\n");

        int subMenuChoice;
        printf("Pilih opsi (1-3): ");
        scanf("%d", &subMenuChoice);

        switch (subMenuChoice) {
            case 1:
                pendataanKehadiran(&mhsw, &nomMhswPerSubject[Pilih - 1], pilihMataKuliah, nimNamaMap, &nomNimNamaMap,
                                   dosenMap, &nomDosenMap, totalMahasiswa, Pilih);
                break;
            case 2:
                tampilkanData(&mhsw, nomMhswPerSubject[Pilih - 1], pilihMataKuliah, totalMahasiswa, Pilih, dosenMap);
                break;
            case 3:
                if (MataKuliah(pilihMataKuliah, &Pilih) == 0) {
                    printf("Terminating the program.\n");
                    exit(0);
                }
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    }

    return 0;
}

int MataKuliah(char *pilihMataKuliah, int *Pilih) {
    printf("\nPilih mata kuliah hari ini! (Pilih Menu Matakuliah, 0 untuk keluar):\n");
    printf("1. Pemrograman Dasar\n");
    printf("2. Elektronika Dasar\n");
    printf("3. Matematika Dasar\n");
    printf("4. Bahasa Inggris\n");

    scanf("%d", Pilih);

    if (*Pilih == 0) {
        return 0;
    } else if (*Pilih < 1 || *Pilih > MAX_KELAS) {
        printf("Pilihan tidak sesuai. Silahkan Pilih Menu Yang Ada.\n");
        return 0;
    }

    char mataKuliah[MAX_KELAS][50] = {
        "Pemrograman Dasar",
        "Elektronika Dasar",
        "Matematika Dasar",
        "Bahasa Inggris",
    };
    strcpy(pilihMataKuliah, mataKuliah[*Pilih - 1]);
    printf("Mata kuliah yang dipilih: %s\n", pilihMataKuliah);

    return 1;
}

int pendataanKehadiran(struct Mahasiswa *mhsw, int *nomMhsw, const char *mataKuliah,
                        struct dataNimNama nimNamaMap[], int *nomNimNamaMap, struct Dosen dosenMap[], int *nomDosenMap,
                        int totalMahasiswa, int Pilih) {

    int nim;
    printf("Masukkan NIM (0 untuk melihat data): ");
    scanf("%d", &nim);

    if (nim == 0) {
        return tampilkanData(mhsw, *nomMhsw, mataKuliah, totalMahasiswa, Pilih, dosenMap);
    }

    for (int i = 0; i < *nomMhsw; i++) {
        if (mhsw->nim[i] == nim && strcmp(mhsw->mataKuliah[i], mataKuliah) == 0) {
            printf("NIM %d sudah terdaftar. Anda Tidak dapat melakukan absensi lagi.\n", nim);
            return 0;
        }
    }

    char nama[50];
    int nimIndex = -1;

    for (int i = 0; i < *nomNimNamaMap; i++) {
        if (nimNamaMap[i].nim == nim) {
            strcpy(nama, nimNamaMap[i].nama);
            nimIndex = i;
            break;
        }
    }

    if (nimIndex == -1) {
        printf("NIM belum terdata.\n");
        return 0;
    }

    if (*nomMhsw >= MAX_MURID) {
        printf("Mahasiswa di kelas ini sudah mencapai batas maksimum.\n");
        return 0;
    }

    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    int currentMinutes = localTime->tm_hour * 60 + localTime->tm_min;

    int startTime = dosenMap[Pilih - 1].waktuAbsensi.jamMulai * 60 + dosenMap[Pilih - 1].waktuAbsensi.menitMulai;
    int endTime = dosenMap[Pilih - 1].waktuAbsensi.jamSelesai * 60 + dosenMap[Pilih - 1].waktuAbsensi.menitSelesai;

    double secondsDifference = difftime(currentTime, mktime(localTime));

    if (currentMinutes >= startTime) {
        if (currentMinutes > endTime) {
            printf("Peringatan: Anda terlambat memasukkan NIM! Data tidak akan masuk ke tampilkan data.\n");
            return 0;
        }

    strftime(mhsw->waktuHadir[*nomMhsw], sizeof(mhsw->waktuHadir[*nomMhsw]), "%H:%M:%S", localTime);
    strftime(mhsw->tanggal[*nomMhsw], sizeof(mhsw->tanggal[*nomMhsw]), "%Y-%m-%d", localTime);

    mhsw->nim[*nomMhsw] = nim;
    strcpy(mhsw->nama[*nomMhsw], nama);
    mhsw->nama[*nomMhsw][sizeof(mhsw->nama[*nomMhsw]) - 1] = '\0';

    strcpy(mhsw->mataKuliah[*nomMhsw], mataKuliah);
    mhsw->dataKehadiran[*nomMhsw] = currentTime;

    printf("Absensi kehadiran untuk %s. NIM: %d\n", mhsw->nama[*nomMhsw], mhsw->nim[*nomMhsw]);

    (*nomMhsw)++;
    } else if (currentMinutes < startTime) {
    printf("Absensi belum dapat dilakukan pada saat ini.\n");
    return 0;
    } 
    return 0;
}

int tampilkanData(struct Mahasiswa *mhsw, int nomMhsw, const char *pilihMataKuliah, int totalMahasiswa, int Pilih,
                  struct Dosen dosenMap[]) {
    printf("\nKehadiran untuk %s (%s):\n", pilihMataKuliah, dosenMap[Pilih - 1].nama);

    printf("| %-30s | %-15s | %-15s | %-30s |\n", "Nama", "NIM", "Tanggal", "Waktu Kehadiran");
    printf("|--------------------------------|-----------------|-----------------|--------------------------------|\n");

    for (int i = 0; i < nomMhsw; i++) {
        if (strcmp(mhsw->mataKuliah[i], pilihMataKuliah) == 0) {
            printf("| %-30s | %-15d | %-15s | %-30s |\n",
                   mhsw->nama[i], mhsw->nim[i], mhsw->tanggal[i], mhsw->waktuHadir[i]);
        }
    }

    printf("|--------------------------------|-----------------|-----------------|--------------------------------|\n");

    printf("\nMahasiswa yang terdata: %d/%d\n", nomMhsw, totalMahasiswa);
    return 1;
}
