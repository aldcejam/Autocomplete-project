#include <iostream>
#include <string>
#include "classes/autocomplete/Autocomplete.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <dataset> <k>" << std::endl;
        return 1;
    }

    std::string dataset = argv[1];
    int limit = std::stoi(argv[2]);


    try {
        Autocomplete autocomplete(dataset);

        std::string query;
        while (true) {
            std::cout << "Enter the term to be auto-completed: (type \"exit\" to end the program): " << std::endl;
            std::getline(std::cin, query);

            if (query == "exit") {
                break;
            }
            std::transform(query.begin(), query.end(), query.begin(), ::tolower);
            autocomplete.autocomplete(query, limit);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
