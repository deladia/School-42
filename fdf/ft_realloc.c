#include "fdf.h"

void	*ft_realloc(void *src, size_t old, size_t new)
{
	void	*dest;

	if (src == NULL)
		src = (void *)ft_memalloc(sizeof(void) * new);
	if (new == 0)
		return(NULL);
	if ((dest = ft_memalloc(new)) == NULL)
		return (NULL);
	ft_memcpy(dest, src, (old < new) ? old : new);
	free (src);
	return (dest);
}