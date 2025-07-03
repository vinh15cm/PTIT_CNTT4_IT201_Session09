#include <stdio.h>
#include <stdlib.h>

// Cấu trúc một node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Khong the cap phat bo nho \n");
        exit(1);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Hàm thêm node vào cuối danh sách
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

// Hàm duyệt từng phần tử và in ra chi tiết
void printNodesDetailed(Node* head) {
    int count = 1;
    while (head != NULL) {
        printf("Node %d : %d\n", count, head->data);
        head = head->next;
        count++;
    }
}

// Hàm main
int main() {
    Node* head = NULL;

    // Tạo danh sách
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // In danh sách
    printList(head);

    // Duyệt & in chi tiết từng node
    printNodesDetailed(head);

    return 0;
}
