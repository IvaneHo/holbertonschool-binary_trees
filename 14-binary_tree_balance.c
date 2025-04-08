#include "binary_trees.h"

/**
 * binary_tree_height -  Measures the height of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * Description: The difference between the height of the left subtree
 *              and the height of the right subtree for a given node.
 *
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: The number of leaves, or 0 if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}