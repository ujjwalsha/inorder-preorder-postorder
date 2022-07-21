#include<stdio.h>
#include<stdlib.h>



//inorder, preorder and postorder tree program 

struct node{
    int info;
    struct node *left;
    struct node *right;
};

struct node* createnode(int x){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->info = x;
    new->left = NULL;
    new->right = NULL;

    return new;
}

//preorder traversal

void preorder(struct node* root){
    if(root == NULL)
    return;

    printf("%d", root->info);
    preorder(root -> left);
    preorder(root ->right);
}

//inOrder traversal 
void inorder(struct node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    printf("%d", root -> info);
    inorder(root -> right);
}

//postorder traversal 
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d", root -> info);
}


  /*     1 
      /  \      
     /    \
    2       3  
   / \     / \ 
  /   \   6   7
 4     5
*/

void main(){
    struct node* root = createnode(1);
    root ->left = createnode(2);
    root ->right = createnode(3);
    root->left ->left = createnode(4);
    root -> left ->right = createnode(5);
    root -> right -> left = createnode(6);
    root ->right -> right = createnode(7);

    printf("\npreorder traversal \n");
    preorder(root);

    printf("\ninorder traversal \n");
    inorder(root);
    
    printf("\npostorder traversal \n");
    postorder(root);
}