/*Binary Search*/
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
		long int size,low,mid,high,i;
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
				long int j,x,y;
				int temp;
				
				srand( (unsigned) time(NULL) * getpid());
				gettimeofday(&t0, NULL);
				if(array != NULL)
				{
					for(j = 0; j < num; j++)
					{
						array[j] = rand()%limit;
					}
				}
				
				for(x = 0; x < num - 1; x++)
				{       
					for(y = 0; y < num - x - 1; y++)
					{          
						if(array[y] > array[y + 1])
						{               
						    temp = array[y];
						    array[y] = array[y + 1];
						    array[y + 1] = temp;
						}
					}
				}
				gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
				for(j = 0; j < num; j++)
				{
					printf("%d\t\t",array[j]);
				}				
				printf("\nRandom Generation code executed, and sorted in %f milliseconds.\n", elapsed);
				printf("Enter element to search for: ");
				scanf("%d",&key);
				low=0;high=size-1;mid=(high+low)/2;
				gettimeofday(&t0, NULL);
				while (low<=high)
				{
					if(array[mid]<key)
						low=mid+1;
						
					else if (array[mid]==key) 
					{
						printf("%d found at position %ld\n",key,mid);
					break;
					}
					else
						high=mid-1;
						
					mid=(low+high)/2;
				}
				if(low>high)
					printf("%d not present\n",key);
				gettimeofday(&t1, NULL);
        			elapsed = timedifference_msec(t0, t1);
				printf("Binary Search code executed in %f milliseconds.\n", elapsed);
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

