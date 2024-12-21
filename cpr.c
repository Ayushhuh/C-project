#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acc {
    int id;
    char name[50];
    float balance;
};

void create(struct acc *a, int *count) {
    printf("enter account id: ");
    scanf("%d", &a[*count].id);
    printf("enter account holder name: ");
    getchar();
    fgets(a[*count].name, 50, stdin);
    a[*count].name[strcspn(a[*count].name, "\n")] = 0;
    a[*count].balance = 0.0;
    (*count)++;
    printf("account created successfully.\n");
}

int find(struct acc *a, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (a[i].id == id) {
            return i;
        }
    }
    return -1;
}

void deposit(struct acc *a, int count) {
    int id;
    float amt;
    printf("enter account id: ");
    scanf("%d", &id);
    int index = find(a, count, id);
    if (index == -1) {
        printf("account not found.\n");
        return;
    }
    printf("enter deposit amount: ");
    scanf("%f", &amt);
    a[index].balance += amt;
    printf("amount deposited successfully.\n");
}

void withdraw(struct acc *a, int count) {
    int id;
    float amt;
    printf("enter account id: ");
    scanf("%d", &id);
    int index = find(a, count, id);
    if (index == -1) {
        printf("account not found.\n");
        return;
    }
    printf("enter withdrawal amount: ");
    scanf("%f", &amt);
    if (amt > a[index].balance) {
        printf("insufficient balance.\n");
    } else {
        a[index].balance -= amt;
        printf("amount withdrawn successfully.\n");
    }
}

void balance(struct acc *a, int count) {
    int id;
    printf("enter account id: ");
    scanf("%d", &id);
    int index = find(a, count, id);
    if (index == -1) {
        printf("account not found.\n");
        return;
    }
    printf("account id: %d\n", a[index].id);
    printf("account holder: %s\n", a[index].name);
    printf("current balance: %.2f\n", a[index].balance);
}

void update(struct acc *a, int count) {
    int id;
    printf("enter account id: ");
    scanf("%d", &id);
    int index = find(a, count, id);
    if (index == -1) {
        printf("account not found.\n");
        return;
    }
    printf("enter new name: ");
    getchar();
    fgets(a[index].name, 50, stdin);
    a[index].name[strcspn(a[index].name, "\n")] = 0;
    printf("account name updated successfully.\n");
}

void delAcc(struct acc *a, int *count) {
    int id;
    printf("enter account id to delete: ");
    scanf("%d", &id);
    int index = find(a, *count, id);
    if (index == -1) {
        printf("account not found.\n");
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        a[i] = a[i + 1];
    }
    (*count)--;
    printf("account deleted successfully.\n");
}

void menu(struct acc *a, int *count) {
    int choice;
    do {
        printf("\n1. create account\n");
        printf("2. deposit\n");
        printf("3. withdraw\n");
        printf("4. check balance\n");
        printf("5. update account name\n");
        printf("6. delete account\n");
        printf("7. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create(a, count);
                break;
            case 2:
                deposit(a, *count);
                break;
            case 3:
                withdraw(a, *count);
                break;
            case 4:
                balance(a, *count);
                break;
            case 5:
                update(a, *count);
                break;
            case 6:
                delAcc(a, count);
                break;
            case 7:
                printf("exiting...\n");
                break;
            default:
                printf("invalid choice. try again.\n");
        }
    } while (choice != 7);
}

int main() {
    struct acc a[100];
    int count = 0;
    menu(a, &count);
    return 0;
}
