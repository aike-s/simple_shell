#include "shell.h"
/**
 * _malloc - Save in memory
 * @GC: garbage collector
 * @size: size
 * Return: pointer in a new position
 */
void *_malloc(garbage_collector_t *GC, size_t size)
{
	unsigned long i;

	if (size == 0)
		return (NULL);
	GC->subscriptions[GC->malloc_acumulator] = malloc(size);
	if (GC->subscriptions[GC->malloc_acumulator] == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*((char *)GC->subscriptions[GC->malloc_acumulator] + i) = 0;

	GC->malloc_acumulator++;
	return (GC->subscriptions[GC->malloc_acumulator - 1]);
}
/**
 * search_free - look for the mallocs to free
 *
 * @GC: Garbage Colector
 * @current_to_do_free: Liberates the current malloc
 * Return: 1
 */

int search_free(garbage_collector_t *GC, void *current_to_do_free)
{
	int i;

	for (i = 0; i < GC->free_acumulator; i++)
	{
		if (current_to_do_free == GC->subscriptions_free[i])
			return (0);
	}
	return (1);
}

/**
 * _free_all - libera
 * @GC: garbage collector
 * Return: always void
 */
void _free_all(garbage_collector_t *GC)
{
	while (GC->malloc_acumulator > 0)
	{
		GC->malloc_acumulator -= 1;

		if (search_free(GC, GC->subscriptions[GC->malloc_acumulator]))
		{
			free(GC->subscriptions[GC->malloc_acumulator]);
			GC->subscriptions_free[GC->free_acumulator]
			= GC->subscriptions[GC->malloc_acumulator];
			GC->free_acumulator++;
		}
	}
}

/**
 * create_garbage_collector - create garbage collector
 * Return: GC
 */
garbage_collector_t *create_garbage_collector(void)
{
	garbage_collector_t *GC;

	GC = malloc(sizeof(garbage_collector_t));
	if (GC == NULL)
		return (NULL);

	GC->subscriptions = malloc(1024 * sizeof(void *));
	if (GC->subscriptions == NULL)
	{
		free(GC);
		return (NULL);
	}
	GC->subscriptions_free = malloc(1024 * sizeof(void *));
	if (GC->subscriptions_free == NULL)
	{
		free(GC->subscriptions);
		free(GC);
		return (NULL);
	}

	GC->malloc = _malloc;
	GC->free_all = _free_all;
	GC->malloc_acumulator = 0;
	GC->free_acumulator = 0;
	return (GC);
}
/**
 * free_garbage_collector - Liberate the function Grabe_colector
 *
 * @GC: garbage collector
 */
void free_garbage_collector(garbage_collector_t *GC)
{

	free(GC->subscriptions_free);
	free(GC->subscriptions);
}
