#include <stdio.h>
#include <string.h>
struct Bank
{
    char name[20];
    char acc_num[15];
    char password[10];
    char mob[12];
    char add[30];
    float bank_balance;

};
void Create_account(struct Bank arr[], int* size);
int Search_Account(struct Bank arr[],int size, char acc[]);
void Print_all_Users_Info(struct Bank arr[], int size);
void Login_Account(struct Bank arr[], int size);
void Deposit_Money(struct Bank arr[], int size);
void Withdraw_Money(struct Bank arr[], int size);
void Transfer_Money(struct Bank arr[], int size);

int main()
{
    struct Bank arr[100];
    int i = 1;
    int size = 0;

    printf("\n=====================================\n");
    printf("          WELCOME TO SECURE BANK          ");
    printf("\n=====================================\n");
    
    while(i)
    {
        printf("\n1.Create New Account\n2.Login\n3.Deposit Money\n4.Withdraw Money\n5.Transfer Money\n6.Print Users Information\n7.Exit\n");
        printf("-------------------------------------\n");
        int opt;
        printf("\nSelect one option from the above menu : ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                    Create_account(arr, &size);
                    break;
            case 2:
                    Login_Account(arr,size);
                    break;
            case 3: 
                    Deposit_Money(arr,size);
                    break;
            case 4:
                    Withdraw_Money(arr,size);
                    break;
            case 5:
                    Transfer_Money(arr,size);
                    break;
            case 6:
                    Print_all_Users_Info(arr,size);
                    break;
            case 7:
                    printf("\nThank you for contacting us!!!\n");
                    return 0;
            default:
                    printf("\nInvalid option! Pleased select 1 to 7\n");
                    break;
        }
        printf("\nDo you want to continue(1-Y/0-N): ");
        scanf("%d", &i);
    }
}
void Transfer_Money(struct Bank arr[], int size)
{
    if(size == 0)
    {
        printf("\nNo accounts available! Please create an account first\n");
        return;
    }

    char sender_acc[15];
    char receiver_acc[15];

    int sender_index = -1;
    int receiver_index = -1;

    //find sender account
    while(sender_index == -1)
    {
        printf("\nEnter Your Account Number: ");
        scanf("%s", sender_acc);

        for(int i = 0; i < size; i++)
        {
            if(strcmp(arr[i].acc_num, sender_acc) == 0)
            {
                sender_index = i;
                break;
            }
        }
        if(sender_index == -1)
        {
            printf("Invalid account number! Please try again\n");
        }
    }

    //check sender Balance
    if(arr[sender_index].bank_balance <= 0)
    {
        printf("Insufficient balance! Your current balance is Rs. %.2f\n", arr[sender_index].bank_balance);
        return;
    }

    //find receiver Account
    while(receiver_index == -1)
    {
        printf("Enter Receiver Account Number: ");
        scanf("%s", receiver_acc);

        for(int i = 0; i < size; i++)
        {
            if(strcmp(arr[i].acc_num, receiver_acc) == 0)
            {
                receiver_index = i;
                break;
            }
        }

        if(receiver_index == -1)
        {
            printf("Receiver account not found! Please try again\n");
        }
        else if(receiver_index == sender_index)
        {
            printf("You cannot transfer money to your own account! Please try again\n");
            receiver_index = -1;
        }
    }

    //Enter transfer amount
    float amount;
    while(1)
    {
        printf("Enter Transfer Amount: Rs. ");
        if(scanf("%f", &amount) != 1)
        {
            printf("Invalid input! Please enter amount\n");
            while(getchar() != '\n');
            continue;
        }
        if(amount <= 0)
        {
            printf("Transfer amount must be greater than zero!\n");
            continue;
        }
        if(amount > arr[sender_index].bank_balance)
        {
            printf("Insufficient Balance! Your current balance is Rs. %.2f\n", arr[sender_index].bank_balance);
            continue;
        }
        break;
    }

    //update Both Balance
    arr[sender_index].bank_balance -= amount;
    arr[receiver_index].bank_balance += amount;

    printf("\nTransfer Successfull\n");
    printf("Transferred Amount: Rs. %.2f\n", amount);
    printf("Your Remaining Balance: Rs. %.2f\n", arr[sender_index].bank_balance);
    printf("Receiver Updated Balance: Rs. %.2f\n", arr[receiver_index].bank_balance);
} 


void Withdraw_Money(struct Bank arr[], int size)
{
    if(size == 0)
    {
        printf("\nNo accounts available! Pleased create an account first\n");
        return;
    }

    char acc[15];
    int index = -1;

    while(index == -1)
    {
        printf("\nEnter Your Account Number: ");
        scanf("%s",acc);

        for(int i = 0; i < size; i++)
        {
            if(strcmp(arr[i].acc_num, acc) == 0)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            printf("Invalid account number! Pleased try again\n");
        }
    }
    if(arr[index].bank_balance <= 0)
        {
            printf("Insufficient balance! Your current balance is Rs. %.2f\n",
            arr[index].bank_balance);
            return;
        }

  float amount;

    while(1)
    {
        printf("Enter Withdrawal Amount: Rs. ");

        if(scanf("%f", &amount) != 1)
        {
            printf("Invalid input! Please enter a numeric amount.\n");

            while(getchar() != '\n');
            continue;
        }

        if(amount <= 0)
        {
            printf("Withdrawal amount must be greater than zero!\n");
            continue;
        }

        if(amount > arr[index].bank_balance)
        {
            printf("Insufficient balance! Your current balance is Rs. %.2f\n",
                arr[index].bank_balance);
            continue;
        }

        break;
    }

    arr[index].bank_balance -= amount;

    printf("\nWithdrawal Successfull!\n");
    printf("Withdrwan Amount: Rs. %.2f\n", amount);
    printf("Remaining Balnce: Rs. %.2f\n", arr[index].bank_balance);
}

