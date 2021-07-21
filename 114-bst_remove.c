#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);

/**
 * bst_remove - Deletes a value on a Binary Search Tree.
 *
 * @root: The BST to be searched upon.
 * @value: The value to be deleted.
 *
 * Return: pointer to the new root node of BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *delete_node, *successor;
	int successor_val;

	delete_node = bst_search(root, value);
	if (!delete_node)
		return (root);
	/* Leaf node */
	if (!(delete_node->left || delete_node->right))
	{
		if (!delete_node->parent)
			root = NULL;
		else if (delete_node->parent->left == delete_node)
			delete_node->parent->left = NULL;
		else if (delete_node->parent->right == delete_node)
			delete_node->parent->right = NULL;
		free(delete_node);
	}
	/* One child only */
	else if (!delete_node->left && delete_node->right)
	{
		if (!delete_node->parent)
			root = delete_node->right;
		else if (delete_node->parent->left == delete_node)
			delete_node->parent->left = delete_node->right;
		else if (delete_node->parent->right == delete_node)
			delete_node->parent->right = delete_node->right;
		delete_node->right->parent = delete_node->parent;
		free(delete_node);
	}
	else if (delete_node->left && !delete_node->right)
	{
		if (!delete_node->parent)
			root = delete_node->left;
		else if (delete_node->parent->left == delete_node)
			delete_node->parent->left = delete_node->left;
		else if (delete_node->parent->right == delete_node)
			delete_node->parent->right = delete_node->left;
		delete_node->left->parent = delete_node->parent;
		free(delete_node);
	}
	/* Two child nodes, in-order successor (from right child, the leftmost) */
	else
	{
		for (successor = delete_node->right; successor->left;
		     successor = successor->left)
			;
		successor_val = successor->n;
		bst_remove(root, successor_val);
		delete_node->n = successor_val;
	}
	return (root);
}

/**
 * bst_search - Searches for a value on a Binary Search Tree.
 *
 * @tree: The BST to be searched upon.
 * @value: The value to be searched.
 *
 * Return: pointer to the node in BST that matches the value, NULL otherwise.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));

	return (NULL);
}
