//  Stack is a linear data structure that follows the Last In First Out (LIFO) principle.
//  The main operations of a stack are Push and Pop. Push adds an item to the top of the stack, while Pop removes the item from the top of the stack.

#include <stdio.h>


void Push(int value, int stack[], int *top, int maxLength){
    if(*top < maxLength - 1){
        stack[++(*top)] = value;
        printf("Item %d added to the stack! \n", value);
    }
    else{
        printf("Stack overflow! \n");
    }
}

int Pop(int stack[], int *top){
    if(*top >= 0){
        int value = stack[(*top)--];
        printf("Item %d removed from the stack! \n", value);
        return value;
    }
    else{
        printf("Stack underflow! \n");
        return -1; // Return -1 to indicate stack is empty
    }
}

int main(){
    int stackLength, choice = -1, top = -1;

    printf("Enter the length of your Stack: ");
    scanf("%d", &stackLength);
    int stack[stackLength];

    while(choice != 0){
        printf("Enter 1 to Push, 2 to Pop, and 0 to Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Enter the value to push: ");
            scanf("%d", &value);
            Push(value, stack, &top, stackLength);
        }
        else if(choice == 2){
            Pop(stack, &top);
        }
        else if(choice != 0){
            printf("Invalid choice! Please try again. \n");
        }
    }

    return 0;
}
