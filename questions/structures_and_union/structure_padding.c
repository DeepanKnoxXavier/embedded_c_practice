
#include <stdio.h>
#include <stdint.h>
#pragma pack(1)
struct s1 {
  uint16_t var1;
  uint8_t var3;
  uint32_t var2;
};


struct s2 {
  uint16_t var1;
  uint16_t var3;
  uint32_t var2;
};

int main()
{
  printf("Size of structure s1: %d\n", sizeof(struct s1));
  printf("Size of structure s2: %d\n", sizeof(struct s2));

  return 0;
}