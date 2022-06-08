#include "functions.h"
#include "base_functions.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <vector>

void leap_year_check() //Code for determining if an entered year is a leap year.
{
    int year;
    std::cout << "Input a year: ";
    std::cin >> year;
    if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
        std::cout << "The year " << year << " is a leap year." << std::endl;
    }
    else{
        std::cout << "The year " << year << " is not a leap year." << std::endl;
    }
}
void reverse_string() //Reversing an entered string.
{
    std::string inputstring1;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputstring1);
    int stringlength = inputstring1.length();
    int character = stringlength - 1;
    for(int i = 0; i < (stringlength/2); i++){
        std::swap(inputstring1[i], inputstring1[character]);
        character = character - 1;
    }
    std::cout << "The reversed string is: " << inputstring1 << std::endl;
}
void planetary_age() //Working out the age of a person in all the planet's years, based on a entered number of seconds.
{
    int age_in_seconds;
    std::cout << "Enter a length of time in seconds: ";
    std::cin >> age_in_seconds;
    float mercury_age, venus_age, earth_age, mars_age, jupiter_age, saturn_age, uranus_age, neptune_age;
    earth_age = float(age_in_seconds)/31557600;
    mercury_age = earth_age/0.2408467;
    venus_age = earth_age/0.61519726;
    mars_age = earth_age/1.8808158;
    jupiter_age = earth_age/11.862615;
    saturn_age = earth_age/29.447498;
    uranus_age = earth_age/84.016846;
    neptune_age = earth_age/164.79132;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The person is " << mercury_age << " mercurian years old." << std::endl;
    std::cout << "The person is " << venus_age << " cytherean years old." << std::endl;
    std::cout << "The person is " << earth_age << " terrestial years old." << std::endl;
    std::cout << "The person is " << mars_age << " martian years old." << std::endl;
    std::cout << "The person is " << jupiter_age << " jovian years old." << std::endl;
    std::cout << "The person is " << saturn_age << " saturian years old." << std::endl;
    std::cout << "The person is " << uranus_age << " uranian years old." << std::endl;
    std::cout << "The person is " << neptune_age << " neptunian years old." << std::endl;
}
void triangle_type() //Checking what type of triangle three side lengths produce.
{
    int trilength1, trilength2, trilength3;
    std::cout << "Enter the first triangle length: ";
    std::cin >> trilength1;
    std::cout << "Enter the second triangle length: ";
    std::cin >> trilength2;
    std::cout << "Enter the third triangle length: ";
    std::cin >> trilength3;
    if(trilength1 > (trilength2 + trilength3) || trilength2 > (trilength1 + trilength3) || trilength3 > (trilength1 + trilength2)){
        std::cout << "One of the sides entered is longer than the other two combined, so this is not a valid triangle." << std::endl;
    }
    else if(trilength1 == 0 || trilength2 == 0 || trilength3 == 0){
        std::cout << "One or more of the entered sides has a length of 0; this is not a valid triangle." << std::endl;
    }
    else if(trilength1 < 0 || trilength2 < 0 || trilength3 < 0){
        std::cout << "One or more of the entered sides is negative; this is not a valid triangle." << std::endl;
    }
    else if(trilength1 == (trilength2 + trilength3) || trilength2 == (trilength1 + trilength3) || trilength3 == (trilength1 + trilength2)){
        std::cout << "One of the sides equals the length of the other two, making this a degenerate triangle." << std::endl;
    }
    else{
        if(trilength1 == trilength2 && trilength1 == trilength3){
            std::cout << "All the sides are the same length, this is an equilateral triangle." << std::endl;
        }
        else if(trilength1 == trilength2 && trilength1 != trilength3){
            std::cout << "Side 1 and 2 are the same length, but side 3 is not, making this an isosceles triangle." << std::endl;
        }
        else if(trilength1 == trilength3 && trilength1 != trilength2){
            std::cout << "Side 1 and 3 are the same length, but side 2 is not, making this an isosceles triangle." << std::endl;
        }
        else if(trilength2 == trilength3 && trilength2 != trilength1){
            std::cout << "Side 2 and 3 are the same length, but side 1 is not, making this an isosceles triangle." << std::endl;
        }
        else{
            std::cout << "All the sides are of different length, so this is a scalene triangle." << std::endl;
        }
    }
}
void chess_board_grains() //Grain chess board, doubling the number of grains on the next tile.
{
    unsigned long long grainchessboard[8][8];
    unsigned long long grain_total = 0;
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            if(i > 0 && k == 0){
                grainchessboard[i][k] = 2* grainchessboard[i-1][7];
            }
            else if(i == 0 && k == 0){
                grainchessboard[i][k] = 1;
            }
            else{
                grainchessboard[i][k] = 2*grainchessboard[i][k-1];
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 8; k++){
            grain_total = grain_total + grainchessboard[i][k];
            std::cout << " " << std::setw(19) << grainchessboard[i][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "The total number of grains is: " << grain_total << std::endl;
}
void raindrops() //Raindrops, basically fizzbuzz.
{
    for(int i = 1; i < 51; i++){
        if(i%3 == 0 || i%5 == 0 || i%7 == 0){
            std::string raindrops;
            if(i%3 == 0){
                raindrops = raindrops + "Pling";
            }
            if(i%5 == 0){
                raindrops = raindrops + "Plang";
            }
            if(i%7 == 0){
                raindrops = raindrops + "Plong";
            }
            std::cout << " " << raindrops << " ";
        }
        else{
            std::cout << " " << i << " ";
        }
    }
}
void pangram() //Pangram, determining if a sentence uses every letter in the alphabet.
{
    bool missing_letter = false;
    std::string sentence;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::cin.ignore();
    std::cout << "Enter a string here: ";
    std::getline(std::cin, sentence);
    int sentence_length = sentence.length();
    for(int k = 0; k < 26; k++){
        bool letter = false;
        for(int i = 0; i < sentence_length; i++){
            if(sentence[i] == alphabet[k]){
                letter = true;
            }
        }
        if(letter == false){
            missing_letter = true;
        }
    }
    if(missing_letter == true){
        std::cout << "This sentence is not a Pangram" << std::endl;
    }
    else{
        std::cout << "This sentence is a Pangram" << std::endl;
    }
}
void twofer() //One for <enter name here>, two for me.
{
    std::string twofer = "One for ";
    std::cout << "Enter name here: ";
    std::string name_entry1;
    std::getline(std::cin, name_entry1);
    if(name_entry1 == ""){
        twofer = twofer + "you, two for me.";
    }
    else{
        bool name_entry1_empty = true;
        for(int i = 0; i < name_entry1.length(); i++){
            if(name_entry1[i] != ' '){
                name_entry1_empty = false;
            }
        }
        if(name_entry1_empty == true){
            twofer = twofer + "you, two for me.";
        }
        else{
            twofer = twofer + name_entry1 + ", two for me.";
        }
    }
    std::cout << twofer << std::endl;
}
void school_directory() //School directory system. Removing still doesn't work properly, but that isn't required, so moved on for a change of pace
{
    bool in_school_grade_loop = true;
    std::string student_enrollment[6][50];
    int gradetotals[6] = {0,0,0,0,0,0};
    while(in_school_grade_loop == true){
        char entry;
        system("cls");
        std::cout << "Would you like to add a student ('a'), remove a student ('r'), see the enrolled students ('e'), or quit the system ('q')?" << std::endl;
        std::cout << "Please enter a selection: ";
        std::cin >> entry;
        switch(entry){
            case 'a':
            case 'A':{
                bool in_add_student = true;
                while(in_add_student == true){
                    int grade;
                    std::string student_name;
                    std::cout << "What is the name of the student: ";
                    std::cin.ignore();
                    std::getline(std::cin, student_name);
                    std::cout << "Which grade do you want to add them to? Enter a number between 1 and 6, or press 0 to exit: ";
                    std::cin >> grade;
                    if(grade > 0 && grade < 7){
                        if(gradetotals[grade-1] == 50){
                            std::cout << "There are already 50 students in that grade, it is full." << std::endl;
                            Sleep(500);
                        }
                        else{
                            student_enrollment[grade-1][gradetotals[grade-1]] = student_name;
                            gradetotals[grade-1]++;
                            std::cout << student_name << " added to grade " << grade << "." << std::endl;
                            Sleep(1000);
                        }
                    }
                    else if(grade == 0){
                        in_add_student = false;
                    }
                    else{
                        std::cout << "Not a valid entry, please try again." << std::endl;
                    }
                }
                break;
            }
            case 'r':
            case 'R':{
                bool in_remove_student = true;
                while(in_remove_student == true){
                    int grade;
                    std::cout << "Which grade would you like to remove a student from? Enter a number between 1 and 6, or press 0 to exit: ";
                    std::cin >> grade;
                    if(grade == 0){
                        in_remove_student = false;
                    }
                    else if(grade > 0 && grade < 7){
                        if(gradetotals[grade-1] == 0){
                            std::cout << "There are no students in that grade, please try again." << std::endl;
                        }
                        else if(gradetotals[grade-1] == 1){
                            std::cout << "The student in grade " << grade << " is: " << student_enrollment[grade-1][0] << std::endl;
                        }
                        else{
                            std::cout << "The students in grade " << grade << " are: ";
                            for(int i = 0; i < gradetotals[grade-1]; i++){
                                std::cout << student_enrollment[grade-1][i];
                                if(i == gradetotals[grade-1]-1){
                                    std::cout << "." << std::endl;
                                }
                                else if(i == gradetotals[grade-1]-2){
                                    std::cout << ", and ";
                                }
                                else{
                                    std::cout << ", ";
                                }
                            }
                        }
                        if(gradetotals[grade-1] > 0){
                            if(gradetotals[grade-1] == 1){
                                std::cout << "If you would like to remove " << student_enrollment[grade-1][0] << " press 1, or 0 to exit: ";
                            }
                            else{
                                std::cout << "Which student would you like to remove? Select a number between 1 and " << gradetotals[grade-1] << ", or press 0 to exit: ";
                            }
                            int entry_2;
                            std::cin >> entry_2;
                            if(entry_2 > 0 && entry_2 <= gradetotals[grade-1]){
                                for(int i = 0; i < (gradetotals[grade-1]-entry_2+1); i++){
                                    student_enrollment[grade-1][entry_2+i-1] = student_enrollment[grade-1][entry_2+i];
                                }
                                student_enrollment[grade-1][gradetotals[grade-1]] = "";
                                gradetotals[grade-1]--;
                            }
                            else if(entry_2 == 0){
                                Sleep(500);
                                in_remove_student = false;
                            }
                            else{
                                std::cout << "Not a valid entry." << std::endl;
                            }
                        }
                    }
                    else{
                        std::cout << "Not a valid entry, please try again." << std::endl;
                    }
                }
                break;
            }
            case 'e':
            case 'E':{
                bool in_view_students = true;
                while(in_view_students == true){
                    int grade;
                    std::cout << "Which grade would you like to view? Enter a number between 1 and 6, press 7 to view all, or press 0 to exit: ";
                    std::cin >> grade;
                    if(grade == 0){
                        in_view_students = false;
                    }
                    else if(grade > 0 && grade < 7){
                        if(gradetotals[grade-1] == 0){
                            std::cout << "There are no students in that grade." << std::endl;
                        }
                        else if(gradetotals[grade-1] == 1){
                            std::cout << "The student in grade " << grade << " is: " << student_enrollment[grade-1][0] << std::endl;
                        }
                        else{
                            std::cout << "The students in grade " << grade << " are: ";
                            for(int i = 0; i < gradetotals[grade-1]; i++){
                                std::cout << student_enrollment[grade-1][i];
                                if(i == gradetotals[grade-1]-1){
                                    std::cout << "." << std::endl;
                                }
                                else if(i == gradetotals[grade-1]-2){
                                    std::cout << ", and ";
                                }
                                else{
                                    std::cout << ", ";
                                }
                            }
                        }
                    }
                    else if(grade == 7){
                        if(gradetotals[0] == 0 && gradetotals[1] == 0 && gradetotals[2] == 0 && gradetotals[3] == 0 && gradetotals[4] == 0 && gradetotals[5] == 0){
                            std::cout << "There are no students currently enrolled." << std::endl;
                        }
                        else{
                            std::cout << "The currently enrolled students are: ";
                            for(int i = 0; i < 6; i++){
                                std::cout << "    starting with grade " << (i + 1) << "  "; 
                                if(gradetotals[i] > 0){
                                    int rankings[gradetotals[i]];
                                    for(int k = 0; k < gradetotals[i]; k++){
                                        rankings[k] = 0;
                                        for(int l = 0; l < gradetotals[i]; l++){
                                            if(k == l){
                                            }
                                            else if (student_enrollment[i][k] > student_enrollment[i][l]){
                                                rankings[k]++;
                                            }
                                            else{
                                            }
                                        }
                                    }
                                    std::cout << "In grade " << (i+1) << ": ";
                                    for(int k = 0; k < gradetotals[i]; k++){ //Working here atm, don't ask what's going on, I don't know
                                        for(int l = 0; l < gradetotals[i]; l++){
                                            if(k == gradetotals[i]){
                                                if(rankings[l] == k){
                                                    if(gradetotals[i] == 1){
                                                        std::cout << student_enrollment[i][l] << ".";
                                                    }
                                                    else if(gradetotals[i] == 2){
                                                        std::cout << " and " << student_enrollment[i][l] << ".";
                                                    }
                                                    else{
                                                        std::cout << ", and " << student_enrollment[i][l] << ".";
                                                    }
                                                }
                                            }
                                            else if(k == 0){
                                                if(rankings[l] == k){
                                                    std::cout << student_enrollment[i][l];
                                                }
                                            }
                                            else{
                                                if(rankings[l] == k){
                                                    std::cout << ", ";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        std::cout << std::endl;
                    }
                    else{
                        std::cout << "Not a valid entry, please try again." << std::endl;
                    }
                }
                break;
            }
            case 'q':
            case 'Q':{
                in_school_grade_loop = false;
                break;
            }
        }
    }
}
void hamming() //Hamming distance.
{
    std::string string_1, string_2;
    std::cout << "Please enter a first string: ";
    std::getline(std::cin, string_1);
    int string_1_length = string_1.length();
    std::cout << "Please enter a second string of length " << string_1_length << ": ";
    std::getline(std::cin, string_2);
    int string_2_length = string_2.length();
    std::cout << "Strings are " << string_1 << " and " << string_2 << std::endl;
    std::cout << "String lengths are " << string_1_length << " and " << string_2_length << std::endl;
    Sleep(2000);
    if(string_1_length == string_2_length){
        int Hamming_distance = 0;
        for(int i = 0; i < string_1_length; i++){
            std::cout << "string_1[i] = " << string_1[i] << " and string_2[i] = " << string_2[i] << std::endl;
            if(string_1[i] != string_2[i]){
                Hamming_distance++;
            }
        }
        std::cout << "The Hamming Distance of the two strings is " << Hamming_distance << std::endl;
        Sleep(1500);
    }
    else{
        std::cout << "Strings are not of the same length." << std::endl;
        Sleep(1500);
    }
}
void nucleotide_count() //Nucleotide count.
{
    std::string string_1;
    std::cout << "Please enter a nucleotide string (should only consist of A, C, G and T): ";
    std::cin.ignore();
    std::getline(std::cin, string_1);
    int A_count = 0, C_count = 0, G_count = 0, T_count = 0;
    bool contains_other = false;
    for(int i = 0; i < string_1.length(); i++){
        switch(string_1[i]){
            case 'A':{
                A_count++;
                break;
            }
            case 'C':{
                C_count++;
                break;
            }
            case 'G':{
                G_count++;
                break;
            }
            case 'T':{
                T_count++;
                break;
            }
            default:{
                contains_other = true;
                break;
            }
        }
    }
    if(contains_other == false){
        std::cout << "'A' count = " << A_count << "  'C' count = " << C_count << "  'G' count = " << G_count << "  'T' count = " << T_count << std::endl;
    }
    else{
        std::cout << "The string contains characters other than A, C, G or T, and therefore is invalid." << std::endl;
    }
    Sleep(2000);
}
void DNA_to_RNA() //DNA to RNA
{
    std::string string_DNA, string_RNA;
    std::cout << "Please enter a nucleotide string (should only consist of A, C, G and T): ";
    std::cin.ignore();
    std::getline(std::cin, string_DNA);
    bool contains_other = false;
    for(int i = 0; i < string_DNA.length(); i++){
        switch(string_DNA[i]){
            case 'A':{
                string_RNA  = string_RNA + 'U';
                break;
            }
            case 'C':{
                string_RNA  = string_RNA + 'G';
                break;
            }
            case 'G':{
                string_RNA  = string_RNA + 'C';
                break;
            }
            case 'T':{
                string_RNA  = string_RNA + 'A';
                break;
            }
            default:{
                contains_other = true;
                break;
            }
        }
    }
    if(contains_other == false){
        std::cout << "The corresponding RNA string is " << string_RNA << std::endl;
    }
    else{
        std::cout << "The string contains characters other than A, C, G or T, and therefore is invalid." << std::endl;
    }
    Sleep(2000);
}
void collatz() //Collatz Conjecture.
{
    int input, steps = 0;
    std::cout << "Please enter an positive integer to begin: ";
    std::cin >> input;
    if(input > 0){
        while(input > 1){
            if(input%2 == 0){
                input = input/2;
                steps++;
            }
            else{
                input = (3*input) + 1;
                steps++;
            }
            if(input > 1){
                std::cout << input << "   ";
            }
        }
        std::cout << input << "   " << std::endl;
        std::cout << "Reaching 1 took " << steps << " steps." << std::endl;
    }
    else{
        std::cout << "That is not a positive integer, so the code cannot run." << std::endl;
    }
    Sleep(2000);
}
void difference_of_squares() //Difference of squares.
{
    int integer, sum = 0, square_sum = 0;
    std::cout << "Enter a positive integer: ";
    std::cin >> integer;
    if(integer > 0){
        for(int i = 0; i < integer; i++){
            sum = sum + i + 1;
            square_sum = square_sum + ((i + 1) * (i + 1));
        }
        sum = sum * sum;
        std::cout << "The sqaure of the sum of the first " << integer << " integers is " << sum << ", while the sum of the squares is " << square_sum << "." << std::endl;
        std::cout << "The difference between the two squares is " << sum - square_sum << "." << std::endl;
    }
    else{
        std::cout << "That is not a positive integer, so the code cannot run." << std::endl;
    }
}
void Nth_prime() //Nth Prime.
{
    int N, primes_found = 0, number_checking = 2;
    bool found_Nth_prime = false;
    std::cout << "Enter a positive integer: ";
    std::cin >> N;
    if(N > 0){
        int start_time = std::time(NULL);
        std::cout << "The prime numbers are:";
        while(found_Nth_prime == false){
            bool is_prime = true;
            for(int i = 2; i < (number_checking+1); i++){
                if((number_checking%i == 0) && (i != number_checking)){
                    is_prime = false;
                }
            }
            if(is_prime == true){
                primes_found++;
                std::cout << "  " << number_checking;
            }
            if(primes_found == N){
                found_Nth_prime = true;
            }
            else{
                number_checking++;
            }
        }
        int end_time = std::time(NULL) - start_time;
        std::cout << "." << std::endl << "Therefore the " << N << " position prime is " << number_checking << std::endl;
        std::cout << "Finding these primes took " << end_time << " seconds by the brute force method." << std::endl;
        system("pause");
        primes_found = 0, number_checking = 2, found_Nth_prime = false;
        int *prime_array = new int[N];
        int start_time_2 = std::time(NULL);
        std::cout << "The prime numbers are:";
        for(int i = 0; i < N; i++){
            prime_array[i] = 0;
        }
        while(found_Nth_prime == false){
            bool is_prime = true;
            for(int i = 0; i < (primes_found); i++){
                if(number_checking%prime_array[i] == 0){
                    is_prime = false;
                }
            }
            if(is_prime == true){
                prime_array[primes_found] = number_checking;
                primes_found++;
                std::cout << "  " << number_checking;
            }
            if(primes_found == N){
                found_Nth_prime = true;
            }
            else{
                number_checking++;
            }
        }
        int end_time_2 = std::time(NULL) - start_time_2;
        delete[] prime_array;
        std::cout << "." << std::endl << "Therefore the " << N << " position prime is " << number_checking << std::endl;
        std::cout << "Finding these primes took " << end_time_2 << " seconds by the new method." << std::endl;
        system("pause");
    }
    else{
        std::cout << "That is not a positive integer, so the code cannot run." << std::endl;
    }
}
int Nth_prime_return(int N)
{
    int primes_found = 0, number_checking = 2;
    bool found_Nth_prime = false;
    int *prime_array = new int[N];
    for(int i = 0; i < N; i++){
        prime_array[i] = 0;
    }
    while(found_Nth_prime == false){
        bool is_prime = true;
        for(int i = 0; i < (primes_found); i++){
            if(number_checking%prime_array[i] == 0){
                is_prime = false;
            }
        }
        if(is_prime == true){
            prime_array[primes_found] = number_checking;
            primes_found++;
        }
        if(primes_found == N){
            found_Nth_prime = true;
        }
        else{
            number_checking++;
        }
    }
    int return_value = prime_array[N-1];
    delete[] prime_array;
    return return_value;
}
void queen_attack() //Queen attack.
{
    int white_x, white_y, black_x, black_y;
    bool can_attack = false;
    std::cout << "Enter the x position of the white queen (1-8, top left (1,1)): ";
    std::cin >> white_x;
    std::cout << "Enter the y position of the white queen (1-8, top left (1,1)): ";
    std::cin >> white_y;
    std::cout << "Enter the x position of the black queen (1-8, top left (1,1)): ";
    std::cin >> black_x;
    std::cout << "Enter the y position of the black queen (1-8, top left (1,1)): ";
    std::cin >> black_y;
    if((white_x == black_x) && (white_y == black_y)){
        std::cout << "Invalid entry, the pieces have been placed on top of one another." << std::endl;
    }
    else if((white_x > 0) && (white_x < 9) && (white_y > 0) && (white_y < 9) && (black_x > 0) && (black_x < 9) && (black_y > 0) && (black_y < 9)){
        for(int x = 1; x < 9; x++){
            for(int y = 1; y < 9; y++){
                if(x == white_x && y == white_y){
                    std::cout << " W ";
                }
                else if(x == black_x && y == black_y){
                    std::cout << " B ";
                }
                else{
                    std::cout << " _ ";
                }
            }
            std::cout << std::endl;
        }
        if((white_x == black_x) || (white_y == black_y) || (abs(white_x - black_x) == abs(white_y - black_y))){
            can_attack = true;
        }
        if(can_attack == true){
            std::cout << "The queens can attack each other." << std::endl;
        }
    }
    else{
        if((white_x < 1) || (white_x > 8)){
            std::cout << "Invalid position. The white x coordinate is out of bounds." << std::endl;
        }
        if((white_y < 1) || (white_y > 8)){
            std::cout << "Invalid position. The white y coordinate is out of bounds." << std::endl;
        }
        if((black_x < 1) || (black_x > 8)){
            std::cout << "Invalid position. The black x coordinate is out of bounds." << std::endl;
        }
        if((black_y < 1) || (black_y > 8)){
            std::cout << "Invalid position. The black x coordinate is out of bounds." << std::endl;
        }
    }
}
void sieve_of_eratosthenes() //Sieve of Eratosthenes.
{
    int N;
    std::cout << "Enter a positive integer greater than 1: ";
    std::cin >> N;
    if(N > 1){
        int number_list[N-1];
        bool prime_list[N-1];
        for(int i = 0; i < (N-1); i++){
            number_list[i] = i + 2;
            prime_list[i] = true;
        }
        for(int i = 0; i < (N-1); i++){
            if(prime_list[i] == true){
                int multiples = 2;
                while((number_list[i]*multiples) <= N){
                    prime_list[(number_list[i]*multiples) - 2] = false;
                    multiples++;
                }
            }
        }
        std::cout << "The prime numbers are: " << std::endl;
        for(int i = 0; i < (N-1); i++){
            if(prime_list[i] == true){
                std::cout << number_list[i] << " ";
            }
        }
        std::cout << "." << std::endl;
    }
    else{
        std::cout << "That is not a positive integer greater than 1, so the code cannot run." << std::endl;
    }
}
void integer_to_english() //Integer to English.
{
    long long entry, digits = 0, top_digits = 0, chunks = 0, count = 1;
    std::cout << "Enter an integer between 0 and 999,999,999,999: ";
    std::cin >> entry;
    std::string singles[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string blocks[4] = {"hundred", "thousand", "million", "billion"};
    if((entry >= 0) && (entry < 1000000000000)){
        if(entry == 0){
            std::cout << "Zero" << std::endl;
        }
        else{
            while(digits == 0){
                if((entry/pow(10, count)) < 1){
                    digits = count;
                }
                else{
                    count++;
                }
            }
            int entry_digits[digits];
            for(int i = 0; i < digits; i++){
                entry_digits[i] = entry%10;
                entry = entry/10;
                std::cout << entry_digits[i] << " ";
            }
            std::cout << std::endl;
            /*std::string EntryAsString = std::to_string((long long) entry);// see if that works ;)
            std::cout << EntryAsString << std::endl;*/
            chunks = ((digits-1)/3) + 1;
            top_digits = digits - (3*(chunks-1));
            std::cout << "The number has " << digits << " digits in " << chunks << " chunks, with " << top_digits << " digits in the top chunk." << std::endl;
            for(int i = 0; i < chunks; i++){
                if(i == 0){ //Top level chunk
                    if(top_digits == 1){ //If single digit in top chunk
                        std::cout << singles[entry_digits[digits-1]-1];
                    }
                    else if(top_digits == 2){ //If two digits in top chunk
                        if(entry_digits[digits-2] == 1){ // 10-19
                            std::cout << teens[entry_digits[digits-2]];
                        }
                        else{ //20-99
                            std::cout << tens[entry_digits[digits-1]-2];
                            if(entry_digits[digits-2] != 0){
                                std::cout << " " << singles[entry_digits[digits-2]-1];
                            }
                        }
                    }
                    else{ //If three digits in top chunk
                        std::cout << singles[entry_digits[digits-1]-1] << " " << blocks[0];
                        if(entry_digits[digits-2] != 0){ //If there's a tens number, copy from above
                            if(entry_digits[digits-2] == 1){
                                std::cout << " and " << teens[entry_digits[digits-3]];
                            }
                            else{
                                std::cout << " and " << tens[entry_digits[digits-2]-2];
                                if(entry_digits[digits-3] != 0){
                                    std::cout << " " << singles[entry_digits[digits-3]-1];
                                }
                            }
                        }
                        else if(entry_digits[digits-3] != 0){ //If there's only a singles number
                            std::cout << " and " << singles[entry_digits[digits-3]-1];
                        }
                    }
                    if(chunks > 1){
                        std::cout << " " << blocks[chunks-1];
                    }
                }
                else{ //Generic other chunks
                    if(entry_digits[digits-top_digits-1-(3*(i-1))] != 0 || entry_digits[digits-top_digits-2-(3*(i-1))] != 0 || entry_digits[digits-top_digits-3-(3*(i-1))] != 0){
                        std::cout << ",";
                    }
                    if(entry_digits[digits-top_digits-1-(3*(i-1))] != 0){
                        std::cout << " " << singles[entry_digits[digits-top_digits-1-(3*(i-1))]-1] << " " << blocks[0];
                    }
                    if(entry_digits[digits-top_digits-2-(3*(i-1))] != 0){
                        if(entry_digits[digits-top_digits-1-(3*(i-1))] != 0){
                            std::cout << " and";
                        }
                        if(entry_digits[digits-top_digits-2-(3*(i-1))] == 1){
                            std::cout << " " << teens[entry_digits[digits-top_digits-3-(3*(i-1))]] << " ";
                        }
                        else{
                            std::cout << " " << tens[entry_digits[digits-top_digits-2-(3*(i-1))]-2];
                            if(entry_digits[digits-top_digits-3-(3*(i-1))] != 0){
                                std::cout << " " << singles[entry_digits[digits-top_digits-3-(3*(i-1))]-1];
                            }
                        }
                    }
                    else if(entry_digits[digits-top_digits-3-(3*(i-1))] != 0){
                        if(entry_digits[digits-top_digits-1-(3*(i-1))] != 0 || i == (chunks-1)){
                            std::cout << " and";
                        }
                        std::cout << " " << singles[entry_digits[digits-top_digits-3-(3*(i-1))]-1];
                    }
                    if(chunks-i == 3 && (entry_digits[digits-top_digits-1-(3*(i-1))] != 0 || entry_digits[digits-top_digits-2-(3*(i-1))] != 0 || entry_digits[digits-top_digits-3-(3*(i-1))] != 0)){
                        std::cout << " " << blocks[2];
                    }
                    if(chunks-i == 2 && (entry_digits[digits-top_digits-1-(3*(i-1))] != 0 || entry_digits[digits-top_digits-2-(3*(i-1))] != 0 || entry_digits[digits-top_digits-3-(3*(i-1))] != 0)){
                        std::cout << " " << blocks[1];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "The entered number lies outside the range of 0 to 999,999,999,999, therefore the program cannot run." << std::endl;
    }
}
void add_gigasecond()
{
    int year, month, day, hour, minute, second, day_ender;
    bool enter_year = true, enter_month = true, enter_day = true, enter_hour = true, enter_minute = true, enter_second = true;
    std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string endings[4] = {"st", "nd", "rd", "th"};
    std::cout << "Enter a date and time, from which the date and time one gigasecond in the future will be calculated." << std::endl;
    while(enter_year == true){
        std::cout << "Please enter a year: ";
        std::cin >> year;
        if(year > 0 || year < 0){
            enter_year = false;
        }
        else{
            std::cout << "Not a valid year, please try again." << std::endl;
        }
    }
    while(enter_month == true){
        std::cout << "Please enter a month: ";
        std::cin >> month;
        if(month > 0 && month < 12){
            enter_month = false;
        }
        else{
            std::cout << "Not a valid month, please try again." << std::endl;
        }
    }
    while(enter_day == true){
        std::cout << "Please enter a day: ";
        std::cin >> day;
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day > 0 && day < 32){
                enter_day = false;
            }
            else{
                std::cout << "Not a valid day, please try again." << std::endl;
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day > 0 && day < 31){
                enter_day = false;
            }
            else{
                std::cout << "Not a valid day, please try again." << std::endl;
            }
        }
        else{
            if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
                if(day > 0 && day < 30){
                    enter_day = false;
                }
                else{
                    std::cout << "Not a valid day, please try again." << std::endl;
                }
            }
            else{
                if(day > 0 && day < 29){
                    enter_day = false;
                }
                else{
                    std::cout << "Not a valid day, please try again." << std::endl;
                }
            }
        }
        if(day == 1 || day == 21 || day == 31){
            day_ender = 0;
        }
        else if(day == 2 || day == 22){
            day_ender = 1;
        }
        else if(day == 3 || day == 23){
            day_ender = 2;
        }
        else{
            day_ender = 3;
        }
    }
    while(enter_hour == true){
        std::cout << "Please enter a hour: ";
        std::cin >> hour;
        if(hour >= 0 && hour < 24){
            enter_hour = false;
        }
        else{
            std::cout << "Not a valid hour value, please try again." << std::endl;
        }
    }
    while(enter_minute == true){
        std::cout << "Please enter a minute: ";
        std::cin >> minute;
        if(minute >= 0 && minute < 60){
            enter_minute = false;
        }
        else{
            std::cout << "Not a valid minute value, please try again." << std::endl;
        }
    }
    while(enter_second == true){
        std::cout << "Please enter a second: ";
        std::cin >> second;
        if(second >= 0 && second < 60){
            enter_second = false;
        }
        else{
            std::cout << "Not a valid seconds value, please try again." << std::endl;
        }
    }
    system("cls");
    std::cout << "The entered time and date is: ";
    if(hour < 10){
        std::cout << "0";
    }
    std::cout << hour << ":";
    if(minute < 10){
        std::cout << "0";
    }
    std::cout << minute << ":";
    if(second < 10){
        std::cout << "0";
    }
    std::cout << second << " on the " << day << endings[day_ender] << " of " << months[month-1] << " " << year << "." << std::endl;
    second = second + 1000000000;
    while(second > 60){
        second = second - 60;
        minute++;
        if(minute >= 60){
            minute = 0;
            hour++;
        }
        if(hour >= 24){
            hour = 0;
            day++;
        }
        if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
            if(month == 2){
                if(day > 29){
                    day = 1;
                    month++;
                }
            }
            else if(day > days_in_month[month-1]){
                day = 1;
                month++;
            }
        }
        else{
            if(day > days_in_month[month-1]){
                day = 1;
                month++;
            }
        }
        if(month > 12){
            month = 1;
            year++;
        }
    }
    std::cout << "The time and date after 1 gigayear is: ";
    if(hour < 10){
        std::cout << "0";
    }
    std::cout << hour << ":";
    if(minute < 10){
        std::cout << "0";
    }
    std::cout << minute << ":";
    if(second < 10){
        std::cout << "0";
    }
    std::cout << second << " on the " << day << endings[day_ender] << " of " << months[month-1] << " " << year << "." << std::endl;
}
void binary_wink()
{
    std::cout << "Please enter a number between 1 and 31: ";
    int entry;
    std::string outputs[4] = {"wink", "double blink", "close your eyes", "jump"};
    std::cin >> entry;
    if(entry > 0 && entry < 32){
        bool binary[5] = {0,0,0,0,0};
        for(int i = 0; i < 5; i++){
            if(entry >= (16/int(pow(2,i)))){
                binary[i] = 1;
                entry -= (16/int(pow(2,i)));
            }
        }
        std::cout << "The binary output is: ";
        for(int i = 0; i < 5; i++){
            std::cout << binary[i];
        }
        std::cout << std::endl;
        if(binary[0] == false){
            for(int i = 0; i < 4; i++){
                if(binary[4-i] == true){
                    std::cout << outputs[i] << "  ";
                }
            }
        }
        else{
            for(int i = 0; i < 4; i++){
                if(binary[i+1] == true){
                    std::cout << outputs[3-i] << "  ";
                }
            }
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "Invalid entry. Number is outside the range of 1 to 15." << std::endl;
    }
}
void allergies()
{
    std::cout << "Please enter an allergy number: ";
    int entry;
    std::string allergies[8] = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
    std::cin >> entry;
    entry = entry%256;
    if(entry > 0){
        std::cout << "The patient is allergic to: ";
        for(int i = 0; i < 8; i++){
            if(entry >= (128/int(pow(2,i)))){
                std::cout << "  " << allergies[7-i];
                entry -= (128/int(pow(2,i)));
            }
        }
        std::cout << "." << std::endl;
    }
    else{
        std::cout << "The patient has none of the stored allergies." << std::endl;
    }
}
void protein_translation()
{
    std::cout << "Enter RNA string: ";
    std::string sequence;
    std::cin >> sequence;
    std::string codons[17] = {"AUG", "UUU", "UUC", "UUA", "UUG", "UCU", "UCC", "UCA", "UCG", "UAU", "UAC", "UGU", "UGC", "UGG", "UAA", "UAG", "UGA"};
    std::string proteins[7] = {"Methionine", "Phenylalanine", "Leucine", "Serine", "Tyrosine", "Cysteine", "Tryptophan"};
    if(sequence.length()%3 == 0){
        int number = sequence.length()/3, read = 0;
        std::cout << "Protein string is:";
        while(read < number){
            std::string section = sequence.substr((3*read), 3);
            if((section == "AUG")){
                std::cout << "  " << proteins[0];
            }
            else if((section == "UUU") || (section == "UUC")){
                std::cout << "  " << proteins[1];
            }
            else if((section == "UUA") || (section == "UUG")){
                std::cout << "  " << proteins[2];
            }
            else if((section == "UCU") || (section == "UCC") || (section == "UCA") || (section == "UCG")){
                std::cout << "  " << proteins[3];
            }
            else if((section == "UAU") || (section == "UAC")){
                std::cout << "  " << proteins[4];
            }
            else if((section == "UGU") || (section == "UGC")){
                std::cout << "  " << proteins[5];
            }
            else if((section == "UGG")){
                std::cout << "  " << proteins[6];
            }
            else if((section == "UAA") || (section == "UAG") || (section == "UGA")){
                read = number;
            }
            read++;
        }
        std::cout << "." << std::endl;
    }
    else{
        std::cout << "Not a valid RNA string; strings should be composed of a series of blocks of 3." << std::endl;
    }
}
void sum_of_multiples()
{
    bool number_loop = true;
    int number;
    while(number_loop){
        number = int_inputter("Please enter an integer with a value of 3 or more: ");
        if(number < 3){
            std::cout << "Error, entered number must be 3 or more." << std::endl;
        }
        else{
            number_loop = false;
        }
    }
    int multiple1 = int_value_checker("Please enter a positive integer below the first entered number: ", 0, number);
    bool multiple_2_loop = true;
    int multiple2;
    while(multiple_2_loop){
        multiple2 = int_value_checker("Please enter a different positive integer below the first entered number: ", 0, number);
        if(multiple1 == multiple2){
            std::cout << "Error, please enter different numbers." << std::endl;
        }
        else{
            multiple_2_loop = false;
        }
    }
    int sum = 0;
    for(int i = 1; i < number; i++){
        if((i%multiple1 == 0) || (i%multiple2 == 0)){
            sum += i;
        }
    }
    std::cout << "The sum of the multiples is " << sum << "." << std::endl;
}
void prime_factors()
{
    bool input_loop = true;
    int number;
    while(input_loop){
        number = int_inputter("Please enter a positive integer above 1: ");
        if(number < 2){
            //std::cout << "Error, please enter a positive number above." << std::endl;
        }
        else{
            input_loop = false;
        }
    }
    std::vector<int> prime_factors;
    int factor = 2, primes = 1, tracker = number;
    while(factor <= number){
        if(number%factor == 0){
            number /= factor;
            prime_factors.push_back(factor);
        }
        else{
            ++primes;
            factor = Nth_prime_return(primes);
        }
    }
    std::cout << "The prime factors of " << tracker << " are: ";
    for(int elem : prime_factors){
        std::cout << elem << "  ";
    }
    std::cout << std::endl;
}
void bottles_of_beer()
{
    int bottles = int_value_checker("Please enter an integer between 1 and 99: ", 1, 99), record = bottles;
    while(bottles > 0){
        std::cout << bottles << " bottles of beer on the wall, " << bottles << " bottles of beer." << std::endl;
        if(bottles > 2){
            std::cout << "Take one down and pass it around, " << --bottles << " bottles of beer on the wall." << std::endl;
        }
        else if(bottles == 2){
            std::cout << "Take one down and pass it around, " << --bottles << " bottle of beer on the wall." << std::endl;
        }
        else if(bottles == 1){
            --bottles;
            std::cout << "Take it down and pass it around, no more bottles of beer on the wall." << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "No more bottles of beer on the wall, no more bottles of beer." << std::endl;
    std::cout << "Go to the store and buy some more, " << record << " bottles of beer on the wall." << std::endl;
}
void atbash()
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char reverse[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    std::string input_text, output_text;
    int response = int_value_checker("Press 0 to encrypt text, or 1 to decript text: ", 0, 1);
    if(response == 0){
        std::cout << "Enter some text to be ciphered: ";
        std::getline(std::cin, input_text);
        input_text.erase(std::remove_if(input_text.begin(), input_text.end(), isspace), input_text.end());
        std::for_each(input_text.begin(), input_text.end(), [](char& c){c = std::tolower(c);});
        int counter = 0;
        for(int i = 0; i < input_text.length(); i++){
            if(counter%5 == 0){
                output_text += " ";
            }
            for(int k = 0; k < 26; k++){
                if(input_text.at(i) == alphabet[k]){
                    output_text += reverse[k];
                    counter++;
                }
            }
        }
        std::cout << "The ciphered text is: " << output_text << std::endl;
    }
    else{
        std::cout << "Enter some text to be deciphered: ";
        std::getline(std::cin, input_text);
        input_text.erase(std::remove_if(input_text.begin(), input_text.end(), isspace), input_text.end());
        std::for_each(input_text.begin(), input_text.end(), [](char& c){c = std::tolower(c);});
        for(int i = 0; i < input_text.length(); i++){
            for(int k = 0; k < 26; k++){
                if(input_text.at(i) == reverse[k]){
                    output_text += alphabet[k];
                }
            }
        }
        std::cout << "The deciphered text is: " << output_text << std::endl;
    }
}
void trinary_to_decimal()
{
    std::string trinary;
    std::cout << "Please input a trinary string: ";
    std::getline(std::cin, trinary);
    bool is_valid = true;
    int value = 0;
    for(int i = 0; i < trinary.length(); i++){
        if((trinary.at(i) == '0') || (trinary.at(i) == '1') || (trinary.at(i) == '2')){}
        else{
            is_valid = false;
        }
    }
    if(is_valid){
        for(int i = 0; i < trinary.length(); i++){
            int digit;
            if((trinary.at(trinary.length()-1-i) == '0')){digit = 0;}
            if((trinary.at(trinary.length()-1-i) == '1')){digit = 1;}
            if((trinary.at(trinary.length()-1-i) == '2')){digit = 2;}
            value += (digit*pow(3, i));
        }
    }
    std::cout << "The decimal value of the trinary is " << value << "." << std::endl;
}
void phone_number()
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::string raw_number, final_number;
    std::cout << "Please enter a phone number: ";
    std::getline(std::cin, raw_number);
    raw_number.erase(std::remove_if(raw_number.begin(), raw_number.end(), isspace), raw_number.end());
    for(int i = 0; i < raw_number.length(); i++){
        for(int k = 0; k < 10; k++){
            if(raw_number.at(i) == numbers[k]){
                final_number += numbers[k];
            }
        }
    }
    if(((final_number.length() == 10) || ((final_number.length() == 11) && (final_number.at(0) == '1'))) && (final_number.at(final_number.length()-10) != '0') && (final_number.at(final_number.length()-10) != '1') && (final_number.at(final_number.length()-7) != '0') && (final_number.at(final_number.length()-7) != '1')){
        if(final_number.length() == 11){
            final_number.erase(final_number.begin());
        }
        std::cout << final_number << std::endl;
    }
    else{
        std::cout << "That is not a valid NANP number." << std::endl;
    }
}