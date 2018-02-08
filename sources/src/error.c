#include <lem-in.h>

void	lem_error(int code)
{
	static char	*msg[] = {
		"ERROR"
	};

	ft_printf("%{RD}%s%{nc}\n", msg[code]);
	exit(0);
}
