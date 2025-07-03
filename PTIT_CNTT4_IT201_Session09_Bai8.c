#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node
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

// Thêm vào cuối danh sách
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

// Hàm xóa phần tử tại vị trí bất kỳ
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL || pos < 1) {
        printf("Vi tri khong hop le hoac danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    // Xóa phần tử đầu
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Tìm node trước vị trí cần xóa
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // Nếu không tìm được
    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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

    int position;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Danh sach sau khi xoa:\n");
    printList(head);

    return 0;
}
