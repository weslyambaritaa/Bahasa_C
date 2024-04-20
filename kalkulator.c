#include <stdio.h>

int main () {

char operator;
double angka1;
double angka2;
double hasil;

printf("masukkan operator (+ - * /)\n");
scanf("%c",&operator);

printf("masukkan angka pertama\n");
scanf("%lf",&angka1);

printf("masukkan angka kedua\n");
scanf("%lf",&angka2);

switch(operator){
  case '+':
    hasil = angka1 + angka2;
    printf("hasil = %lf\n",hasil);
    break; 
  case '-':
    hasil = angka1 - angka2;
    printf("hasil = %lf\n",hasil);
    break;
  case '*':
    hasil = angka1 * angka2;
    printf("hasil = %lf\n",hasil);
    break;
  case '/':
    hasil = angka1 / angka2;
    printf("hasil = %lf\n",hasil);
    break;
  default:
  printf("anda memasukkan operator yang tidak valid");
}

  return 0;
}