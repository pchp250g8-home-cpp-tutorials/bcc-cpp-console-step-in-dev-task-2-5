#include <iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int n, n_orig; // ticket price in rubles
    int x = 0; // number of 4-ruble tokens
    int y = 0; // number of 7-ruble tokens
    int max_y; // maximum number of 7-ruble tokens
    // Data input
    std::cout << "Ticket price in rubles: ";
    std::cin >> n; // Input the ticket price
    n_orig = n; // Store the entered value for output
    // Iterate through the number of 7-ruble tokens, from the maximum down to 0
    max_y = n / 7;
    for (y = max_y; y >= 0; y--)
    {
        // Amount after accounting for 7-ruble tokens
        int remainder = n - 7 * y;
        // Check if the remainder can be covered by 4-ruble tokens
        if (remainder % 4 == 0)
        {
            // If the entire amount is successfully covered, exit the loop
            x = remainder / 4;
            // Display the found solution
            std::cout << "The entered price of " << n_orig
                      << " can be broken down into tokens:\r\n";
            std::cout << "Number of 4-ruble tokens: " << x << "\r\n";
            std::cout << "Number of 7-ruble tokens: " << y << "\r\n";
            break;
        }
    }
    // No solutions for the specified amount
    if ((x <= 0) && (y <= 0))
    {
        std::cout << "The entered amount " << n_orig
        		  << " cannot be broken down into tokens\r\n";
    }
    // Pause output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
    return 0;
}
