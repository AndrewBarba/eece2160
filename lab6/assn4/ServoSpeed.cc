#include <stdio.h>
#include "GPIO.h"

int main() {

  while (1) {

    int servo;
    printf("Select a servo:\n");
    printf("1. Base\n");
    printf("2. Bicep\n");
    printf("3. Elbow\n");
    printf("4. Wrist\n");
    printf("5. Gripper\n--> ");
    scanf("%d", &servo);

    int num;
    switch (servo) {
      case 1:
        num = 13;
        break;
      case 2:
        num = 10;
        break;
      case 3:
        num = 11;
        break;
      case 4:
        num = 12;
        break;
      case 5:
        num = 0;
        break;
    }

    int angle1;
    printf("Enter start angle between 0 and 180 degrees:\n--> ");
    scanf("%d", &angle1);

    int angle2;
    printf("Enter end angle between 0 and 180 degrees:\n--> ");
    scanf("%d", &angle2);

    int speed;
    printf("Enter rotational velocity in degrees per second:\n--> ");
    scanf("%d", &speed);

    GPIO *gpio = new GPIO(num);
    gpio->GenerateVariablePWM(20000, 600 + (angle1 * 10), 600 + (angle2 * 10),  periods);
  }

  return 0;
}
