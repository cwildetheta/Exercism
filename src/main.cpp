#include "base_functions.h"
#include "functions.h"
#include <iostream>
#include <windows.h>
#include <map>
#include <functional>

std::map<int, std::function<void()>> function_map{
    {1, leap_year_check},
    {2, reverse_string},
    {3, planetary_age},
    {4, triangle_type},
    {5, chess_board_grains},
    {6, raindrops},
    {7, pangram},
    {8, twofer},
    {9, school_directory},
    {10, hamming},
    {11, nucleotide_count},
    {12, DNA_to_RNA},
    {13, collatz},
    {14, difference_of_squares},
    {15, Nth_prime},
    {16, queen_attack},
    {17, sieve_of_eratosthenes},
    {18, integer_to_english},
    {19, add_gigasecond},
    {20, binary_wink},
    {21, allergies},
    {22, protein_translation},
    {23, sum_of_multiples},
    {24, prime_factors},
    {25, bottles_of_beer},
    {26, atbash},
    {27, trinary_to_decimal},
    {28, phone_number}
}; 

int main()
{
    bool in_exercism = true;
    while(in_exercism == true){
        system("cls");
        std::cout << "Which program do you want to run?" << std::endl;
        std::cout << "1. Determining if an entered year is a leap year." << std::endl;
        std::cout << "2. Reversing an entered string." << std::endl;
        std::cout << "3. Working out the age of a person in all the planet's years, based on a entered number of seconds." << std::endl;
        std::cout << "4. Checking what type of triangle three side lengths produce." << std::endl;
        std::cout << "5. Grain chess board, doubling the number of grains on the next tile." << std::endl;
        std::cout << "6. Raindrops, basically fizzbuzz." << std::endl;
        std::cout << "7. Pangram, determining if a sentence uses every letter in the alphabet." << std::endl;
        std::cout << "8. One for <enter name here>, two for me." << std::endl;
        std::cout << "9. School directory system." << std::endl;
        std::cout << "10. Hamming distance." << std::endl;
        std::cout << "11. Nucleotide count." << std::endl;
        std::cout << "12. DNA to RNA." << std::endl;
        std::cout << "13. Collatz Conjecture." << std::endl;
        std::cout << "14. Difference of squares." << std::endl;
        std::cout << "15. Nth Prime." << std::endl;
        std::cout << "16. Queen attack." << std::endl;
        std::cout << "17. Sieve of Eratosthenes." << std::endl;
        std::cout << "18. Integer to English." << std::endl;
        std::cout << "19. Gigasecond." << std::endl;
        std::cout << "20. Secret handshake." << std::endl;
        std::cout << "21. Allergies." << std::endl;
        std::cout << "22. Protein Translation." << std::endl;
        std::cout << "23. Sum of multiples." << std::endl;
        std::cout << "24. Prime factors." << std::endl;
        std::cout << "25. Bottles of beer." << std::endl;
        std::cout << "26. Atbash." << std::endl;
        std::cout << "27. Trinary to decimal." << std::endl;
        std::cout << "28. Phone number." << std::endl;
        std::cout << "0. Exit system." << std::endl;
        int program_choice = int_value_checker("Enter an integer between 0 and 28: ", 0, 28);
        system("cls");
        if(program_choice == 0){
            in_exercism = false;
        }
        else{
            function_map.find(program_choice)->second();
            system("pause");
        }
    }
    return 0;
}