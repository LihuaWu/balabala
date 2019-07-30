int dfs(Node* self,  int& result) {
	if (self == NULL) {
		return 0;
	}
	int left_move = dfs(self->left, result);
	int right_move = dfs(self->right, result);
	result += abs(left_move) + abs(right_move);
	return root->val + left_move + right_move-1;
}
