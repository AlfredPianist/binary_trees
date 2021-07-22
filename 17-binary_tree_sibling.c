#include "binary_trees.h"
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    binary_tree_t *parent = node->parent;
    if (node == NULL || node->parent == NULL)
        return NULL;
        
    if (parent->left == NULL || parent->right == NULL)
        return NULL;
    
    if (parent->left->n == node->n){
        return (parent->right);
    }else{
        return (parent->left);
    }

}