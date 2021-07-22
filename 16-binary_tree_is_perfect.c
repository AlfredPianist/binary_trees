#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if id full, 0 otherwise
 */
 
int binary_tree_is_perfect(const binary_tree_t *tree)
{

    if(tree == NULL)
        return (0);

    if (binary_tree_is_full(tree) && (binary_tree_balance(tree) == 0))
    {
        return (1);
    }
    return (0);
}

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 0;
	if (tree == NULL)
		return(0);
	
	if((tree->left == NULL && tree->right == NULL))
		return (1);

	is_full = binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
	return(is_full);
}

int binary_tree_balance(const binary_tree_t *tree)
{
    return(binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree || !(tree->left || tree->right))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (1 + (height_left >= height_right ? height_left : height_right));
}