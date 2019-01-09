#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

// Subtree state can be = Balanced(value 0), LeftHigher(value 1), RightHigher(value 2).
enum State
{
    Balanced,   // Left and right subtree have the same height.
    LeftHigher, // Left subtree's height is 1 larger than right one's.
    RightHigher // Right subtree's height is 1 larger than left one's.
};

struct node
{
    int key;
    State height;
    int size;//not refering to height, but the number of nodes, used to find the K-th min
    node *left, *right;
    node(int k)
    {
        key = k;
        height = Balanced;
        size = 1;
        left = right = NULL;
    }
};

int sizeOfTree(node* root){
    return root == NULL? 0 : root->size;
}

void right_rotate(node*& ref_root)
{
    //every rotation on a node, the node's height must at least decrease by one.
    //when you are rotating a node rightward, then the node must not have left child-->true
    assert(ref_root && ref_root->left);
    node *a = ref_root, *b = ref_root->left;
    int treeSize = a->size;
    int rightSize = treeSize - 1 - sizeOfTree(b->left);
    ref_root = b;
    a->left = b->right;
    b->right = a;
    a->size = rightSize;
    ref_root->size = treeSize;
}

void left_rotate(node*& ref_root)
{
    assert(ref_root && ref_root->right);
    node *a = ref_root, *b = ref_root->right;
    int treeSize = a->size;
    int leftSize = treeSize - 1 - sizeOfTree(b->right);
    ref_root = b;
    a->right = b->left;
    b->left = a;
    a->size = leftSize;
    ref_root->size = treeSize;

    /*done write something here.*/
}

// insert_key() inserts "key" to tree roots at ref_root.
// Returns true if the insertion causes the tree's height increases.
// Otherwise, returns false.
// Observes that insertion never decreases height of tree at ref_root,
// also the height's increment can only be either 0 or 1.
bool insert_key(int key, node*& ref_root)
{
    if(ref_root == NULL)
    {
        ref_root = new node(key);
        return true;
    }
     
    // Inserts `key` to the left subtree.
    if(key < ref_root->key){
        ++ref_root->size;
        // Do matainence(rotations and update height infomation) only when left subtree's height increases.
        if (insert_key(key, ref_root->left)) {
            // Two cases here.
            // 1. LeftHigher: We need to do rotations to keep the tree balanced.
            if (ref_root->height == LeftHigher) {
                node*& p = ref_root->left;
                // There are two cases.
                // a. DoubleRotation
                if (p->height == RightHigher) {
                    // height(b) > height(a)
                    // max(height(x), height(y)) == height(a) == height(z)
                    //     ref_root                                ref_root
                    //     /     \       L rotation on p           /      \
                    //    p       z         ======>               b        z
                    //  /   \                                   /   \
                    // a     b                                 p     y  
                    //      / \                               / \
                    //     x   y                             a   x
                    //
                    //
                    //                                               ||
                    //                                               || R rotation on ref_root
                    //                                               ||
                    //                                              \  /
                    //                                               \/
                    //
                    //
                    //                                                b
                    //                                             /     \
                    //                                           p      ref_root
                    //                                         /   \     /   \    
                    //                                        a     x   y     z
                    State s = p->right->height;
                    left_rotate(p);
                    right_rotate(ref_root);
                    ref_root->height = Balanced;

                    // Based on condition max(height(x), height(y)) == height(a) == height(z), we have that
                    // If s == RightHigher, then height(x) < height(a) otherwise height(x) == height(a).
                    ref_root->left->height = s == RightHigher ? LeftHigher : Balanced;
                    // If s == LeftHigher, then height(y) < height(z) otherwise height(y) == height(z).
                    ref_root->right->height = s == LeftHigher ? RightHigher : Balanced;
                }
                // b. SingleRotation
                else {
                    // height(b) <= height(a)
                    //     ref_root                             p
                    //     /     \       R rotation           /   \
                    //    p               ======>            a  ref_root
                    //  /   \                                     /   \
                    // a     b                                   b     
                    State s = p->height;
                    right_rotate(ref_root);
                    ref_root->height = s == LeftHigher ? Balanced : RightHigher;
                    ref_root->right->height = s == LeftHigher ? Balanced : LeftHigher;
                }
                // Tree's height does not change in both above cases.
                return false;
            }
            // 2. RightHigher or Balanced: the height increment(0/1) from left subtree
            // does not affect the balance at tree ref_root, so no rotation is needed.
            // We only need to update ref_root->height.
            // If ref_root is already balanced before insertion happens, ref_tree height increases by 1.
            // If ref_root is RightHigher before insertion happens, ref_tree height does not change but left and right become balanced .
            else {
                ref_root->height = (ref_root->height == Balanced ? LeftHigher : Balanced);
                // If tree changes to LeftHigher from previously Balanced state, this means that tree's height is increased by 1.
                return ref_root->height == LeftHigher;
            }
        }
    }
    else if(key > ref_root->key){
        ++ref_root->size;
        if (insert_key(key, ref_root->right)) {
            /* write something here.*/
        }
    }
    // We never insert duplicate `key`.
    else
        assert(0);
}

