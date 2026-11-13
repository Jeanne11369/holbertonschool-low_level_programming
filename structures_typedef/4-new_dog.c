#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Owner's name
 *
 * Return: Pointer to new dog, or NULL on failure
 */

dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int len;

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

len = strlen(name) + 1;
dog->name = malloc(len);

if (dog->name == NULL)
{
free(dog);
return (NULL);
}

strcpy(dog->name, name);

len = strlen(owner) + 1;
dog->owner = malloc(len);

if (dog->owner == NULL)
{
free(dog->name);
free(dog);
return (NULL);
}

strcpy(dog->owner, owner);
dog->age = age;

return (dog);
}
