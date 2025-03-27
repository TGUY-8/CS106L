#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  //use find_ all and isspace to get all iterators
  auto space_pointers = find_all(source.begin(), source.end(), isspace);

  //use lambda to generate tokens between consecutive space characters
 auto getToken = [source] (auto begin, auto end)
 { Token token{source, begin, end};
   return token;};

   //get a set to store all the tokens
 Corpus tokens;
 std::insert_iterator ins(tokens, tokens.end());

 //use transform to write to token-set
 std::transform(space_pointers.begin(), space_pointers.end() - 1, space_pointers.begin() + 1, ins, getToken);

 std::erase_if(tokens, [](Token token) -> bool { return token.content.empty();});

  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  return std::set<Mispelling>();
};

/* Helper methods */


#include "utils.cpp"