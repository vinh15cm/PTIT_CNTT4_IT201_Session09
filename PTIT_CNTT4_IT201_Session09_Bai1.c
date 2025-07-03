#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phần tử của danh sách liên kết đơn
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào cuối danh sách
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    printf("Danh sach lien ket: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Hàm main
int main() {
    Node* head = NULL;

    // Tạo danh sách gồm 5 phần tử bất kỳ
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    // In danh sách
    printList(head);

    return 0;
}
