#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBUG 1
struct treeNode{
    int key;
    //struct treeNode *parent;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode treeNode;
//All function declaration to avoid problems.
treeNode *R_rotation(treeNode *parent);
treeNode *L_rotation(treeNode *parent);
treeNode *LR_rotation(treeNode *parent);
treeNode *RL_rotation(treeNode *parent);
treeNode * balance_tree( treeNode * currentNode);
treeNode * Insert(treeNode *currentNode, int key);
int maximum(int a, int b);
int get_height(treeNode *currentNode);
int get_balance(treeNode *currentNode);
treeNode * FindMin(treeNode *currentNode);
int get_left_height(treeNode *currentNode);
void In_order_find_Kth_min(treeNode *currentNode, int * count, const int K_th_min);
treeNode *delete(treeNode *root, const int key);


//for debugging
treeNode * balance_tree_when_deleting( treeNode * currentNode);


treeNode *R_rotation(treeNode *parent){
    #if DEBUG
        printf("R_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->left;
    //1
    //child->parent = parent->parent;
    
    parent->left = child->right;
    child->right = parent;
    //2
    //parent->parent = child;
//#if DEBUG
//    printf("R_rotation on %d and its new parents: %d\n", parent->key, parent->parent->key);
//#endif
    return child;
}
treeNode *L_rotation(treeNode *parent){
    #if DEBUG
        printf("L_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->right;
    //1
    //child->parent = parent->parent;
    
    parent->right = child->left;
    child->left = parent;
    //2
    //parent->parent = child;
//#if DEBUG
//    printf("L_rotation on %d and its new parents: %d\n", parent->key, parent->parent->key);
//#endif
    return child;
}
treeNode *LR_rotation(treeNode *parent){
    #if DEBUG
        printf("LR_rotation on %d\n", parent->key);
    #endif
    treeNode *child = parent->left;
    parent->left = L_rotation(child);
    return R_rotation(parent);
}
treeNode *RL_rotation(treeNode *parent){
#if DEBUG
    printf("RL_rotation on %d\n", parent->key);
#endif
    treeNode *child = parent->right;
    parent->right = R_rotation(child);
    return L_rotation(parent);
}
treeNode * balance_tree( treeNode * currentNode){
    int height_diff = get_balance(currentNode);
    if(height_diff > 1){
        if(get_balance(currentNode -> left) > 0){
            currentNode = R_rotation(currentNode);
        }else{
            currentNode = LR_rotation(currentNode);
        }
    }else if(height_diff < -1){
        if(get_balance(currentNode->right) < 0){
            currentNode = L_rotation(currentNode);
        }else{
            currentNode = RL_rotation(currentNode);
        }
    }
    return currentNode;
}
treeNode * Insert(treeNode *currentNode, int key){
    if(currentNode == NULL){
    #if DEBUG
        printf("Added key %d\n", key);
    #endif
        currentNode = (treeNode*)malloc(sizeof(treeNode));
        currentNode ->key = key;
        currentNode ->left = currentNode ->right = NULL;
    }else if(key > currentNode ->key){
        
        currentNode ->right = Insert(currentNode ->right, key);
        //1
        //currentNode ->right -> parent = currentNode;
        
        currentNode = balance_tree( currentNode );
    }else if(key < currentNode ->key){
       
        currentNode ->left = Insert(currentNode ->left,key);
        //2
        //currentNode ->left -> parent = currentNode;
        
        currentNode = balance_tree(currentNode);
    }else{
        printf("fail! - duplicated key\n");
        exit(-1);
    }
    return currentNode;
}

int maximum(int a, int b){
    return (a > b? a : b);
}
int get_height(treeNode *currentNode){
    if(currentNode == NULL){
        return -1;
    }else{
        int height = 1 + maximum(get_height(currentNode->left), get_height(currentNode->right));
        return height;
    }
}
//int get_left_height(treeNode *currentNode){
//    if(currentNode == NULL){
//        return -1;
//    }else{
//        int height = 1 + get_left_height(currentNode->left);
//        return height;
//    }
//}
int get_balance(treeNode *currentNode){
    if(currentNode == NULL){
        return 0;
        //if 0 ==> balanced
    }else{
        return (get_height(currentNode->left) - get_height(currentNode->right));
        //if 0 ==> balanced, if -1 right sub > left sub by one, vice versa
    }
}
treeNode * FindMin(treeNode *currentNode){
    if(currentNode == NULL){
        return NULL;
    }
    if(currentNode->left != NULL){
        return FindMin(currentNode->left);
    }else{
        return currentNode;
    }
}
void In_order_find_Kth_min(treeNode *currentNode, int * count, const int K_th_min){
    if(currentNode == NULL ){
        return;
    }
    In_order_find_Kth_min(currentNode->left, count, K_th_min);
    (*count) += 1;
    if((*count) == K_th_min){
        printf("%d\n", currentNode->key);
    }
//    printf("Count_for_loops: %d\n", *count);
    In_order_find_Kth_min(currentNode->right, count, K_th_min);
}

void In_order_find_Kth(treeNode *currentNode, int * count, const int K_th_min){
    if(currentNode == NULL ){
        return;
    }
    In_order_find_Kth(currentNode->left, count, K_th_min);
    printf("%d ", currentNode->key);
    In_order_find_Kth(currentNode->right, count, K_th_min);
}

//treeNode * balance_tree_when_deleting( treeNode * currentNode){
//    int height_diff = get_balance(currentNode);
//    if(height_diff > 1){
//        if(get_balance(currentNode -> left) > 0){
//            currentNode = R_rotation(currentNode);
//            //printf("Current root is : %d, its right is %d\n", currentNode->key, currentNode->right->key);
//            currentNode->parent = NULL;
////            (currentNode->right)->left = currentNode->right;
////            currentNode->right->parent = currentNode->right;
//            currentNode->right->left->parent = currentNode->right;
//
//        }else{
//            currentNode = LR_rotation(currentNode);
//        }
//    }else if(height_diff < -1){
//        if(get_balance(currentNode->right) < 0){
//            currentNode = L_rotation(currentNode);
//           // printf("Current root is : %d, its left is %d, its right is %d, so 4's right is %d\n", currentNode->key, currentNode->left->key, currentNode->right->key, currentNode->left->right->key);
//            currentNode->parent = NULL;
////            (currentNode->left)->right = currentNode->left;
////            currentNode->left->parent = currentNode->left;
//            currentNode->left->right->parent = currentNode->left;
//        }else{
//            currentNode = RL_rotation(currentNode);
//        }
//    }
//    return currentNode;
//}

treeNode *delete(treeNode *root, const int key){
    //first have to implement a search function to dig out where key belongs to
//    treeNode * Key_s_node = root;
//    while(key != Key_s_node->key){
//        if(key > Key_s_node->key){
//            if(Key_s_node->right == NULL){
//                printf("The key to be deleted is not in the tree\n");
//            }
//            Key_s_node = Key_s_node->right;
//        }else{
//            if(Key_s_node->left == NULL){
//                printf("The key to be deleted is not in the tree\n");
//            }
//            Key_s_node = Key_s_node->left;
//        }
//    }
//    
//    //deletion algorithm in Lecture 7 - Binary Search Tree
//    treeNode *y;
//    treeNode *x;
//    if((Key_s_node->left == NULL) || (Key_s_node->right == NULL)){
//        y =  Key_s_node;
//    }else{
//        y = FindMin(Key_s_node->right);
//        Key_s_node->key = y->key;
//    }
//    if(y->left != NULL){
//        x = y->left;
//    }else{
//        x = y->right;
//    }
//    if(y->parent == NULL){
//        root = x;
//        printf("Current root is: %d\n", root->key);
//    }else{
//        if(y->parent->left == y){
//            y->parent->left = x;
//        }else{
//            y->parent->right = x;
//        }
//    }
//    root = balance_tree_when_deleting(root);
//    return root;
    
    
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if ( key < root->key )
        root->left = delete(root->left, key);
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if( key > root->key )
        root->right = delete(root->right, key);
    // if key is same as root's key, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            treeNode *temp = root->left ? root->left : root->right;
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            treeNode *temp = FindMin(root->right);
            // Copy the inorder successor's data to this node
            root->key = temp->key;
            // Delete the inorder successor
            root->right = delete(root->right, temp->key);
        }
    }
    // If the tree had only one node then return
    if (root == NULL)
        return root;
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    //root->height = 1 + maximum(get_height(root->left),get_height(root->right));
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = get_balance(root);
    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return R_rotation(root);
    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left =  L_rotation(root->left);
        return R_rotation(root);
    }
    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return L_rotation(root);
    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = R_rotation(root->right);
        return L_rotation(root);
    }
    return root;
}

