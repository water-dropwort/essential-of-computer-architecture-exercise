// コンピュータがビッグエンディアンかリトルエンディアンかを判定する。
#include <stdio.h>

int main()
{
  int x = 0x12345678;
  char* address = (char*)&x;
  int bytevalue;
  int y = 0;
  int i;

  printf("x = 0x%X\n", x, x);

  for(i = 0; i < 4; i++) {
    bytevalue = *(address+i)&0xFF;
    y = (y << 8) | bytevalue;
    printf("[%d] 0x%X\n", address+i, bytevalue);
  }
  return 0;
}
