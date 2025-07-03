#include <stdio.h>
#include <stdlib.h>

// câu trúc 1 node trong danh sach lien ket
typedef struct Node{
int data;
struct Node* next;
}Node*;
// ham tao node moi
Node* newNode(int value){
Node* newNode = (Node*)malloc(sizeof(Node));
if(!newNode){
printf("khong the cap phat bo nho \n");
exit(1);
}
newNode->data = value;
newNode->next = NULL;
return newNode;

}
// ham them node vao cuoi danh sach
void appendNode(Node* head, int value){
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
// ham in danh sach dang
void printList(Node* head){
while (head != NULL){
printf("%d ", head->data);
if (head->next != NULL)
head = head->next;
}
printf("->NULL\n");
}
// ham tim kiem gia tri trong danh sach lien ket
bool search(Node* head, int target){
while (head != NULL){
if(head->data == target)
return true;
head = head->next;
}
return false;
}
int main(){
Node* head = NULL;

// tao danh sach 1 2 3 4
appendNode(&head, 1);
appendNode(&head, 2);
appendNode(&head, 3);
appendNode(&head, 4);
appendNode(&head, 5);
printList(head);
// nhap so can tim
int x;
printf("Nhap x: ");
scanf("%d", &x);

// tim kiem
if(search(head, x)){
printf("True\n");
}else{
printf("False\n");
}
return 0;
}

