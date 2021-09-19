#include <unistd.h>
#include <stdlib.h>

int	ft_str_is_numeric_or_space(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_test_argv1_norm(char *argv1)
{
	int i;

	if (ft_strlen(argv1) != 31)
		return (0);
	i = 0;
	while (argv1[i] != '\0')
	{
		if (i % 2 == 1)
		{
			if (!(argv1[i] == ' '))
				return (0);
		}
		else
		{
			if (!(argv1[i] >= '1' && argv1[i] <= '4'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	*ft_get_refs(char *argv1)
{
	int i;
	int	*refs;
	
	refs = malloc(16 * sizeof(int));

	i = 0;
	while (i <= 30)
	{
		if (i % 2 == 0)
			refs[i / 2] = argv1[i] - '0';
	}
	return (refs);
}

int	ft_check_arg(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		return (0);
	if (ft_str_is_numeric_or_space(argv[1]) == 0)
		return (0);
	return (ft_test_argv1_norm(argv[1]));
}

int	main(int argc, char **argv)
{
	int	*refs;
	
	if (ft_check_arg(argc, argv) == 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	refs = ft_get_refs(argv[1]);
	free(refs);
	return (0);
}
