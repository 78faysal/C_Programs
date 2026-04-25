//  Stack is a linear data structure that follows the Last In First Out (LIFO) principle.
//  The main operations of a stack are Push and Pop. Push adds an item to the top of the stack, while Pop removes the item from the top of the stack.

#include <stdio.h>

int top = -1, choice = -1, stackLength;


void Push(int value, int stack[]){
    if(top < stackLength - 1){
        stack[++(top)] = value;
        printf("Item %d added in the stack! \n", value);
    }
    else{
        printf("Stack overflow! \n");
    }
}

int Pop(int stack[]){
    if(top >= 0){
        int value = stack[(top)--];
        printf("Item %d removed from the stack! \n", value);
        return value;
    }
    else{
        printf("Stack underflow! \n");
        return -1; // Return -1 to indicate stack is empty
    }
}

void Show(int stack[]) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Your stack items are: [");

    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(){
    printf("Enter the length of your Stack: ");
    scanf("%d", &stackLength);
    int stack[stackLength];

    while(choice != 0){
        printf("\nEnter 1 for Push, \n2 for Pop, \n3 for Show, \nor 0 to Exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            printf("Enter the value you want to push: ");
            scanf("%d", &value);
            Push(value, stack);
        }
        else if(choice == 2){
            Pop(stack);
        }
        else if(choice == 3){
            Show(stack);
        }
        else if(choice != 0){
            printf("Invalid choice! Please try again. \n");
        }
    }

    return 0;
}
