#include <iostream>
#include <string>
#include <map>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template <typename Iterator>
struct keys_and_values : qi::grammar<Iterator, std::map<double, double>()>
{
    keys_and_values() : keys_and_values::base_type(query)
    {
        query = pair >> *(qi::lit(',') >> pair);
        pair  =  key >> ',' >> value;

        key   = qi::double_;
        value = qi::double_;
    }

    qi::rule<Iterator, std::map<double, double>()> query;
    qi::rule<Iterator, std::pair<double, double>()> pair;
    qi::rule<Iterator, double()> key, value;
};

int main() {
    typedef std::string::const_iterator iterator_type;
    typedef keys_and_values<iterator_type> keys_and_values_grammar;

    keys_and_values_grammar grammar; // Our grammar
    std::string str = "1323.323,32323.232,3232.23,32222.23"; // Input string to parse

    std::map<double, double> result;
    iterator_type iter = str.begin();
    iterator_type end = str.end();
    bool r = qi::parse(iter, end, grammar, result);

    if (r && iter == end) {
        std::cout << "Parsing succeeded\n";
        for (const auto& kv : result) {
            std::cout << "Key: " << kv.first << ", Value: " << kv.second << "\n";
        }
    }
    else {
        std::cout << "Parsing failed\n";
    }

    return 0;
}
