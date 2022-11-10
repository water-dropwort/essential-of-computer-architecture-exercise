// 8ビットで可能なすべての2進数と2の補数表現を表示
#include <stdio.h>

#define BIT_SIZE 8
#define BIT_LEN 1 << BIT_SIZE

// 0埋めで2進数表示
void print_binary(int x) {
  int bit;
  char c;
  for(bit = BIT_SIZE-1; bit >= 0; bit--) {
    c = ((x >> bit & 1) == 1) ? '1' : '0';
    printf("%c",c);
  }
}

// BIT_SIZEの桁のビットを2の補数で解釈する
int to_comp_of_2(int x) {
  if((x >> BIT_SIZE-1 & 1) == 1) {
    return -(~(x-1) & ~(0xFFFFFFFF << BIT_SIZE));
  }
  else {
    return x;
  }
}

int main() {
  int bits[BIT_LEN];
  int bit;
  int i;

  for(i = 0; i < BIT_LEN; i++) {
    bits[i] = 0;
  }
  for(bit = 0; bit < BIT_SIZE; bit++) {
    for(i = 0; i < (1 << (bit+1)); i++) {
      if (i >= (1 << bit)) {
        bits[i] = bits[i-(1 << bit)] | (1 << bit);
      }
    }
  }

  for(i = 0; i < BIT_LEN; i++){
    print_binary(bits[i]);
    printf(" %d\n", to_comp_of_2(bits[i]));
  }
  return 0;
}