#if DEBUG
void In_order_search(treeNode *currentNode){
    if(currentNode == NULL ){
        return;
    }
    In_order_search(currentNode->left);
//    if(currentNode->parent != NULL){
//        printf("%d parent is : %d\n", currentNode->key, currentNode->parent->key);
//    }else{
//        printf("%d parent is : NULL\n", currentNode->key);
//    }
    printf("The tree: %d\n", currentNode->key);
    In_order_search(currentNode->right);
}
#endif

//this function is particularly designed for releasing memory.
//void In_order_free_memory(treeNode *currentNode){
//    if(currentNode == NULL ){
//        return;
//    }
//    In_order_free_memory(currentNode->left);
//    free(currentNode);
//    In_order_free_memory(currentNode->right);
//}


int main(){
//    treeNode *root = NULL;
//    root = Insert(root, 5);
//    root = Insert(root, 4);
//    root = Insert(root, 3);
//    root = Insert(root, 7);
//    root = Insert(root, 9);
//    root = Insert(root, 1);
//    root = Insert(root, 2);
//    root = Insert(root, 14);
//    root = Insert(root, 11);
    treeNode *root = NULL;
    char command[5];
    int value;
    scanf("%s", command);
    while(strcmp(command, "END")!=0){
        if(strcmp(command, "A")==0){
            scanf("%d", &value);
            root = Insert(root, value);
            
            //1
            //root->parent = NULL;
        }
//        if(strcmp(command, "H") == 0){
//            //printf("The height of left subtree: %d\n", get_left_height(root));
//            printf("The height of the tree: %d\n", get_height(root));
//        }
        if(strcmp(command, "M") == 0){
            int K_th;
            scanf("%d", &K_th);
            treeNode *temp;
            temp = FindMin(root);
            //printf("Minimum element is %d\n", temp->key);
            int *count = (int*)malloc(sizeof(int));
            *count = 0;
            In_order_find_Kth_min(root, count, K_th);
        }
        
        
//        if(strcmp(command, "MM") == 0){
//            int K_th;
//            scanf("%d", &K_th);
//            treeNode *temp;
//            temp = FindMin(root);
//            //printf("Minimum element is %d\n", temp->key);
//            int *count = (int*)malloc(sizeof(int));
//            *count = 0;
//            In_order_find_Kth(root, count, K_th);
//            printf("\n");
//        }

        
        if(strcmp(command, "D") == 0){
            int key;
            scanf("%d", &key);
            root = delete(root, key);
        }
        
        
        //debugging
#if DEBUG
        if(strcmp(command, "DEBUG") == 0){
            printf("The root now is %d\n", root->key);
            In_order_search(root);
        }
#endif
        
        
        scanf("%s", command);
    }
    
#if DEBUG
    In_order_search(root);
#endif
    //releasing memory, not sure if it works
    //In_order_free_memory(root);
    return 0;
}
