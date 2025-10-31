#include<stdio.h>
#define len 1024 

void main(){

unsigned char mem[len] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

mem[901] = 0;
mem[902] = 0;
mem[903] = 0;
mem[904] = 0;

mem[600] = 0;

//mem[400] 
mem[400] = 0;


while ( mem[600] < 12) {

mem[901] = mem[901] + mem[mem[400]] ;
if(mem[901] <  mem[mem[400]]){
	mem[991] = 1;
}

mem[902] = mem[902] + mem[mem[400]+1] + mem[991];
if(mem[902] <  mem[mem[400]+1]){
	mem[992] = 1;
}

mem[903] = mem[903] + mem[mem[400]+2] + mem[992];
if(mem[903] <  mem[mem[400]+2]){
	mem[993] = 1;
}

mem[904] = mem[904] + mem[mem[400]+3] + mem[993];
if(mem[904] < mem[mem[400]+3]){
	mem[994] = 1;
}

mem[905] = mem[905] + mem[994] ;

mem[600] = mem[600] + 4;

mem[400] = mem[400]+4;

}

printf("%d %d %d %d %d \n", mem[905] , mem[904] , mem[903] , mem[902] , mem[901]);


}
