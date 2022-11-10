// 1バイト整数を16進数で表示。4バイトごとに空白で区切る。
#include <stdio.h>

void print_bytes(char* ary, int length) {
  int i;
  for (i = 0; i < length; ++i) {
    if(i != 0 && i % 4 == 0) {
      printf(" ");
    }
    printf("%02X", ary[i] & 0xFF);
  }
}

int main() {
  char ary[] = {-128,-100,-50,-25,0,25,50,127};
  print_bytes(ary, 8);
  return 0;
}
