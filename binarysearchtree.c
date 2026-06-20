#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
}

struct node* search(struct node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }

    if(key < root->data){
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to display BST (Inorder Traversal)
void display(struct node* root){
    if(root != NULL){
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main(){
    struct node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Nodes in BST (Inorder): ");
    display(root);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    struct node* result = search(root, key);

    if(result != NULL){
        printf("Element found in BST\n");
    }
    else{
        printf("Element not found in BST\n");
    }

    return 0;
}
