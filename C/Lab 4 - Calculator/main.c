#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct NodeType {
    char operator;
    int value;
    struct NodeType *nextPtr;
} Node;

// Function to create a new node
Node *addNode(char operator, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->operator= operator;
    newNode->value = value;
    newNode->nextPtr = NULL;
    return newNode;
}

int main() {
    // Initialize stacks to NULL
    Node *undoStack = NULL;
    Node *redoStack = NULL;

    int result, operand;
    char userChoice, operator;

    printf(" _____________________________________ \n");
    printf("| C Calculator - Lab 4 - Dylan Lucero |\n");
    printf("| Usage: u - Undo r - Redo  q - Quit) |\n");
    printf("|_____________________________________|\n");
    printf("Enter starting value: ");
    scanf("%d", &result);

    while (1) {
        printf("Result = %d\n", result);
        printf("Enter next operation:");
        scanf(" %c", &userChoice);

        if (userChoice == 'q') { break; } // If q, program will quit
        else if (userChoice == 'u') { // if u, Undo
            // Check if stack is empty
            if (undoStack != NULL) {
                // Undo the last operation
                operator= undoStack->operator;
                operand = undoStack->value;
                undoStack = undoStack->nextPtr;

                // Store the previous result before the operation
                int previousResult = result;

                // Update result with new value
                if (operator== '+') { result = previousResult - operand; }       
                else if (operator== '-') { result = previousResult + operand; }
                else if (operator== '*') { result = previousResult / operand; }

                // Save the current state to the redo stack
                Node *redoNode = addNode(operator, operand);
                redoNode->nextPtr = redoStack;
                redoStack = redoNode;
            }
        } else if (userChoice == 'r') { // if r, Redo
            // Check if stack is empty
            if (redoStack != NULL) {
                // Redo the last undone operation
                operator= redoStack->operator;
                operand = redoStack->value;
                redoStack = redoStack->nextPtr;

                // Save the current state to the undo stack
                Node *undoNode = addNode(operator, operand);
                undoNode->nextPtr = undoStack;
                undoStack = undoNode;

                // Update result with new value 
                if (operator== '+') { result += operand; }
                else if (operator== '-') { result -= operand; }
                else if (operator== '*') { result *= operand; }
            }
        } else if (userChoice == '+' || userChoice == '-' || userChoice == '*') {
            scanf(" %d", &operand);

            // Perform the operation and update the result
            int tempResult = result;
            switch (userChoice) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            }
            // Save the operation to the undo stack
            Node *undoNode = addNode(userChoice, operand); // Save the operand, not tempResult
            undoNode->nextPtr = undoStack;
            undoStack = undoNode;
        } else { printf("Not a valid operation.\n"); }
    } return 0;
}
