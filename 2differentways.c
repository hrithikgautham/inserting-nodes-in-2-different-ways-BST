#include<stdio.h>
#include<stdlib.h>

/*
	this program illustrates how to insert
	a node in a binary tree in 2 different ways
*/

typedef struct node{//container to hold the value
	int data;
	struct node *left;
	struct node *right;
}Node;

Node* createNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//method1
Node* insertUsingPointer(Node *root, int data){
	if(root == NULL)	
		return createNode(data);
		//if the root is empty,  just return a new node (which is supplied by createNode(int))
	
	if(data < root->data)//following the traditional BST order
	//the node to the left of root are lesser than the node
	//the node to the right of root are greater than or equal to node (in this case particularly)
		root->left = insertUsingPointer(root->left, data);
	else
		root->right = insertUsingPointer(root->right, data);

	return root;
}

//method2
void insertUsingPointerPointer(Node **root, int data){
	if(*root == NULL){
		*root = createNode(data);
		return;
	}
	
	if(data < (*root)->data)	//all the nodes less than the root node are on left
		insertUsingPointerPointer(&(*root)->left, data);
	else	//all the nodes GREATER THAN OR EQUAL TO the root node are on the right
		insertUsingPointerPointer(&(*root)->right, data);
}

//printing the nodes
void printPreOrder(Node* root){
	if(root == NULL)
		return;
	printPreOrder(root->left);
	printf("%d ", root->data);
	printPreOrder(root->right);
}

int main(){
	Node *method1;
	method1 = createNode(50);//nodes will be inserted using insertUsingPointer(Node*)
	/*
		another way of initialisation 
		
		Node *method1 = NULL; 
		method1 = insertUsingPointer(method1, 50);
		
		since, insertUsingPointer(Node*) is returning a pointer of type 'Node', we can do this.
	*/
	//insert nodes into method1 object
	insertUsingPointer(method1, 99);
	insertUsingPointer(method1, 23);
	insertUsingPointer(method1, 45);
	insertUsingPointer(method1, 51);
	insertUsingPointer(method1, 12);
	insertUsingPointer(method1, 11);
	insertUsingPointer(method1, 89);
	printf("using insertUsingPointer(Node*) and method1 object : \n\n insertUsingPointer(Node*)  ==>  ");
	printPreOrder(method1);//the output wiil be sorted, because we are traversing the BST using preorder method
	printf("\n\n");
	
	//insert nodes into method2 object
	Node *method2 = NULL;	//line #1									
	method2 = createNode(50);//line #2
	//will be inserted using insertUsingPointerPointer(Node**)
	//NOTE : we dont have o initailise the method2 object
	/*
		eg : we can do this and the program  would run fine
		
		Node *method = NULL;  //line #3
		
		we can substitute line #3 in the place of line #1 and line #2 
	*/
	insertUsingPointerPointer(&method2, 99);//note, we need to send the address of the pointer in order for this function to work
	//by any chance if we send the pointer as the parameter and not its address, the program will not run
	insertUsingPointerPointer(&method2, 23);
	insertUsingPointerPointer(&method2, 45);
	insertUsingPointerPointer(&method2, 51);
	insertUsingPointerPointer(&method2, 12);
	insertUsingPointerPointer(&method2, 11);
	insertUsingPointerPointer(&method2, 89);
	printf("using insertUsingPointerPointer(Node**) and method2 object : \n\n insertUsingPointerPointer(Node**)  ==>  ");
	printPreOrder(method2);
	return 0;
}
