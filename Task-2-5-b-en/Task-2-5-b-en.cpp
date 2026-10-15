#include <iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
    int n; // Ticket price in rubles
    int x = 0; // Number of 4-ruble tokens
    int y = 0; // Number of 7-ruble tokens
    bool found = false; // Flag to indicate if a solution has been found
    // Input data
    std::cout << "Ticket price in rubles: ";
    std::cin >> n; // Input the ticket price
    y = n / 7; // Start with the maximum possible number of 7-ruble tokens
    // Iterate through the number of 7-ruble tokens from the maximum down to 0,
    // until a solution is found or we run out of 7-ruble tokens.
    while ((y >= 0) && (!found))
    {
        // Amount remaining after using 7-ruble tokens
        int remainder = n - 7 * y;
        // Check if the remainder can be covered by 4-ruble tokens
        if (remainder % 4 == 0)
        {
            // If the entire amount can be covered, exit the loop
            x = remainder / 4;
            // Display the found solution
            std::cout << "The entered price of " << n
            		  << " can be broken down into tokens:\r\n";
            std::cout << "Number of 4-ruble tokens: " << x << "\r\n";
            std::cout << "Number of 7-ruble tokens: " << y << "\r\n";
            // Set the flag variable to true,
            // since a solution has been found
            found = true;
        }
        y -= 1; // decrease the number of 7-ruble tokens
    }
    // No solutions exist for the specified amount
    if (!found)
    {
        std::cout << "The entered price " << n
        		  << " cannot be broken down into tokens\r\n";
    }
    // Pause the output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
    return 0;
}
