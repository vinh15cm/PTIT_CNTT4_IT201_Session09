#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm node vào cuối danh sách
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

// In danh sách
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

// Thêm phần tử vào vị trí bất kỳ
void insertAtPosition(Node** head, int value, int pos) {
    Node* newNode = createNode(value);
    if (pos <= 0) {
        printf("Vi tri khong hop le!\n");
        free(newNode);
        return;
    }

    if (pos == 1) {  // Thêm đầu
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri vuot qua do dai danh sach!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen (bat dau tu 1): ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printf("Danh sach sau khi chen:\n");
    printList(head);

    return 0;
}