// delete_key() deletes "key" to tree roots at ref_root.
// Returns true if the deletion causes the tree's height increases.
// Otherwise, returns false.
// Observes that deletion never increases height of tree at ref_root,
// also the height's decrement can only be either 0 or 1.
bool delete_key(int key, node*& ref_root)
{
    if(ref_root == 0)
        assert(0); // or return; if non-existent key is allowed.

    if(key < ref_root->key){
        --ref_root->size;
        if (delete_key(key, ref_root->left)) {
            /* write something here.*/
            //有待檢查
            
            
            if (ref_root->height == RightHigher) {
                node*& p = ref_root->right;
                if (p->height == LeftHigher) {
                    State s = p->left->height;
                    right_rotate(p);
                    left_rotate(ref_root);
                    ref_root->height =  Balanced;
                    
                    //this two I change the order, but not sure whether this will affect the result
                    ref_root->left->height = s == RightHigher ? LeftHigher : Balanced;
                    ref_root->right->height = s == LeftHigher ? RightHigher : Balanced;
                    return true;
                }
                else {
                    State s = p->height;
                    left_rotate(ref_root);
                    ref_root->height =  s == RightHigher ? Balanced : LeftHigher;
                    ref_root->left->height = s == RightHigher ? Balanced : RightHigher;
                    return s == RightHigher;
                }
                return false;
            }
            else {
                // ref_root->height is either Balanced or RightHigher, deletion happens on the right tree.
                ref_root->height = (ref_root->height == Balanced ? RightHigher : Balanced);
                return ref_root->height == Balanced;
            }

            
        } 
    }
    else if(key > ref_root->key){
        --ref_root->size;
        if (delete_key(key, ref_root->right)) {
            
            if (ref_root->height == LeftHigher) {
                node*& p = ref_root->left;
                if (p->height == RightHigher) {
                	//  height(b) > height(a)
                    // ----------------------------case: ref_root->right non-empty -------------------------
                    //     ref_root                                    ref_root
                    //     /     \       L rotation on p               /      \
                    //    p       z         ======>                   b        z
                    //  /   \                                       /   \
                    // a     b                                     p     y  
                    //      / \                                   / \
                    //     x   y                                 a   x
                    //
                    //
                    //                                              ||
                    //                                              || R rotation on ref_root
                    //                                              ||
                    //                                             \  /
                    //                                              \/
                    //
                    //
                    //
                    //                                                b
                    //                                             /     \
                    //                                           p      ref_root
                    //                                         /   \     /   \    
                    //                                        a     x   y     z
                    // ----------------------------case: ref_root->right empty -------------------------
                    //     ref_root                                    ref_root
                    //     /     \       L rotation on p               /      \
                    //    p                 ======>                   b        
                    //  /   \                                       /   \
                    //       b                                     p       
                    //
                    //
                    //                                              ||
                    //                                              || R rotation on ref_root
                    //                                              ||
                    //                                             \  /
                    //                                              \/
                    //
                    //
                    //
                    //                                                b
                    //                                             /     \
                    //                                           p      ref_root                    
                    State s = p->right->height;
                    left_rotate(p);
                    right_rotate(ref_root);
                    ref_root->height =  Balanced;
                    ref_root->right->height = s == LeftHigher ? RightHigher : Balanced;
                    ref_root->left->height = s == RightHigher ? LeftHigher : Balanced;
                    return true;
                }
                else {
                    // height(b) <= height(a)
                    //     ref_root                               p
                    //     /     \       R rotation             /   \
                    //    p               ======>              a  ref_root
                    //  /   \                                       /   \
                    // a     b                                     b                    
                    State s = p->height;
                    right_rotate(ref_root);
                    ref_root->height =  s == LeftHigher ? Balanced : RightHigher;
                    ref_root->right->height = s == LeftHigher ? Balanced : LeftHigher;
                    return s == LeftHigher;
                }
                return false;
            }
            else {
                // ref_root->height is either Balanced or RightHigher, deletion happens on the right tree.
                ref_root->height = (ref_root->height == Balanced ? LeftHigher : Balanced);
                return ref_root->height == Balanced;
            }
        }
    }
    else
    {
        if(ref_root->left && ref_root->right)
        {
            node* p = ref_root->right;
            while(p->left)
                p = p->left;
            std::swap(ref_root->key, p->key);
            --ref_root->size;
            // After we swap `key` to its smallest position in the right subtree, we continue to call
            // function delete_key(key, ref_root->right). This case is the same as "key > ref_root->key" case.
            if (delete_key(key, ref_root->right)) {
		        /* write something here.*/

            }
        }
        else
        {
            node *p = ref_root->left ? ref_root->left : ref_root->right;
            delete ref_root;
            ref_root = p;
            return true;
        }
    }
}

int KthMin(node * root, int k){
    if(root == 0 || k < 1 || k > root->size){
        printf("root %d, k %d\n", root->size, k);
        assert(0);
    }
    int lsize =  sizeOfTree(root->left);
    /* write something here.*/
}

int main()
{
    node *root = NULL;
    char op[10] = "";
    int k;
    while(true)
    {
        scanf("%s", op);
        if(op[0] == 'E') break;
        switch(op[0]) {
            case 'A': scanf("%d", &k); insert_key(k, root); break;
            case 'D': scanf("%d", &k); delete_key(k, root); break;
            case 'M': scanf("%d", &k); printf("%d\n", KthMin(root, k));break;
            default: assert(0);
        }
    }
    return 0;
}
