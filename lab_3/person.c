#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  // Unique identifier for the person
  int id;
  // Information about person
  char name[20];
  int age;
  // Pointer to next person in list
  struct Person *next;
};

struct List {
  // First person in the list. A value equal to NULL indicates that the
  // list is empty.
  struct Person *head;
  // Current person in the list. A value equal to NULL indicates a
  // past-the-end position.
  struct Person *current;
  // Pointer to the element appearing before 'current'. It can be NULL if
  // 'current' is NULL, or if 'current' is the first element in the list.
  struct Person *previous;
};

struct List *globalList;
int current_id = 0;

// Give an initial value to all the fields in the list.
void ListInitialize(struct List *list) {
  list->head = NULL;
  list->current = NULL;
  list->previous = NULL;
}

// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(struct List *list) {
  if (list->current) {
    list->previous = list->current;
    list->current = list->current->next;
  }
}

// Move the current position to the first element in the list.
void ListHead(struct List *list) {
  list->previous = NULL;
  list->current = list->head;
}

// Get the element at the current position, or NULL if the current position is
// past-the-end.
struct Person *ListGet(struct List *list) {
  return list->current;
}

// Set the current position to the person with the given id. If no person
// exists with that id, the current position is set to past-the-end.
void ListFind(struct List *list, int id) {
  ListHead(list);
  while (list->current && list->current->id != id)
    ListNext(list);
}

// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(struct List *list, struct Person *person) {

  // Set 'next' pointer of current element
  person->next = list->current;

  // Set 'next' pointer of previous element. Treat the special case where
  // the current element was the head of the list.
  if (list->current == list->head)
    list->head = person;
  else
    list->previous->next = person;

  // Set the current element to the new person
  list->current = person;
}

// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(struct List *list) {

  // Ignore if current element is past-the-end
  if (!list->current)
    return;

  // Remove element. Consider special case where the current element is
  // in the head of the list.
  if (list->current == list->head)
    list->head = list->current->next;
  else
    list->previous->next = list->current->next;

  // Free element, but save pointer to next element first.
  struct Person *next = list->current->next;
  free(list->current);

  // Set new current element
  list->current = next;
}

void PrintPerson(struct Person *person) {
  printf("Person with ID %d:\n", person->id);
  printf("\tName: %s\n", person->name);
  printf("\tAge: %d\n\n", person->age);
}

// Prints the list
void ListPrint(struct List *list) {
  ListHead(list);
  while(list->current && list->current->id != current_id + 1) {
    PrintPerson(ListGet(globalList));
    ListNext(list);
  }
}

void addPerson() {
  current_id++;

  // Allocate person
  struct Person *person = malloc(sizeof(struct Person));

  // Set id
  person->id = current_id;

  // Read name
  printf("Enter name: ");
  scanf("%s", person->name);

  // Read age
  printf("Enter age: ");
  scanf("%d", &person->age);

  // Add person
  ListInsert(globalList, person);
}

void findPerson() {

  // Read id
  int id;
  printf("Enter ID: ");
  scanf("%d", &id);

  ListFind(globalList, id);

  struct Person *person = ListGet(globalList);

  if (person) {
    PrintPerson(person);
  } else {
    printf("Could not find person with ID: %d\n\n", id);
  }
}

void removePerson() {

  // Read id
  int id;
  printf("Enter ID: ");
  scanf("%d", &id);

  ListFind(globalList, id);

  struct Person *person = ListGet(globalList);

  if (person) {
    ListRemove(globalList);
  } else {
    printf("Could not find person with ID: %d\n\n", id);
  }
}

void sortArrayAge(struct Person *p, int size) {
	for (int x = 0; x < size; x++) {
		for (int y = x + 1; y < size; y++) {
			struct Person ax = p[x];
			struct Person ay = p[y];
			if (ay.age < ax.age) {
				p[y] = ax;
				p[x] = ay;
			}
		}
	}
}

void sortArrayName(struct Person *p, int size) {
	for (int x = 0; x < size; x++) {
		for (int y = x + 1; y < size; y++) {
			struct Person ax = p[x];
			struct Person ay = p[y];
			if (strcmp(ay.name, ax.name) <= 0) {
				p[y] = ax;
				p[x] = ay;
			}
		}
	}
}

void sortListAge() {

  struct Person *p = malloc(sizeof(struct Person) * current_id);

  ListHead(globalList);
  while(globalList->current && globalList->current->id != current_id + 1) {
    struct Person *x = ListGet(globalList);
    p[x->id] = *x;
    ListNext(globalList);
  }

  sortArrayAge(p, current_id);

  ListInitialize(globalList);

  for (int x = 0; x < current_id; x++) {
    ListInsert(globalList, &p[x]);
  }
}

void sortListName() {

  struct Person *p = malloc(sizeof(struct Person) * current_id);

  ListHead(globalList);
  while(globalList->current && globalList->current->id != current_id + 1) {
    struct Person *x = ListGet(globalList);
    p[x->id] = *x;
    ListNext(globalList);
  }

  sortArrayName(p, current_id);

  ListInitialize(globalList);

  for (int x = 0; x < current_id; x++) {
    ListInsert(globalList, &p[x]);
  }
}

/**
 * Prints the main menu
 */
void printMenu() {
  printf("Main menu:\n\n");
  printf("1. Add a person\n");
  printf("2. Find a person\n");
  printf("3. Remove a person\n");
  printf("4. Sort the list: Age\n");
  printf("5. Sort the list: Name\n");
  printf("6. Print the list\n");
  printf("7. Exit\n\n");
  printf("Select an option: ");
}

int main() {

  printf("Lab 3\n\n");

  // Create space for global list
  globalList = malloc(sizeof(struct Person));

  // Initialize the global list
  ListInitialize(globalList);

  // Enter the run loop
  while (1) {

    // Show the menu
    printMenu();

    // Read option from stdin
    int input;
    scanf("%d", &input);

    // Perform procedure based on option
    printf("You selected ");
    switch (input) {
      case 1:
        printf("\"Add a person\"\n\n");
        addPerson();
        break;
      case 2:
        printf("\"Find a person\"\n\n");
        findPerson();
        break;
      case 3:
        printf("\"Remove a person\"\n\n");
        removePerson();
        break;
      case 4:
        printf("\"Sort the list: Age\"\n\n");
        sortListAge();
        break;
      case 5:
        printf("\"Sort the list: Name\"\n\n");
        sortListAge();
        break;
      case 6:
        printf("\"Print the list\"\n\n");
        ListPrint(globalList);
        break;
      case 7:
        printf("\"Exit\"\n\n");
        free(globalList);
        return 0;
      default:
        printf("Invalid option!\n\n");
        break;
    }
  }
}
