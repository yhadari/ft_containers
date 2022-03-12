#include "iostream"

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void preOrder(struct node* root)
{
    if (root != NULL) {
        std::cout << " " << root->key;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << " " << root->key;
    }
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        std::cout <<"  "<< root->key;
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        std::cout <<"\n";
    }
}

struct node* minValueNode(struct node* node)
{
    while (node->left)
        node = node->left;
    return node;
}

void leftViewUtil(struct node* root, int level, int* max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level) {
        std::cout <<"  "<< root->key;
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
 
void leftView(struct node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

void rightViewUtil(struct node* root, int level, int* max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level) {
        std::cout <<" "<< root->key;
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int nodeCount(struct node* node)
{
    if (node == NULL)
        return 0;
    else
        return (nodeCount(node->left) + nodeCount(node->right) + 1);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
   */
    struct node* root = NULL;
 
    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Function Call
    root = deleteNode(root, 50);
    leftView(root);
    std::cout << std::endl;
    rightView(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl << " "<< nodeCount(root);
    return 0;
}