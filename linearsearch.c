/* Implement a program to perform linear search and binary search*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long n,j,i,k,min,mid,num;
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
};
int linearsearch(long list[num],int key);
int binarysearch(long list[num], int key);
void main()
{
	struct timeval t0;
   	struct timeval t1;
  	float elapsed;
	int ch, key;
	long list[num];
	while(1)
	{
		printf("\n1. Select Array Size and Fill with Random Values\n2.Linear Search\n3. Binary Search\n4. Display Array Values\n5. Sort Array Values\n6. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter Desired Array Size: ");
				scanf("%ld",&num);
				n=num-1;
    				srand( (unsigned) time(NULL) * getpid());
    				if(list != NULL)
    				{
        				for(j = 0; j < n; j++)
        				{
            					list[j] = rand()%100;
        				}
    				}
    				printf("\nArray created and filled with %ld random values\n",num);
    				break;
    			}
    			case 2:
    			{
				printf("\nEnter Value(0-100) to Search for: ");
				scanf("%d",&key);
				gettimeofday(&t0, NULL);
				if(linearsearch(list[num],key))
					printf("\nValue found at position %ld\n",i);
				else
					printf("\nValue not found\n");
				gettimeofday(&t1, NULL);
   				elapsed = timedifference_msec(t0, t1);
   				printf("Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			case 3:
			{
				printf("\nEnter Value(0-100) to Search for: ");
				scanf("%d",&key);
				gettimeofday(&t0, NULL);
				if(binarysearch(list,key))
					printf("\nValue found at position %ld\n",i);
				else
					printf("\nValue not found\n");
				gettimeofday(&t1, NULL);
   				elapsed = timedifference_msec(t0, t1);
   				printf("Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			case 4:
			{
				printf("\nDisplaying all Elements..\n");
				for(i=0;i<n;i++)
					printf("\t%ld",list[i]);
				break;
			}
			case 5:
			{
				for(i=0;i<n-1;i++)
				{
					min=i;
					for(k=i+1;k<n;k++)
					{		
						if(list[j]<list[min])
							min=j;
					}
					if(min!=i)
					{	
						int temp;
						temp=list[i];
						list[i]=list[min];
						list[min]=temp;
					}
				}
				printf("\nElements of Array Sorted in Ascending Order\n");
				break;
			}
			case 6:
			{
				printf("\nGoodbye\n");
				exit(0);
			}
			default:
			{
				printf("\nInvalid Choice\n");
				break;
			}
		}
	}
}
int linearsearch(long list[num], int key)
{
	for(i=0;i<n;i++)
	{
		if(list[i]==key)
			return i;
	}
	return 0;
}
int binarysearch(long list[num], int key)
{
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(list[mid]==key)
			return mid;
		else if(list[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	return 0;
}				
				
			
	

	
		

