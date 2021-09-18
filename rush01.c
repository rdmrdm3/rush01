/*
* ft_strsplit split a string by space/tab into an array of strings
* @use function: malloc
*/
char		**ft_strsplit(char *str);
int			ft_str_to_int(char *str);
int			ft_check_argv(int argc, char **argv);
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

int			main(int argc, char **argv)
{
	int				*refs;
	unsigned int	size;
	int				**matrix;

	refs = ft_get_inputed_refs(argc, argv);
	size = ft_get_size(refs);
	if (!refs || size == 0)
		return (ft_error());
	matrix = ft_create_empty_matrix(size);
	ft_assign_matrix(matrix, refs, size);
	return (0);
}
