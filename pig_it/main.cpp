#include <iostream>
#include <vector>

//Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

std::string pig_it(std::string str)
{
  std::vector<std::string> words;
  while(!str.empty())
  {
    size_t word_end = str.find_first_of(' ');
    if(word_end == std::string::npos)
    {
      words.push_back(str);
      break;
    }
    words.push_back(str.substr(0, word_end));
    str = str.substr(word_end + 1, str.size() - word_end);
  }

  std::string result;
  for(const auto& word : words)
  {
    if(word.size() == 1)
    {
        if(word.find_first_of(",.?!") == std::string::npos)
        {
            result += word + "ay" + " ";
        }
        else
        {
            result += word + " ";
        }
        continue;
    }
    result += word.substr(1, word.size() - 1) + word[0] + "ay" + " ";
  }
  result.erase(result.size() - 1, 1);
  return result;
}

int main()
{
    std::cout << pig_it("this is test string") <<std::endl;
    std::cout << pig_it("this ! test string") <<std::endl;
    std::cout << pig_it("this is test ?") <<std::endl;
    std::cout << pig_it("o this is test o") <<std::endl;

    return 0;
}
