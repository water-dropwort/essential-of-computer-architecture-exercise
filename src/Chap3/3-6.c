// ASCIIかEBCDICかを判定する
#include <stdio.h>

#define ASCII_A  0x41
#define EBCDIC_A 0xC1

int main(){
  char c = 'A';
  if(c == ASCII_A){
    printf("ASCII");
  }
  else if(c == EBCDIC_A){
    printf("EBCIDC");
  }
  else {
    printf("Other");
  }
  return 0;
}
