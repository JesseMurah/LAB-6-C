#include <stdio.h>

// Step 2: Declare global float variable called balance and initialize it
float balance = 10000.0;

// Step 3a: Declare function to authenticate user's pin number
int authenticate(int pin) {
    int correct_pin = 1234; // assuming correct pin is 1234
    
    if (pin == correct_pin) {
        return 1;
    } else {
        return 0;
    }
}

// Step 3b: Declare function to request amount of money for a transaction
float requestAmount() {
    float amount;
    
    printf("Enter amount: ");
    scanf("%f", &amount);
    
    return amount;
}

// Step 3c: Declare function to deposit money into user's account
void deposit(float amount) {
    balance += amount;
    printf("Deposit successful.\n");
    printf("New balance: %.2f\n", balance);
}

// Step 3d: Declare function to withdraw money from user's account
void withdraw(float amount) {
    if (amount > balance) {
        printf("Insufficient funds.\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful.\n");
        printf("New balance: %.2f\n", balance);
    }
}

// Step 3e: Declare function to transfer money from sender's account to recipient's account
void transfer() {
    float amount;
    int recipient_acc_num;
    
    printf("Enter recipient's account number: ");
    scanf("%d", &recipient_acc_num);
    
    printf("Enter amount: ");
    scanf("%f", &amount);
    
    if (amount > balance) {
        printf("Insufficient funds.\n");
    } else {
        balance -= amount;
        printf("Transfer successful.\n");
        printf("New balance: %.2f\n", balance);
    }
}

int main() {
    int pin;
    int tries = 0;
    char option;
    
    // Step 4: Convert tries local variable to a static local variable
    static int tries_static = 0;
    
    // Step 5: Identify local and global variables
    // Local variables: pin, tries, option, amount, recipient_acc_num
    // Global variables: balance, tries_static
    
    // Step 6: Define goto labels 'Start' and 'Menu'
Start:
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    
    // Step 4: Use static local variable for tries and modify program to end after 4 incorrect attempts
    if (authenticate(pin)) {
        printf("Authentication successful.\n");
        
Menu:
        printf("Choose an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Transfer\n");
        printf("4. Quit\n");
        
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                deposit(requestAmount());
                break;
            case '2':
                withdraw(requestAmount());
                break;
            case '3':
                transfer();
                break;
            case '4':
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
        
        goto Menu;
    } else {
        tries_static++;
        if (tries_static < 4) {
            printf("Authentication failed. Try again.\n");
            goto Start;
        } else {
            printf("Too many incorrect attempts. Program will now exit.\n");
            return 0;
        }
    }
    
    return 0;
}




