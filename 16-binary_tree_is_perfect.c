#include "binary_trees.h"

/**
 * depth - Gets the depth of the leftmost leaf node
 * @tree: Pointer to the root node
 *
 * Return: Depth
 */
static int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively
 * @tree: Pointer to the current node
 * @level: Current level in the tree
 * @leaf_depth: Expected depth for all leaf nodes
 *
 * Return: 1 if perfect, 0 otherwise
 */
static int is_perfect_recursive(const binary_tree_t *tree,
				int level, int leaf_depth)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == leaf_depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (
		is_perfect_recursive(tree->left, level + 1, leaf_depth) &&
		is_perfect_recursive(tree->right, level + 1, leaf_depth)
	);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = depth(tree);
	return (is_perfect_recursive(tree, 1, d));
}
