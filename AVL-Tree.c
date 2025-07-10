#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) { return (a > b) ? a : b; }
struct Node {
    int key, height;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key; node->left = node->right = NULL; node->height = 1;
    return node;
}
int height(struct Node* N) {
    return N ? N->height : 0;
}
int getBalance(struct Node* N) {
    return N ? height(N->left) - height(N->right) : 0;
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right; x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left; y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
struct Node* insert(struct Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left); return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right); return leftRotate(node);
    }
    return node;
}
struct Node* minValueNode(struct Node* node) {
    while (node->left) node = node->left;
    return node;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            struct Node* temp = root->left ? root->left : root->right;
            root = temp;
        } else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (!root) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left); return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right); return leftRotate(root);
    }
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = deleteNode(root, 10);
    inorder(root);
    printf("\n");
    struct Node* found = search(root, 15);
    if (found) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