void Deposit_Money(struct Bank arr[], int size)
{
    if(size == 0)
    {
        printf("\nNo accounts available! Please create an account first\n");
        return;
    }

    char acc[15];
    int index = -1;

    while(index == -1)
    {
        printf("\nEnter Your Account Number: ");
        scanf("%s", acc);

        index = -1;

        for(int i = 0; i < size; i++)
        {
            if(strcmp(arr[i].acc_num, acc) == 0)
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            printf("\nAccount not found! Pleased try again\n");

        }
    }
    float amount;

    printf("Enter Deposit Amount: Rs. ");
    if(scanf("%f", &amount) != 1)
    {
        printf("Invalid amount!\n");
        return;
    }
    if(amount <= 0)
    {
        printf("Deposit amount must be greater than zero!\n");
        return;
    }

    arr[index].bank_balance += amount;

    printf("\nDeposit Successful!\n");
    printf("Deposited Amount: Rs. %.2f\n", amount);
    printf("Updated Balance: Rs. %.2f\n", arr[index].bank_balance);
}

int Search_Account(struct Bank arr[],int size, char acc[])
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(arr[i].acc_num,acc) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int Search_Mobile(struct  Bank arr[], int size, char mob[])
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(arr[i].mob, mob) == 0)
        {
            return 1;
        }
    }
    return 0;
    
}
void Login_Account(struct Bank arr[], int size)
{
    if(size == 0)
    {
        printf("No Account found! Please create an account first\n");
        return;
    }

    char acc[15];
    int index = -1;

    do
    {
        printf("Enter Your Account Number: ");
        scanf("%s", acc);

        index = -1;

        for(int i = 0; i < size; i++)
        {
            if(strcmp(arr[i].acc_num, acc) == 0)
            {
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            printf("Account not found! Please enter again\n");
        }

    } while(index == -1);

    char password[10];
    int pw_flag = 1;

    do
    {
        printf("Enter Your Password: ");
        scanf("%s", password);

        if(strcmp(arr[index].password, password) == 0)
        {
            pw_flag = 0;
            printf("Login successful!\n");
            printf("Welcome, %s!\n", arr[index].name);
        }
        else
        {
            printf("Incorrect password! Please try again\n");
        }
    } while(pw_flag);
}

void Create_account(struct Bank arr[], int* size)
{
    printf("\nEnter your Name: ");
    scanf(" %[^\n]", arr[*size].name);

    int acc_flag = 1;

    do
    {
        char acc[15];
        int valid = 1;

        printf("Enter Your 12 - digit Account Number: ");
        scanf(" %s", acc);

        if(strlen(acc) != 12)
        {
            valid = 0;
        }

        for(int i = 0; acc[i] != '\0'; i++)
        {
            if(acc[i] < '0' || acc[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if(valid == 0)
        {
            printf("Invalid Account Number! Enter Exact 12 Digits \n");
        }
        else if(Search_Account(arr,*size,acc))
        {
            printf("Account Number already exits Try again\n");
        }
        else
        {
            acc_flag=0;
            strcpy(arr[*size].acc_num,acc);
        }
    } while (acc_flag);
    
    int pw_flag = 1;

    do
    {
        char conf_password[10];

        printf("Enter Your Password: ");
        scanf(" %[^\n]", arr[*size].password);

        printf("Enter Confirm Password: ");
        scanf(" %[^\n]", conf_password);

        if(strcmp(arr[*size].password, conf_password) == 0)
        {
            pw_flag = 0;
        }
        else
        {
            printf("Passwords do not match! Try again\n");
        }
    } while (pw_flag);

    int mob_flag = 1;

    do
    {
        int valid = 1;

        printf("Enter Your Mobile Number: ");
        scanf(" %s", arr[*size].mob);

        if(strlen(arr[*size].mob) != 10)
        {
            valid = 0;
        }

        for(int i = 0; arr[*size].mob[i] != '\0'; i++)
        {
            if(arr[*size].mob[i] < '0' || arr[*size].mob[i] > '9')
            {
                valid = 0;
                break;
            }
        }
        if(valid == 0)
        {
            printf("Invalid mobile number! Enter exact 10 digits\n");
        }
        else if(Search_Mobile(arr, *size, arr[*size].mob))
        {
            printf("Mobile number already exist! Enter another number\n");
        }
        else
        {
            mob_flag = 0;
        }

    } while(mob_flag);
    
    printf("Enter the Address: ");
    scanf(" %[^\n]", arr[*size].add);

    arr[*size].bank_balance = 0.0;
    (*size)++;

    printf("Account created Successfully!\n");
}



void Print_all_Users_Info(struct Bank arr[], int size)
{
    if(size == 0)
    {
        printf("No accounts available!\n");
        return;
    }

    printf("\n");
    printf("+--------------+----------------------+--------------+----------------------+---------------+\n");
    printf("|                              SECURE BANK - USER INFORMATION                               |\n");
    printf("+--------------+----------------------+--------------+----------------------+---------------+\n");
    printf("| Account No   | Name                 | Mobile No    | Address              | Balance       |\n");
    printf("+--------------+----------------------+--------------+----------------------+---------------+\n");

    for(int i = 0; i < size; i++)
    {
        printf("| %-12.12s | %-20.20s | %-12.12s | %-20.20s | %13.2f |\n",
               arr[i].acc_num,
               arr[i].name,
               arr[i].mob,
               arr[i].add,
               arr[i].bank_balance);

        printf("+--------------+----------------------+--------------+----------------------+---------------+\n");
    }
}


