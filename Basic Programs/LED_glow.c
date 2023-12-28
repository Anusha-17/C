#include <stdio.h>
#include <unistd.h>

void glowLED(int value) {
    // Simulating LED glow, you can replace this with actual hardware control
    printf("LEDs: %d\n", value);
    sleep(1);  // Adjust the sleep duration as needed
}

int reverseBits(int num, int bits) {
    int result = 0;
    for (int i = 0; i < bits; i++) {
        result = (result << 1) | (num & 1);
        num >>= 1;
    }
    return result;
}

int main() {
    int bits = 8;
    int userChoice;

    printf("Enter 1 to toggle LEDs in ascending and descending order: ");
    scanf("%d", &userChoice);

    if (userChoice == 1) {
        // Ascending order
        for (int i = 0; i < (1 << bits); i++) {
        	printf("Ascending order\n");
            glowLED(i);
        }

        // Descending order with reversed bits
        for (int i = (1 << (bits - 1)); i >= 0; i--) {
            int reversed = reverseBits(i, bits);
            printf("Descending order\n");
            glowLED(reversed);
        }
    } else {
        printf("Invalid choice. Please enter 1 to toggle LEDs.\n");
    }

    return 0;
}
