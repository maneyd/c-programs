#include<stdio.h>
#define len 100
#define num(x) (*(unsigned int *)&mem[x])
#define getbit(x) ((mem[(x/8)] >> (x%8))&1)
#define temp mem[len-1]
#define m mem[len-2]
#define itr mem[len-3]
#define flag mem[len-4]
#define n mem[len-5]
#define ans1 mem[len-6]
#define ans2 mem[len-7]
#define temp2 mem[len-8]
#define min_s mem[len-11]
#define max_s mem[len-12]
#define ans mem[len-13]
#define ans3 mem[len-14]

#define put(x,y) mem[(x/8)] = ( y == 1 ?  mem[(x/8)] | (y << (x%8)) : mem[(x/8)] & (~(y << (x%8))))

#define bit 18

int mem[len] = {0x00,0x00,0x02,0x00,0x0c,0x00,0x38};
	
void main(){
//printf("%d",getbit(10));

	// finding 18 bit minimum number 
	void min(){
		n = 0;
		temp = m = 17;
		m = m + bit;
		while(n < 2){
			itr = 0 ;
			ans1 = 0;
			ans2 = 0;
			flag = 0;
			printf("the shortest number is %d\n",temp);
			printf("the second number is %d\n",m);

				while( itr <= bit-1 && flag == 0){
					ans1 = temp-itr;		// temp-itr = index of minimum no	(msb) 
					ans2 = m-itr;			// ccurrent no index	(msb)

					printf("value at %d is %d \t",temp-itr,getbit(ans1));
					printf("value at %d is %d \t at itr = %d\n",m-itr,getbit(ans2),itr);

					if(getbit(ans1) == getbit(ans2)){
						itr++;
					}
					else if(getbit(ans1) > getbit(ans2)){
						temp = m;
						flag = 1;
					}
					else if(getbit(ans1) < getbit(ans2)){
						flag = 1;
					}
				}
			m = m + bit;
			n = n + 1;
		}
	
	printf("shortest at %d\n",temp); 	// temp = index of minimum no found till now (msb)
	}	
	min();

	void max(){
//		printf("for maxing\n");
		n = 0;
		temp2 = m = bit-1;
		m = m + bit;
		while(n < 2){
			itr = 0 ;
			ans1 = 0;
			ans2 = 0;
			flag = 0;
			printf("the largest number is %d\n",temp2);
			printf("the second number is %d\n",m);

				while( itr <= bit-1 && flag == 0){
					ans1 = temp2-itr;		// temp2 = index of maximum no found till now	(msb)
					ans2 = m-itr;			// current no index (msb)

					printf("value at %d is %d \t",temp2-itr,getbit(ans1));
					printf("value at %d is %d \t at itr = %d\n",m-itr,getbit(ans2),itr);

					if(getbit(ans1) == getbit(ans2)){
						itr++;
					}
					else if(getbit(ans1) < getbit(ans2)){
						temp2 = m;
						flag = 1;
					}
					else if(getbit(ans1) > getbit(ans2)){
						flag = 1;
					}
				}
			m = m + bit;
			n = n + 1;
		}
		printf("largest at %d",temp2);	
	}
	
	max();

	min_s = len * 4 * 8;		// msb of mininum no stored in output 
	max_s = min_s-bit;		// msb of maximum no stored in output
	
	printf("min_s at %d \t max_s at %d\n",min_s,max_s);

	printf("------------putting min----------");
	// for putting the min 
		itr = 0;
		ans1 = 0;
		ans2 = 0;
		while(itr <= bit-1){
			ans1 = min_s-itr;
			ans2 = temp-itr;
			ans3 = getbit(ans2);		// getting bit of temp ( min found till now )
			printf("putting %d in %d \n",getbit(ans2),ans1);
			
			put(ans1,ans3);
			itr = itr + 1;;
		}

	printf("------------putting max----------");
	// for putting the max
		itr = 0;
		ans1 = 0;
		ans2 = 0;
		while(itr <= bit-1){
			ans1 = max_s-itr;
			ans2 = temp2-itr;
			ans3 = getbit(ans2);		// gettgin bit of temp2 ( max foudn till now )
			printf("putting %d in %d \n",getbit(ans2),ans1);
			
			put(ans1,ans3);
			itr = itr + 1;
		}

	printf("------printing min-------\n");
		itr = 0;
		ans = 0;
		while(itr <= bit-1){
			ans = min_s-itr;
			printf("the %d is %d\n",ans,getbit(ans));
			itr = itr + 1;
		}
	printf("------printing max--------\n");
		itr = 0;
		ans = 0;
		while(itr <= bit-1){
			ans = max_s-itr;
			printf("the %d is %d\n",ans,getbit(ans));
			itr = itr + 1;
		}

}
