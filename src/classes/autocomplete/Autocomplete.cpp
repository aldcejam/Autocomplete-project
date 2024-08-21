#include "./Autocomplete.h"

/**
 * @brief Realiza uma busca binária para encontrar o índice inicial dos termos que correspondem ao prefixo dado.
 * 
 * Este método realiza uma busca binária para encontrar o índice do primeiro termo que corresponde ao
 * prefixo dado. Também garante que todos os termos correspondentes sejam incluídos, realizando uma
 * busca para trás a partir do índice encontrado.
 * 
 * @param prefix O prefixo a ser pesquisado nos termos.
 * @param start O índice inicial do intervalo de busca.
 * @param end O índice final do intervalo de busca.
 * @return O índice do primeiro termo que corresponde ao prefixo, ou -1 se nenhum termo for encontrado.
 */
int Autocomplete::binarySearch(const std::string &prefix, int start, int end) const
{
    if (start > end)
        return -1;

    int middle = start + (end - start) / 2;
    Term middleTerm = terms[middle];

    if (middleTerm.getTerm().substr(0, prefix.size()) == prefix)
    {
        int i = middle;
        while (i >= 0 && terms[i].getTerm().substr(0, prefix.size()) == prefix)
        {
            i--;
        }
        return i + 1;
    }
    else if (middleTerm.getTerm().substr(0, prefix.size()) < prefix)
    {
        return binarySearch(prefix, middle + 1, end);
    }
    else
    {
        return binarySearch(prefix, start, middle - 1);
    }
}

/**
 * @brief Constrói um objeto Autocomplete lendo termos e seus pesos de um arquivo.
 * 
 * Este construtor lê termos e seus pesos a partir de um arquivo especificado. Cada linha do arquivo
 * deve conter um peso seguido por uma tabulação e, em seguida, um termo. Os termos são convertidos
 * para minúsculas e armazenados em uma lista ordenada.
 * 
 * @param filename O nome do arquivo contendo os termos e pesos.
 * @throws std::runtime_error Se o arquivo não puder ser aberto.
 */
Autocomplete::Autocomplete(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Error opening file.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::size_t tabPos = line.find('\t');
        if (tabPos != std::string::npos)
        {
            long weight = std::stol(line.substr(0, tabPos));
            std::string term = line.substr(tabPos + 1);
            std::transform(term.begin(), term.end(), term.begin(), ::tolower);

            terms.insert(Term(term, weight));
        }
    }

    terms.sort([](const Term &T1, const Term &T2)
               { return Term::compareByPrefix(T1, T2, T1.getTerm().size()) < 0; });
}

/**
 * @brief Fornece sugestões de autocomplete com base em um prefixo dado.
 * 
 * Este método pesquisa termos que começam com o prefixo especificado e retorna uma lista de
 * sugestões ordenadas por seus pesos. O número de sugestões retornadas é limitado pelo
 * tamanho especificado.
 * 
 * @param prefix O prefixo a ser pesquisado nos termos.
 * @param size O número máximo de sugestões a ser retornado.
 */
void Autocomplete::autocomplete(const std::string &prefix, int size)
{
    int start = binarySearch(prefix, 0, terms.size() - 1);
    if (start == -1)
    {
        std::cout << "No terms found." << std::endl;
        return;
    }

    SortedList<Term> results;
    for (int i = start; static_cast<size_t>(i) < terms.size(); ++i)
    {
        size_t index = static_cast<size_t>(i);
        std::string currentTermPrefix = terms[index].getTerm().substr(0, prefix.size());

        if (currentTermPrefix != prefix)
        {
            break;
        }

        results.insert(terms[i]);
    }

    results.sort([](const Term &T1, const Term &T2)
                 { return Term::compareByWeight(T1, T2) < 0; });

    int limit = std::min(static_cast<size_t>(size), results.size());
    for (int j = 0; j < limit; j++)
    {
        std::cout << results[j] << std::endl;
    }
}
