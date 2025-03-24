//Hamming code

#include<stdio.h>
int main()
{
	int data[4];
	int cw[7];
	int rev[7];
	int i,c,c1,c2,c3;
	
	printf("Enter the 4 bit dataword:\n");
	for(i=1;i<=4;i++)
		scanf("%d",&data[i]);
		
	cw[3]=data[1];
	cw[5]=data[2];
	cw[6]=data[3];
	cw[7]=data[4];
	
	cw[1]=(cw[3] ^ cw[5] ^ cw[7]);
	cw[2]=(cw[3] ^ cw[6] ^ cw[7]);
	cw[4]=(cw[5] ^ cw[6] ^ cw[7]);
	
	printf("\nGenerated codeword is:\n");
	for(i=1;i<=7;i++)
		printf("%d",cw[i]);
		
	printf("\nEnter the reciver recived data:\n");
	for(i=1;i<=7;i++)
		scanf("%d",&rev[i]);
		
	printf("\n");
	c1=(rev[1] ^ rev[3] ^ rev[5] ^ rev[7]);
	c2=(rev[2] ^ rev[3] ^ rev[6] ^ rev[7]);
	c3=(rev[4] ^ rev[5] ^ rev[6] ^ rev[7]);
	
	c=c1*1+c2*2+c3*4;
	
	if(c==0)
		printf("\nNo error dected in transmission.....");
	else
	{
		printf("\nError found in Position: %d\n",c);
		
		printf("\nData generated bt Seneder: ");
		for(i=1;i<=7;i++)
			printf("%d",cw[i]);
			
		printf("\nData recived on reciver side: ");
		for(i=1;i<=7;i++)
			printf("%d",rev[i]);
			
		printf("\nThe corrected message is: ");
		rev[c]=!rev[c];
		
		for(i=1;i<=7;i++)
		printf("%d",rev[i]);
		
	}
	return 0;
}