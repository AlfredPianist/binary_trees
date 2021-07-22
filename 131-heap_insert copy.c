#include "binary_trees.h"

int power(int num, int power);
/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int leaves, sublevel, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	leaves = binary_tree_size(tree);
		
	for (level = 0, sublevel = 1; leaves >= sublevel; level++, sublevel *= 2)
	{
		leaves = leaves - sublevel;
	}
	printf("\ndatos para el valor %d\nleaves -> %d\nlevel -> %d\nsublevel -> %d\n", value, leaves, level, sublevel);
	printf("------------------\n");
	for (bit = power(2, (level - 1)); bit != 1; bit = bit / 2){
		printf("bit: %d\n", bit);
		tree = leaves & bit ? tree->right : tree->left;
	}

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	
	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t countnode = 0;

	if (!tree)
		return (0);

	countnode = 1 + binary_tree_size(tree->right) + binary_tree_size(tree->left);
	return (countnode);
}

/**
 * power - function pow
 * @num: num base
 * @power: to power
 * Return: the pow of the num
 */
int power(int num, int power)
{
	int p = 1;

	for(int i = 1; i <= power; i++)
	{
		p *= num;
	}
	return(p);
}
