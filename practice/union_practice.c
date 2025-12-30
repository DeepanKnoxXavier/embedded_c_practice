#include<stdio.h>
#include<stdint.h>
union u {
	uint32_t all;
	struct s {
		uint8_t b0;
		uint8_t b1;
		uint16_t hw;
	}s;
};


int main()
{
	union u var;
	var.all=0x12345678;
	printf("value of var.s.b0=%x\n",var.s.b0);
	printf("value of var.s.b1=%x\n",var.s.b1);
    printf("value of var.s.hw=%x\n",var.s.hw);
return 0;
}