#include <stdio.h>
#include <stdlib.h>

int main (){

int baris;
int kolom;
// int matriks[100][100];

printf("Masukkan jumlah baris (M) ");
scanf("%d", &baris);
printf("Masukkan jumlah kolom (N) ");
scanf("%d", &kolom);

int **matriks1 = (int **)malloc(baris * sizeof(int *));
for(int i = 0; i < baris ; i++){
  matriks1[i] = (int *)malloc(baris * sizeof(int *));
}

int **matriks2 = (int **)malloc(baris * sizeof(int *));
for(int i = 0; i < baris ; i++){
  matriks2[i] = (int *)malloc(baris * sizeof(int *));
}

printf("\n");

for(int i = 0; i < baris ; i++){
  for(int j = 0; j < kolom ; j++ ){
    printf("Masukkan elemen matriks [%d][%d] = ", i+1, j+1);
    scanf("%d", &matriks1[i][j]);
  }
}

printf("\n");
printf("Matriks ke 1\n");
for(int i = 0; i < baris ; i++){
  for(int j = 0; j < kolom ; j++ ){
    printf("%d ", matriks1[i][j]);
  }
  printf("\n");
}

printf("\n");

for(int i = 0; i < baris ; i++){
  for(int j = 0; j < kolom ; j++ ){
    printf("Masukkan elemen matriks [%d][%d] = ", i+1, j+1);
    scanf("%d", &matriks2[i][j]);
  }
}

printf("\n");
printf("Matriks ke 2\n");
for(int i = 0; i < baris ; i++){
  for(int j = 0; j < kolom ; j++ ){
    printf("%d ", matriks2[i][j]);
  }
  printf("\n");
}
printf("\nHasil penjumlahan matriks\n");
for(int i = 0; i < baris ; i++){
  for(int j = 0; j < kolom ; j++ ){
    printf("%d ", matriks1[i][j] + matriks2[i][j]);
  }
  printf("\n");
}

free(matriks1);
free(matriks2);
// 

  return 0;
}