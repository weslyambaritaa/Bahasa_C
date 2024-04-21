#include <stdio.h>  
#include <stdlib.h>
#include <time.h>>
 

// int target = 51; 

int tebakan(int n, int target) 
{ 
  if (n == target) 
  { 
    return 1; 
  } 
  else 
  {  
    return 0; 
  } 
}

int main() 
{ 
  // Asumsikan bahwa angka yang harus ditebak adalah 51 

  srand(time(0));
  
  int myGuess, totalGuess = 0; 
  int target = (rand() % 101);



  //if-else statement
    printf("Silahkan tebak angka antara 1 sampai 100:\n");
do{
  scanf("%d", &myGuess);
  totalGuess++;

  if (myGuess < target)
  {
    printf("Angka lebih besar!\n");
  }
 
  else if (myGuess > target)
  {
    printf("Angka lebih kecil!\n");
  }

  else
  {
    printf("Hore, kamu berhasil menebak angka dengan benar.\n");
    break;
  }
} while(1);

    printf("Jumlah tebakan kamu sebanyak: %d\n", totalGuess);
  return 0; 
} 
