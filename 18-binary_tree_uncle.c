#include "binary_trees.h"

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    
    if (node->parent->parent == NULL)
        return NULL;
    binary_tree_t *grandpa = node->parent->parent;
    
    if (node == NULL || node->parent == NULL)
        return NULL;
    if (grandpa->left== NULL || grandpa->right == NULL)
        return NULL;
    
    if (grandpa->left->n == node->parent->n){
        return (grandpa->right);
    }else{
        return (grandpa->left);
    }
}