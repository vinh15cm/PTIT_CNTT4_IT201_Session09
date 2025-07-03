#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node
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

// Hàm xóa phần tử đầu tiên
void deleteHead(Node** head) {
    if (*head == NULL) return;  // Danh sách rỗng
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    // Tạo danh sách ban đầu: 1->2->3->4->5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Danh sach ban dau:\n");
    printList(head);

    // Xóa phần tử đầu
    deleteHead(&head);

    printf("Danh sach sau khi xoa phan tu dau:\n");
    printList(head);

    return 0;
}
