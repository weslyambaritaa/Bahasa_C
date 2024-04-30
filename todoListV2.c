#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTodoList(char **todos, int count, int *notify) {
    if (count > *notify) {
        *notify *= *notify;
    }
    printf("Daftar Todo [%d/%d]:\n", count, *notify);
    if (count == 0) {
        printf("- belum terdapat data yang tersedia!\n");
    } else {
        for (int i = 0; i < count; ++i) {
            printf("%d. %s\n", i + 1, todos[i]);
        }
    }
}

void addTodo(char ***todos, int *count, int *limit) {
    char input[100];
    printf("\nMenambah Todo: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    if (strlen(input) < 6) {
        printf("Gagal melakukan tindakan.\n");
        printf("Todo harus terdiri dari minimal 6 karakter.\n\n");
        return;
    }

    if (*count >= *limit) {
        *limit *= 2;
        *todos = realloc(*todos, *limit * sizeof(char *));
        if (*todos == NULL) {
            printf("Gagal melakukan realokasi memori!\n");
            exit(1);
        }
    }

    (*todos)[*count] = malloc(100 * sizeof(char));
    if ((*todos)[*count] == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }

    strcpy((*todos)[*count], input);
    (*count)++;
    printf("Berhasil melakukan tindakan.\n");
    printf("Todo baru yang ditambahkan '%s'.\n\n", input);
}

void deleteTodo(char ***todos, int *count, int *limit) {
    int choice;
    printf("\nMenghapus Todo\n");
    printf("No todo: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice < 1 || choice > *limit) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n\n", *limit);
    } else if (choice > *count) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo ini belum tersedia.\n\n");
    } else {
        char todo_before[100];
        strcpy(todo_before, (*todos)[choice - 1]);

        free((*todos)[choice - 1]);

        for (int i = choice - 1; i < *count - 1; ++i) {
            (*todos)[i] = (*todos)[i + 1];
        }

        (*count)--;
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah dihapus.\n\n", todo_before);
    }
}

void modifyTodo(char **todos, int count) {
    int choice;

    printf("\nMengubah Todo\n");
    printf("No todo: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice < 1 || choice > count) {
        printf("Gagal melakukan tindakan.\n");
        printf("No todo yang tersedia berada pada rentang 1 sampai %d.\n\n", count);
    } else {
        char todo_before[100];
        strcpy(todo_before, todos[choice - 1]);

        char input[100];
        printf("Ubah todo menjadi: ");
        fgets(input, sizeof(input), stdin);

        size_t length = strlen(input);
        if (input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        if (strlen(input) < 6) {
            printf("Gagal melakukan tindakan.\n");
            printf("Todo harus terdiri dari minimal 6 karakter.\n\n");
            return;
        }

        strcpy(todos[choice - 1], input);
        printf("Berhasil melakukan tindakan.\n");
        printf("Todo '%s' telah diubah menjadi '%s'.\n\n", todo_before, todos[choice - 1]);
    }
}

int main() {
    char **todos = NULL;
    int count = 0;
    int choice;
    int limit = 2;
    int notify= 2 ;

    todos = (char **)malloc(limit * sizeof(char *));
    if (todos == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }

    do {
        printTodoList(todos, count, &notify);
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Ubah Data\n");
        printf("3. Hapus Data\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addTodo(&todos, &count, &limit);
                break;
            case 2:
                modifyTodo(todos, count);
                break;
            case 3:
                deleteTodo(&todos, &count, &limit);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid.\n\n");
                break;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++) {
        free(todos[i]);
    }
    
    free(todos);

    printf("\nMenutup aplikasi!\n");
    return 0;
}
