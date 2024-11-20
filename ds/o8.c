#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *lchild, *rchild;
} node;

node* get_node();
void insert(node* root, node* new_node);
void inorder(node* temp);
void preorder(node* temp);
void postorder(node* temp);
node* search(node* root, int key);

int main() {
    int choice, n, i, key;
    node *new_node, *root = NULL;
    printf("\nProgram For Binary Search Tree\n");
    do {
        printf("\n1. Create");
        printf("\n2. Recursive Traversals");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nHow many nodes do you want to enter: ");
                scanf("%d", &n);
                printf("\nEnter the %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    new_node = get_node();
                    scanf("%d", &new_node->data);
                    if (root == NULL)
                        root = new_node;
                    else 
                        insert(root, new_node);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is not created.\n");
                else {
                    printf("\nThe Inorder display: ");
                    inorder(root);
                    printf("\nThe Preorder display: ");
                    preorder(root);
                    printf("\nThe Postorder display: ");
                    postorder(root);
                }
                break;

            case 3:
                printf("\nEnter element to be searched: ");
                scanf("%d", &key);
                node *result = search(root, key);
                if (result)
                    printf("\nThe %d element is present in the BST.\n", result->data);
                else 
                    printf("\nThe key %d is not present in the BST.\n", key);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("\nPlease enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

node* get_node() {
    node *temp = (node *)malloc(sizeof(node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(node* root, node* new_node) {
    if (new_node->data < root->data) {
        if (root->lchild == NULL)
            root->lchild = new_node;
        else
            insert(root->lchild, new_node);
    } 
    else if (new_node->data > root->data) {
        if (root->rchild == NULL)
            root->rchild = new_node;
        else
            insert(root->rchild, new_node);
    }
}

node* search(node* root, int key) {
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return search(root->lchild, key); 
    else
        return search(root->rchild, key); 
}

void inorder(node* temp) {
    if (temp != NULL) {
        inorder(temp->lchild);
        printf("%d ", temp->data);
        inorder(temp->rchild);
    }
}

void preorder(node* temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}

void postorder(node* temp) {
    if (temp != NULL) {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d ", temp->data);
    }
}