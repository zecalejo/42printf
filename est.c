#include <unistd.h>

typedef	int	t_call(char *c);

int	ft_putchar(char *c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

void	init_call(t_call *call_list[121])
{
	call_list['c'] = &ft_putchar;
	call_list['s'] = &ft_putstr;
}

void	call_back(char *str, char *string)
{
	static int	index;

	while (str[index] && str[index] != '%')
			index++;
	if (index)
		write(1, str, index);
	static t_call	*call_list[121];
	init_call(call_list);
	if (call_list[(int)*(str + index + 1)])
		call_list[(int)*(str + index + 1)](string);
}

int	main()
{
	call_back("Insert = %s", "Hello");
	return (0);
}