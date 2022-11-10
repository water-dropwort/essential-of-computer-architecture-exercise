// 整数を01の2進数で表示する
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x;
  char str[10];
  int bit;
  int bin[32];

  printf("Enter the integer value > ");
  scanf("%s",&str);

  x = atoi(str);
  printf("[DEC] %d\n", x);
  printf("[HEX] %08X\n", x);

  printf("[BIN] ");
  for(bit = 31; bit >= 0; bit--) {
    printf("%d ", (x>>bit)&1);
    if (bit % 4 == 0) {
      printf(" ");
    }
  }
  return 0;
}

