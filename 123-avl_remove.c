#include "binary_trees.h"

avl_t *avl_rebalance_2(avl_t *node, avl_t **tree);
bst_t *bst_search(const bst_t *tree, int value);

/**
 * avl_remove - Deletes a value on a AVL tree.
 *
 * @root: The AVL to be searched upon.
 * @value: The value to be deleted.
 *
 * Return: pointer to the new root node of AVL.
 */
avl_t *avl_remove(bst_t *root, int value)
{
	bst_t *rebalance, *delete_node, *successor;
	int successor_val;

	delete_node = (avl_t *) bst_search((bst_t *) root, value);
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
		rebalance = delete_node->parent;
		free(delete_node);
		avl_rebalance_2(rebalance, &root);
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
		rebalance = delete_node->right;
		free(delete_node);
		avl_rebalance_2(rebalance, &root);
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
		rebalance = delete_node->left;
		free(delete_node);
		avl_rebalance_2(rebalance, &root);
	}
	/* Two child nodes, in-order successor (from right child, the leftmost) */
	else
	{
		for (successor = delete_node->right; successor->left;
		     successor = successor->left)
			;
		successor_val = successor->n;
		avl_remove(root, successor_val);
		delete_node->n = successor_val;
		rebalance = delete_node->right;
		avl_rebalance_2(rebalance, &root);
	}
	return (root);
}

/**
 * avl_rebalance_2 - Rebalancing algorithm for the AVL tree.
 *
 * @node: The node of the tree be traversed upwards the AVL tree checking
 *        each subtree's balance.
 * @tree: The root of the AVL tree.
 *
 * Return: pointer to new node in AVL tree.
 */
avl_t *avl_rebalance_2(avl_t *node, avl_t **tree)
{
	int balance, balance_prev;
	avl_t *parent = node;

	balance = balance_prev = 0;
	while (parent)
	{
		balance_prev = balance;
		balance = binary_tree_balance(parent);

		/* Left */
		if (balance > 1)
		{
			/* Right */
			if (balance_prev < 0)
				binary_tree_rotate_left((binary_tree_t *) parent->left);
			/* Left */
			parent = (avl_t *) binary_tree_rotate_right((binary_tree_t *) parent);
		}
		/* Right */
		if (balance < -1)
		{
			/* Left */
			if (balance_prev > 0)
				binary_tree_rotate_right((binary_tree_t *) parent->right);
			/* Right */
			parent = (avl_t *) binary_tree_rotate_left((binary_tree_t *) parent);
		}
		/* Update root if affected */
		if (!parent->parent)
			*tree = parent;
		parent = parent->parent;
	}
	return (node);
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
