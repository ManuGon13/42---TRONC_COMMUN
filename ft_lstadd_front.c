 

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("B");
	new = ft_lstnew("A");

	ft_lstadd_front(&lst, new);
	printf("1er maillon : %s\n", (char *)lst->content);
	printf("suivant : %s\n", (char *)lst->next->content);
	return (0);
}
