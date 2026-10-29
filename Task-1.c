#include <stdio.h>  // Allows us to use printf() and fgets()
#include <string.h> // Allows us to use strcspn()

// Function to replace spaces and count them
int replace(char *str)
{
    int count = 0;          // Stores the number of spaces replaced

    while (*str != '\0')    // Repeat until the end of the string
    {
        if (*str == ' ')    // Check if the current character is a space
        {
            *str = '-';     // Replace the space with a hyphen
            count++;        // Increase the replacement count
        }

        str++;              // Move to the next character
    }

    return count;           // Return the number of spaces replaced
}

int main(void)               // Main function: program starts here
{
    char data[50];           // Create a string
    int n;                   // Store the number of spaces replaced

    printf("Enter a string: "); // Ask the user to enter a string

    fgets(data, sizeof(data), stdin); // Read the input, including spaces

    data[strcspn(data, "\n")] = '\0'; // Remove the newline at the end

    printf("String was : %s\n", data); // Print the original string

    n = replace(data);        // Replace spaces and store the count

    printf("String is : %s\n", data); // Print the modified string
    printf("Number replaced %d\n", n); // Print the number replaced

    return 0;                // End the program successfully
}