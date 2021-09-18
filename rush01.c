#include <unistd.h>
/*
* ft_strsplit split a string by space/tab into an array of strings
* @use function: malloc
*/
char		**ft_strsplit(char *str);
int			ft_atoi(char *str);
/*
* ft_get_inputed_refs checks argv, splits it to str, then converts each to int
* return an array of ints, final int is 0
*/
int			*ft_get_inputed_refs(int argc, char **argv);
int			ft_get_size(int *refs);
int			ft_error(void);
/*
* ft_create_empty_matrix create an array of array of int.
* @use malloc
*/
int			**ft_create_empty_matrix(unsigned int size);
void		ft_putresult(int **matrix);
void		ft_putnbr(int nb);

int			ft_assign(int **matrix, int ref, int i, unsigned int size)
{
	if (i / size == 0)
	{
		//top
	}
	else if (i / size == 1)
	{
		//bottom
	}
	else if (i / size == 2)
	{
		//left
	}
	else
	{
		//right
	}
	return (0);
}

void		ft_assign_matrix(int **matrix, int *ref, unsigned int size)
{	
	unsigned int	i;
	int				has_previous_loop_assigned_something;
	
	while (1)
	{
		has_prev_loop_assigned_something = 0;
		i = 0;
		while (refs[i] != 0)
		{
			if (ft_assign(matrix, refs[i], i, size))
				has_prev_loop_assigned_something = 1;
			i++;
		}
		if (has_prev_loop_assigned_something == 0)
			return (ft_error());
	}
}

int			ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int			ft_is_valid_character(char c)
{
	if ((c >= '0' && c <= '9') || ft_is_space(c))
		return (1);
	return (0);
}

char		**ft_strsplit(char *str)
{
	char			**str_list;
	unsigned int	nbr_of_str;
	unsigned int	i;
	unsigned int	j;

	nbr_of_str = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) && i > 0 && ft_is_space(str[i - 1]) != 1)
			nbr_of_str++;
		i++;
	}
	str_list = malloc((nbr_of_str + 1) * sizeof(*str_list));
	i = 0;
	nbr_of_str = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) && j != 0)
		{
			str_list[nbr_of_str] = malloc((j + 1) * sizeof(**str));
			ft_strncpy(str_list[nbr_of_str], str + i - j, j + 1);
			j = 0;
		}
		else if (ft_is_space(str[i]) == 0)
			j++;
		i++;
	}
}

char		**ft_check_argv_and_get_str_list(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_is_valid_character(argv[1][i]))
			return (0);
		i++;
	}
	return ft_strsplit(argv[1]);
}

unsigned int		ft_get_size(char **str_list)
{
	unsigned int	size;
	unsigned int	nbr_of_str;

	if (!str_list)
		return (0);
	nbr_of_str = 0;
	while (str_list[nbr_of_str])
		nbr_of_str++;
	size = 0;
	while (1)
	{
		if (size * size == nbr_of_str)
			return (size)
		else if (size * size > nbr_of_str)
			return (0);
		size++;
	}
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int			ft_error(void)
{
	ft_putstr("error\n");
	return (1);
}

int			*ft_get_refs(char **str_list, unsigned int size)
{
	int				*refs;
	unsigned int	i;

	refs = malloc((size * size + 1) * sizeof(*refs));
	i = 0;
	while (str_list[i])
	{
		refs[i] = ft_str_to_int(str_list[i], size);
		if (refs[i] == 0)
			return 0;
		i++;
	}
	return refs;
}

int			main(int argc, char **argv)
{
	char			**str_list;
	unsigned int	size;
	int				*refs;
	int				**matrix;

	str_list = ft_check_argv_and_get_str_list(argc, argv);
	size = ft_get_size(str_list);
	if (size == 0)
		return (ft_error());
	refs = ft_get_refs(str_list);
	matrix = ft_create_empty_matrix(size);
	ft_assign_matrix(matrix, refs, size);
	return (0);
}
