#include <stdio.h>

int queueLength = 0, front = 0, rear = -1, choice = -1;

void Enqueue(int queue[], int value){
    if(rear == queueLength - 1){
        printf("Queue Overflow.\n");
    } else{
        printf("%d has been enqueued.", value);
        queue[++(rear)] = value;
    }
}

int Dequeue(int queue[]){
    if(front > rear){
        printf("Queue Underflow.\n");
        return -1;
    } else{
        int value = queue[(front)++];
        printf("Item %d removed from the queue.\n", value);
        return value;
    }
}

void Show(int queue[]) {
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Your queue items are: [");

    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(){
    printf("Enter the length of your queue: ");
    scanf("%d", &queueLength);
    int queue[queueLength];

    while(choice != 0){
        printf("\nEnter 1 for Enqueue, \n2 for Dequeue, \n3 for Show operation, or 0 to Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Enter the value you want to Enqueue: ");
            scanf("%d", &value);
            Enqueue(queue, value);
        } else if(choice == 2){
            Dequeue(queue);
        } else if(choice == 3){
            Show(queue);
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
