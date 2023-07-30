#include<stdio.h>
#include<stdlib.h> //malloc, free, rand
struct Node{
	int data;
	struct Node*next;
};
typedef Node* LinkedList;

//Stack
void Push(int K, LinkedList &H){
	LinkedList P;
	P = new Node;
	P->data = K;
	P->next = H;
	H = P;
}

LinkedList Pop(LinkedList &H){
	LinkedList P;
	if (H == NULL ) return NULL;
	else {
		P = H;
		H = H->next;
		delete(P);
		return H;
	}
}
//

	//Double
// struct NodeDLL{
// 	int info;
// 	struct NodeDLL*next,*prev;
// };
// typedef NodeDLL*LinkedList;

LinkedList init(LinkedList H){
	H = NULL;
	return H;
}
//Insert after the node P a node Q with value K
LinkedList insertAfter(LinkedList H,struct Node* P,int K){
	//create a new node with value K
	struct Node* Q=(struct Node*)malloc(sizeof(struct Node*));
	Q->data = K;
	Q->next = NULL;
	//check if H==NULL, insert Q at the beginning of the list
	if (H==NULL) {
		H=Q;
	} else {
		if (P==NULL) return H;
		else {
			//Assign next of Q to P;
			Q->next = P->next;
			//Assign next of P to Q;
			P->next=Q;
		}
	}

	return H;
}

//Insert before the node P a node Q with value K
LinkedList insertBefore(LinkedList H,struct Node* P,int K){
	//create a new node with value K
	struct Node* Q=(struct Node*)malloc(sizeof(struct Node*));
	Q->data = K;
	Q->next = NULL;
	//check if H==NULL, insert Q at the beginning of the list
	if (H==NULL) {
		H=Q;
	} else {
		if (P==NULL) return H;
		else {
			//Assign data P to Q, P data = K
			Q->data = P->data;
			P->data = K;
			//Assign next of Q to P;
			Q->next = P->next;
			//Assign next of P to Q;
			P->next=Q;
		}
	}
	return H;
}

//Delete node P
LinkedList deleteNode(LinkedList H, struct Node*P){
	//If H=P and P->next=NULL (the list node has only one node)
	if (H==P && P->next==NULL){
		H=NULL; 
		free(P);
	}
	//if P=H;
	else if (P==H){
			H=H->next;
			free(P);
		} 
	else {
		// 	//Basic delete
		// LinkedList R=H;
		// while (R->next != P) R=R->next;
		// R->next = P->next;
		// free(P);

		//Delete a regular node P
		if (P->next != NULL) {
		LinkedList R = P-> next;
		P->data = R->data;
		P->next = R->next;
		R->next = NULL;
		free(R);
		} else  {
			LinkedList R=H;
			while (R->next != P) R=R->next;
			R->next = NULL;
			free(P);
		}
	}
	return H;
}

void traversal(LinkedList H){
	if (H==NULL) printf("The list is emty");
	else{
		printf("The list is: ");
		LinkedList P=H;
		while (P){
			printf("%d ",P->data);
			P=P->next;
	}
	}
}

LinkedList find(LinkedList H,int K){
	LinkedList P=H;
	while(P->data != K){
		P=P->next;		
	}
	return P;
}
int main(){
	LinkedList H = init(H);
	// List traversal 
	H = insertBefore (H,H,5);
	H = insertBefore (H,H,4);
	H = insertBefore (H,H,7);
	H = insertBefore (H,H,6);
	H = insertBefore (H,H,8);
	traversal(H);
	printf("\n");
	// LinkedList P = find(H,7);
	// H = deleteNode(H,P); 
	// traversal(H);
	// LinkedList R = H;
	// while (R->next->next != NULL) R = R->next;
	// printf("The previous of last node is: %d\n", R->data);
	Push (1,H);
	traversal(H);
	printf("\n");
	Pop(H);
	traversal(H);
	printf("\n");
	return 0;
}
