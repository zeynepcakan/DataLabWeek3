#include <stdio.h>
#include <stdlib.h>

//delete node in the list.
struct student {
	int std_number;
	int age;
	int final;
	int midterm_exam;
	struct student *next; 
};
typedef struct student node;

// yeni düğümler döndüren fonksiyon 
node *addNode(node *newNode,int new_data)
{
	node *p = newNode;
	// liste boşsa ... dügüm yoktur
	if(newNode == NULL )
	{
		newNode= (node*)malloc(sizeof(node));
		newNode->next = NULL;
		newNode->std_number = new_data; // yeni veri new nodun std_numberıdır. 
		return newNode;
	}
	 // eklenen data daha büyükse diğerlerinden sağa (kuyruğa) alıuyoruz
	else if(newNode->std_number < new_data)
	{
		while(p->next != NULL && p->next->std_number < new_data)
		{
			p=p->next;	
		}
		node *temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		p->next = temp;
		temp->std_number = new_data;
		return newNode;
	}
	// eklene veri baştakinden küçükse onu listenin başına alırız
	
	else 
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->std_number = new_data;
		temp->next = newNode;
		newNode = temp;
		return newNode;
	}	
}
node *deleteNode(node *deletedNode, int data)
{
	node *temp;
	node *p;
	
	if(deletedNode->std_number == data){
		temp=deletedNode;
		deletedNode = deletedNode->next;
		free(temp); //this func delete item.
		return deletedNode;
		
	}
	while(p->next != NULL && p->next->std_number != data)
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		printf("\nnumber not found ");
		return deletedNode;
	}
	else 
	{
		temp = p->next;
		p->next = p->next->next;
		free(temp);
		return deletedNode;
	}
	
}
void printNodes(node *n) // tüm verileri yazdırmak istiyorsak pointer ile liste gezmemiz gerekir.
{
	while(n != NULL)
	{
		printf("%d\t",n->std_number);
		n = n->next;
	}
}
int main() {
	
	// listenin başını oluşturma
	node *head=(node*)malloc(sizeof(node));
	head ->std_number=23;
	head->next=NULL;
	
	head = addNode(head,10);
	head = addNode(head,104);
	head = addNode(head,41);
	head = addNode(head,23);
	head = addNode(head,25);
	head = addNode(head,33);
	head = addNode(head,140);
	head = addNode(head,78);
	
	printf("Our first node's data is : %d\n",head->std_number);
	printNodes(head);
	
	head = deleteNode(head,41);
	head = deleteNode(head,140);
	head = deleteNode(head,10);
	printf("\nafter deleting ...\n");
	printNodes(head);

	
	
	return 0;
}


