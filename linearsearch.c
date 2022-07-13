/*Linear Search*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}


int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    
    while(1)
    {
		int limit,ch,key;
		long int size,i;
		printf("\n1. Execute Program\n2.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{	
				printf("Enter number of Elements: ");
				scanf("%ld",&size);
				int array[size];
				printf("Enter Upper Limit of Allowed Values in Array (where x is upper limit, the array will be populated with values ranging from 0-x): ");
				scanf("%d",&limit);
				
				long int num=size;
				long int j;
				int temp,flag=0;
				
				srand( (unsigned) time(NULL) * getpid());
				gettimeofday(&t0, NULL);
				if(array != NULL)
				{
					for(j = 0; j < num; j++)
					{
						array[j] = rand()%limit;
					}
				}
				gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
				for(j = 0; j < num; j++)
				{
					printf("%d\t\t",array[j]);
				}				
				printf("\nRandom Generation code executed in %f milliseconds.\n", elapsed);
				printf("Enter element to search for: ");
				scanf("%d",&key);
				gettimeofday(&t0, NULL);
				for(i=0;i<num;i++)
				{
					if(array[i]==key)
					{	
						printf("%d found at position %ld\n",key,i);
						flag++;
						break;
					}
				}
				if(flag==0)
					printf("\nElement not found\n");		
				gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
				printf("Linear Search code executed in %f milliseconds.\n", elapsed);
				break;
			}
			case 2:
			{
				printf("Succesfully exiting program \n");
				exit(0);
			}
			
			default:
			{
				printf("\nError,wrong choice input");
				printf("\n");
				break;
			}
		}
	}
}


