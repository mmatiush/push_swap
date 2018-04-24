#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// char*	check_output()
// {

// }

int		main(int ac, char **av)
{
	char *res;
	int result;

	while ((result = get_next_line(0, &res)) == 1)
	{
		printf("<<<%s>>>\n", res);
		free(res);
	}

	return 0;
}