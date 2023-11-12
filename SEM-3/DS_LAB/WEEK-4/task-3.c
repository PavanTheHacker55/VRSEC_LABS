#include<stdio.h>
#define mod %
#define SIZE 5
int front = -1, rear = -1;
int queue[SIZE];

int isEmpty();
int isFull();
int enQueue(int);
int deQueue();

int main()
{
	int opt;
	printf("~~~~~~ CIRCULAR QUEUE OPERATIONS ~~~~~\n");
	do {
		printf("1. EN-QUEUE\n2. DE-QUEUE\n3. DISPLAY\n4. EXIT\nEnter Your Choice: ");
		scanf("%d",&opt);
		if(opt == 1){
			int n;
			printf(">> Enter an Element to Insert: ");
			scanf("%d",&n);
			if(enQueue(n)== 1)
				printf(">> Element Inserted Successfully!!\n");
		} else if(opt == 2){
			if(deQueue() != -1)
				printf(">> Element Removed!!\n");
			else
				printf(">> Queue is Empty!!\n");
		} else if(opt == 3){
			printf(">> Elements in Queue: ");
			for(int i = front; i <= rear; i++)
				printf("%d ",queue[i]);
			printf("\n");
			printf(">> Array: ");
			for(int i=0; i<SIZE; i++)
				printf("%d ", queue[i]);
			printf("\n");
			printf(">> CURRENT front = %d, rear = %d\n", front, rear);
		}
	} while(opt != 4);
	return 0;
}

int isEmpty(){
	if (front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int isFull(){
	if((rear+1)/SIZE == front)
		return 1;
	else
		return 0;
}

int enQueue(int n){
	if (isFull())
		return 0;
	else if(isEmpty())
		front = rear = 0;
	else
		// rear++;
		rear = (rear + 1)/SIZE;
	queue[rear] = n;
	return 1;
}

int deQueue(){
	int x;
	if(isEmpty())
		return -1;
	else if(front == rear){
		x = queue[rear];
		front = rear = -1;
		return 1;
	}
	else {
		x = queue[front];
		// front++;
		front = (front+1)/SIZE;
		return 1;
	}
}