#include <stdio.h>
#include <stdlib.h>

// Global vars
double *v;
int count;
int size;

/**
 * Initializes global variables
 */
void initialize() {
  count = 0;
  size = 2;
  v = malloc(sizeof(double) * size);
}

/**
 * Frees resources and exits
 */
int finalize() {
  free(v);
  return 0;
}

/**
 * Grow the array by a certain size
 */
void grow(int growSize) {
  printf("Vector grown\n");
  printf("Previous capacity: %d elements\n", size);

  // increment size
  size = size + growSize;

  // allocate new memory space
  double *x = malloc(sizeof(double) * size);

  // copy elements
  for (int i = 0; i < count; i++) {
    x[i] = v[i];
  }

  // free old memory
  free(v);

  // reassign global pointer to new memory
  v = x;

  printf("New capacity: %d elements\n", size);
}

/**
 * Shrink the array if capacity is less than 50%
 */
void shrink() {
  if (count < (size / 2)) {
    grow((size / 2) * -1);
  }
}

/**
 * Insert an element to the array
 */
void insertElement() {

  int index;
  printf("Enter the index of new element: ");
  scanf("%d", &index);

  double value;
  printf("Enter the new element: ");
  scanf("%lf", &value);

  // create double capacity
  if (count == size) {
    grow(size);
  }

  // shift elements
  for (int i = count; i > index; i--) {
    v[i] = v[i-1];
  }

  // add element
  v[index] = value;

  // increase count
  count++;
}

/**
 * Append an element to the array
 */
void appendElement() {

  double value;
  printf("Enter the new element: ");
  scanf("%lf", &value);

  // create double capacity
  if (count == size) {
    grow(size);
  }

  // assign element
  v[count] = value;

  // increase count
  count++;
}

/**
 * Remove last element
 */
void removeElement() {

  if (count == 0) {
    printf("There are no elements in the array.\n\n");
    return;
  }

  // decrease count
  count--;

  // shrink if needs
  shrink();
}

/**
 * Prints the contents of the given array
 */
void printArray(double *arr, int length) {
  printf("[ ");
  for (int i = 0; i < length; i++) {
    printf("%f, ", arr[i]);
  }
  printf("null ]\n\n");
}

/**
 * Prints the main menu
 */
void printMenu() {
  printf("Main menu:\n\n");
  printf("1. Print the array\n");
  printf("2. Append element at the end\n");
  printf("3. Remove last element\n");
  printf("4. Insert one element\n");
  printf("5. Exit\n\n");
  printf("Select an option: ");
}

int main() {

  printf("Lab 2\n\n");

  // Initialize global vars
  initialize();

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
        printf("\"Print the array\"\n\n");
        printArray(v, count);
        break;
      case 2:
        printf("\"Append element at the end\"\n\n");
        appendElement();
        break;
      case 3:
        printf("\"Remove last element\"\n\n");
        removeElement();
        break;
      case 4:
        printf("\"Insert one element\"\n\n");
        insertElement();
        break;
      case 5:
        printf("\"Exit\"\n\n");
        return finalize();
      default:
        printf("Invalid option!\n\n");
        break;
    }
  }
}
