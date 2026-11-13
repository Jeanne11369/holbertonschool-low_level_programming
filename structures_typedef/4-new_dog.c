#include <stdlib.h>
#include "dog.h"

/**
	* new_dog - Creates a new dog
	* @name: Name of the dog
	* @age: Age of the dog
	* @owner: Name of the owner
	*
	* Return: Pointer to new dog, or NULL on failure
	*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int i, len;

if (name == NULL || owner == NULL)
return (NULL);

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

for (len = 0; name[len] != '\0'; len++)
;

dog->name = malloc(len + 1);
if (dog->name == NULL)
{
free(dog);
return (NULL);
}

for (i = 0; i <= len; i++)
dog->name[i] = name[i];

for (len = 0; owner[len] != '\0'; len++)
;

dog->owner = malloc(len + 1);
if (dog->owner == NULL)
{
free(dog->name);
free(dog);
return (NULL);
}

for (i = 0; i <= len; i++)
dog->owner[i] = owner[i];

dog->age = age;

return (dog);
}
