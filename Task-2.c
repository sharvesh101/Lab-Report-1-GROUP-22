#include <stdio.h>  // Allows us to use printf() and fgets()
#include <string.h> // Allows us to use strcspn()

// Function to encode lowercase letters
void code(char *str)
{
    char code1[] = "abcdefghijklmnopqrstuvwxyz"; // Original letters
    char code2[] = "bpduhijkaltxwmrzfoysvngeqc";  // Encoded letters
    int i;                       // Stores the position in the alphabet

    while (*str != '\0')         // Repeat until the end of the string
    {
        for (i = 0; i < 26; i++) // Check all 26 lowercase letters
        {
            if (*str == code1[i]) // Check if the character matches
            {
                *str = code2[i];  // Replace it with the encoded letter
                break;            // Stop searching for this character
            }
        }

        str++;                   // Move to the next character
    }
}

int main(void)                   // Main function: program starts here
{
    char data[50];               // Create space to store the input string

    printf("Enter a string: ");  // Ask the user to enter a string

    fgets(data, sizeof(data), stdin); // Read the input, including spaces

    data[strcspn(data, "\n")] = '\0'; // Remove the newline at the end

    printf("String was : %s\n", data); // Print the original string

    code(data);                   // Encode the string

    printf("String is : %s\n", data); // Print the encoded string

    return 0;                    // End the program successfully
}