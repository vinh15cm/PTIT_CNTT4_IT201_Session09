#include <stdio.h>
#include <stdlib.h>
// cau truc mot mode trong danh sach lien ket
typedef struct Node{
int data;
struct Node* next;
}Node;
// ham tao node moi
Node* newNode(int value){
Node* temp = (Node*)malloc(sizeof(Node));
if(!newNode){
printf("khong the cap phat bo nho \n");
exit(1);
}
newNode->data = value;
newNode->next = NULL;
return newNode;
}
// ham them node vao cuoi danh sach
void appendNode(Node** head, int value){
Node* newNode = createNode(value);
if(*head == NULL){
*head = newNode;
}else{
Node* temp = *head;
while(temp->next != NULL)
temp = temp->next;
temp->next = newNode;
}
}
// ham in danh sach dang 1->2->3->...->NULL
void printList(Node* head){
while(head != NULL){
printf("%d ", head->data);
if(head->next != NULL)
printf("->");
head = head->next;
}
printf("\n");
}
// ham duyet tung phan tu va in ra gia tri Node i : gia tri
void printNodesDetailed(Node* head){
int count = 1;
while(head != NULL){
printf("Node %d : %d\n", count, head->data);
head = head->next;
count++;
}
}
int main(){
Node* head = NULL;
// tao danh sach
appendNode(&head, 1);
appendNode(&head, 2);
appendNode(&head, 3);
appendNode(&head, 4);
appendNode(&head, 5);

// in danh sach
printList(head);
// duyet & in chi tiet tung node
printNodesDetailed(head);
return 0;
}
