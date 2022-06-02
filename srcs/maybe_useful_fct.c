
int	count_elem_line(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] == '-' || str[i] == '+'))
			i++;
		if (ft_isalnum(str[i]))
			size++;
		while (ft_isalnum(str[i]))
			i++;
		if (!__is_valid_char(str[i]))
			return (-1);
		i++;
	}
	return (free(str), size);
}

int	map_size(int fd)
{
	char	*str;
	int		size;

	size = 0;
	str = __gnl(fd);
	if (!str)
		return (-1);
	while (str)
	{
		size = size + count_elem_line(str);
		str = __gnl(fd);
	}
	return (size);
}