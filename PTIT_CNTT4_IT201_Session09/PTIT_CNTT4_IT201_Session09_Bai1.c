#include <stdio.h>
#include <stdlib.h>
// cau truc phan tu cua danh sach lien ket don
typedef strcut Node{
int data;
struct Node * next;
}Node;
// ham tao nut moi
Node* createNode(int value){
Node* newNode = (Node*)malloc(sizeof(Node));
if(newNode == NULL){
printf("Khong the cap phat bo nho\n");
exit(1);
}
newNode->data = value;
newNode->next = NULL;
return newNode;
}
// ham them phan tu vao cuoi danh sach
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
// ham in danh sach
void printList(Node* head){
printf("danh sach lien ket:");
while(head != NULL){
printf("%d ",head->next);
}
printf("NULL\n");
}
// ham main
int main(){
Node* head = NULL;
// tao danh sach gom 5 ki tu bat ki
appendNode(&head,10);
appendNode(&head,20);
appendNode(&head,30);
appendNode(&head,40);
appendNode(&head,50);
// in ds
printList(head);
return 0;
}