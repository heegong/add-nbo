#include <stdio.h>
#include <stdint.h>
#include <stddef.h>



void swap(uint8_t *a, uint8_t *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


uint32_t ntoh(uint32_t value) {
	uint8_t* p = reinterpret_cast<uint8_t*>(&value);
	swap(p, p + 3);
	swap(p+1, p + 2);
	uint32_t result = *(reinterpret_cast<uint32_t*>(p));
	printf("%d(%x)", result, result);
	return result;
}


int main(int argc, char **argv) {
	char read_buf[2] = "r";

	FILE* fp1 = fopen(argv[1], read_buf);
	FILE* fp2 = fopen(argv[2], read_buf);
	uint32_t args_num1;
	uint32_t args_num2;

	fread((void *)&args_num1, 1, sizeof(uint32_t), fp1);
	fread((void*)&args_num2, 1, sizeof(uint32_t), fp2);

	uint32_t num1 = ntoh(args_num1);

	printf(" + ");
	
	uint32_t num2 = ntoh(args_num2);
	
	
	uint32_t result = num1+num2;
//	printf("%d(0x%x) + %d(%x) = ",args_num1,args_num1,args_num2,args_num2);
	printf(" = %d(%x)\n", result,result);



	return 0; 
}
