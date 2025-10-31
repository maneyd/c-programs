#include<stdio.h>

#define len 100
#define num(x) (*(unsigned int*)&mem[x])		// reads the 4 byte number
#define temp (*(unsigned int*)&mem[len-4])	
#define no mem[len-5]					// number of integer
#define m mem[len-6]					// bits that have been seen
#define byte mem[len-7]					
#define bit_sft mem[len-8]				// to shift a byte by bits
#define max (*(unsigned int*)&mem[len-12])		// to store max found
#define min (*(unsigned int*)&mem[len-16])		// to store min found
#define min_s (*(unsigned int*)&mem[len-20])		// start of min in the stored output
#define max_s (*(unsigned int*)&mem[len-24])		// start of max in the stored output
#define bit 18						// number of bits
									
unsigned char mem[len] = {0x01,0x00,0x02,0x00,0x00,0x50,0xff,0x00,0x00};

void main(){
	no = 4;		//number of integers
	m = 0;
	byte = 0;
	bit_sft = 0;
	max = 0;	
	min = ~0;
			
	while(m < no*bit+1){
		temp = num(byte) >> bit_sft;
		temp = (temp << (32-bit) ) >> (32-bit);
		printf("temp = %d\n",temp);

			if(min > temp){
				min = temp;
			}
			else if(max < temp){
				max = temp;
			}

		m = m + bit;
		byte = m / 8;		
		bit_sft = m % 8;
	}

	printf("min %d\n",min);
	printf("max %d\n",max);	

	min_s = len * 4; 	// 100 * 4 = 400			
	min_s -= 4;		// at 396 to store minimum
	num(min_s) = min ;

	max_s = min_s - 4;	// at 392 to store maximum
	num(max_s) = max ;

	printf("%d\n",num(min_s));
	printf("%d\n",num(max_s));
}	
