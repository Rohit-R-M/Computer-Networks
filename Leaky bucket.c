#include<stdio.h>
#include<unistd.h>

int main() 
{
    int bucket ;
    int n;
    int output = 20;
    int i, size;
    int currentBucket = 0;
    
    printf("Enter the bucket size:\n");
		scanf("%d",&bucket);

    printf("Enter the number of packets:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter the size of packet %d: ", i + 1);
        scanf("%d", &size);

        if (size <= (bucket - currentBucket)) 
        {
            currentBucket += size;
            printf("Current bucket size: %d\n",currentBucket);
        } 
        else 
        {
            printf("Packet of size %d is dropped. Not enough space in the bucket.\n", size);
        }

        if (currentBucket > 0) 
        {
            int sent = (currentBucket < output) ? currentBucket : output;
            currentBucket -= sent;
            printf("Sent %d units. Current bucket size after sending: %d\n", sent, currentBucket);
        } 
        else 
        {
            printf("No packets to send.\n");
        }

        sleep(1);
    }
    while(currentBucket!=0)
    {	
		if(currentBucket<=bucket)
		{
			printf("Remaing packet is transmited of size %d \n",currentBucket);
			currentBucket=0;
		}
		else
		{
			printf("Remaing packet is of size %d \n",currentBucket);
			
			int r = currentBucket-bucket;
			printf("Transmitted packet :%d \n",r);
		}
	}
    printf("Final bucket size: %d\n", currentBucket);
    return 0;
}
