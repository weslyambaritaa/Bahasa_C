#include <stdio.h>
#include <string.h>

//prototype Fungsi
void printDaftarTodo(char todos[3][100], int angka);
void tambah(char todos[3][100], int *angka);
void ubah(char todos[3][100], int *angka, int pilih);
void hapus(char todos[3][100], int* angka, int pilih);

int main() {
    char todos[3][100];
    int angka = 0;
    int respond;
    int pilih;

    // Loop utama program
    do {
        printDaftarTodo(todos, angka); // Tampilkan daftar todo

        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &respond);

        // Membersihkan buffer stdin
        getchar();

        if (respond == 1) {
            tambah(todos, &angka);
        } else if (respond == 2) {
            printf("\nMengubah Todo\n");
            printf("No todo: ");
            scanf("%d", &pilih);
            getchar(); // Membersihkan buffer stdin
            ubah(todos, &angka, pilih);
        } else if (respond == 3) {
            printf("\nMenghapus Todo\n");
            printf("No todo: ");
            scanf("%d", &pilih);
            getchar(); // Membersihkan buffer stdin
            hapus(todos, &angka, pilih);
        } 
    } while (respond != 0);
    
    printf("\nMenutup aplikasi!");
    return 0;
}

void tambah(char todos[3][100], int *angka) {
    if (*angka == 3) {
        printf("\nMenambah Todo: Gagal melakukan tindakan.\n");
        printf("Kapasitas penyimpanan telah penuh.\n");
        printf("Silahkan menghapus todo lama terlebih dahulu!\n\n");
        return;
    }

    printf("\nMenambah Todo: ");
    fgets(todos[*angka], 100, stdin);

    // Menghapus karakter newline ('\n') dari string jika ada
    size_t length = strlen(todos[*angka]);
    if (todos[*angka][length - 1] == '\n') {
        todos[*angka][length - 1] = '\0';
    }

    printf("Berhasil melakukan tindakan.\n");
    printf("Todo baru yang ditambahkan '%s'.\n\n",todos[*angka]);

    (*angka)++;
}

void ubah(char todos[3][100], int* angka, int pilih) {
    if (pilih < 1 || pilih > 3) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai 3.\n\n");
    }
    else if (pilih > *angka){
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n\n");
    }
    else {
        // Menyimpan todo sebelumnya
        char todo_sebelumnya[100];
        strcpy(todo_sebelumnya, todos[pilih - 1]);

        printf("Ubah todo menjadi: ");
        fgets(todos[pilih - 1], 100, stdin);

        // Menghapus karakter newline ('\n') dari string jika ada
        size_t length = strlen(todos[pilih - 1]);
        if (todos[pilih - 1][length - 1] == '\n') {
            todos[pilih - 1][length - 1] = '\0';
        }

        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah diubah menjadi '%s'.\n\n", todo_sebelumnya, todos[pilih - 1]);
    }
}

void hapus(char todos[3][100], int* angka, int pilih) {
    if (pilih < 1 || pilih > 3) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai 3.\n\n");
    }
    else if (pilih > *angka){
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n\n");
    }
    else {
        // Menyimpan todo sebelumnya
        char todo_sebelumnya[100];
        strcpy(todo_sebelumnya, todos[pilih - 1]);

        // Geser todos ke kiri untuk menimpa todo yang dihapus
        for (int i = pilih - 1; i < *angka - 1; ++i) {
            strcpy(todos[i], todos[i + 1]);
        }

        // Kurangi panjang array
        (*angka)--;

        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah dihapus.\n\n",todo_sebelumnya);

    }
}

void printDaftarTodo(char todos[3][100], int angka){
    printf("Daftar Todo [%d/3]:\n", angka);
    if (angka == 0) {
        printf("- belum terdapat data yang tersedia!\n");
    } else {
        for (int i = 0; i < angka; ++i) {
            printf("%d. %s\n", i + 1, todos[i]);
        }
    }
}
