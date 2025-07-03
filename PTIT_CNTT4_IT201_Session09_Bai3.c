#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // để dùng bool, true, false

// Cấu trúc 1 node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

// Hàm thêm node vào cuối danh sách
void appendNode(Node** head, int value) {
    Node* node = newNode(value);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

// Hàm in danh sách dạng 1->2->3->...->NULL
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

// Hàm tìm kiếm giá trị trong danh sách liên kết
bool search(Node* head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = NULL;

    // Tạo danh sách 1->2->3->4->5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // In danh sách
    printList(head);

    // Nhập số cần tìm
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);

    // Tìm kiếm
    if (search(head, x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
