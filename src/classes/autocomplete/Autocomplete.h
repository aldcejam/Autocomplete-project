#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <fstream>
#include <sstream>
#include <string>
#include "../term/Term.h"
#include "../../utils/SortedList.h"

class Autocomplete {
private:
    SortedList<Term> terms;
    int binarySearch(const std::string& prefix, int start, int end) const;

public:
    Autocomplete(const std::string& filename);
    void autocomplete(const std::string& prefix, int k);
};

#endif // AUTOCOMPLETE_H
