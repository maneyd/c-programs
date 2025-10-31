#include<stdio.h>

#define len 10000
#define no(x) (*(unsigned int*) &mem[x])
#define value (*(unsigned int *)&mem[len-4])
#define v (*(unsigned int*)&mem[len-8])
#define itr mem[len-9]
#define m (*(unsigned int*)&mem[len-48])
#define ts mem[len-20]
#define t mem[len-31]
#define max 10
#define n mem[len-32]
#define o (*(unsigned int*)&mem[len-36])
#define os (*(unsigned int*)&mem[len-40])
#define i (*(unsigned int*)&mem[len-44])

unsigned char mem[len] = {0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x05,0x00,0x00,0x00};

void main(){
	n = 5;		// for nos in the array
	m = 0;		// iterator 	
	ts = 9;		// temp's starting point
	o = n*4+1;	// storing the output  from here
	os = o;		// start of output
	i = 1;
	
	while(i<=n){	// (i <= n)
	printf("m is at %d\n",m);
	value = no(m);		// storing the value in 4 bytes
	printf("The current number is :%d\n",value);
	m = m + 4;

	mem[o] = i+48;
	o++;
        mem[o] = 58;
	o++;

	itr = 0;	
	while(value>0){
		t = value%10;
		mem[ts-itr] = t+48;
		itr++;
		value = value / 10;
	}

	while(ts-itr!=ts){
		mem[o]=mem[ts-itr+1];
	//	printf("at %d value is %c\n",o,mem[o]);
		itr--;
		o++;
	}
	
	mem[o] = 10;
	o++;

	//m = m + 4;
	i = i + 1;
	}

	mem[o] = '\0';
	o++;

	printf("\nthe output is :%s\n",&mem[os]);
	
}
