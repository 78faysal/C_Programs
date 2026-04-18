#include <stdio.h>

void Enqueue(int *rear, int queue[], int max, int value){
    if(*rear == max - 1){
        printf("Queue Overflow.\n");
    } else{
        queue[++(*rear)] = value;
    }
}

int Dequeue(int *front, int *rear, int queue[]){
    if(*front > *rear){
        printf("Queue Underflow.\n");
        return -1;
    } else{
        int value = queue[(*front)++];
        printf("Item %d removed from the queue.\n", value);
        return value;
    }
}


int main(){
    int queueLength = 0, front = 0, rear = -1, choice = -1;

    printf("Enter the length of your queue: ");
    scanf("%d", &queueLength);
    int queue[queueLength];

    while(choice != 0){
        printf("Enter 1 to Enqueue, 2 to Dequeue or 0 to Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Enter the value you want to Enqueue: ");
            scanf("%d", &value);
            Enqueue(&rear, queue, queueLength, value);
        } else if(choice == 2){
            Dequeue(&front, &rear, queue);
        } else if(choice != 0){
            printf("Invalid choice!, Please try again. \n");
        }
    }

    printf("Queue items are");
    for(int i = front; i<= rear; i++){
        printf(", %d", queue[i]);
    }

    return 0;
}
