#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
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

// Hàm in danh sách
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

// Hàm thêm node vào đầu danh sách
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

int main() {
    Node* head = NULL;

    // Tạo danh sách 1->2->3->4->5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Danh sach ban dau:\n");
    printList(head);

    // Nhập giá trị cần chèn đầu
    int value;
    printf("Nhap gia tri muon them vao dau danh sach: ");
    scanf("%d", &value);

    // Thêm vào đầu
    insertHead(&head, value);

    printf("Danh sach sau khi them:\n");
    printList(head);

    return 0;
}
