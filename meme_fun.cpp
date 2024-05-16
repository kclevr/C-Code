/*
 *This coding program is a extra credit assignment
 *It allows a user to enter a value and the program will look through a wordlist and try to find a word where
 *the sum of its charaters add up to the value entered by the user.
 * 
 * katelyn clevenger
 * u1219714
 * December 12, 2018
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

int main ()
{
  //Need a loop that will read in a word from file and then save the word into 
  //array.

  std::ifstream data("words.txt");
  std::string word;
  data >> word;
  std::vector<std::string> word_list;

  bool isDone = false;
  int pos = 0;
  char character;

  //This will read through the file and enter the words into an array
  while(!isDone)
    {
      data >> word;
      word_list.push_back(word);
     
      if (data.fail())
	{
	  isDone = true;
	  break;
	}
     
    }

  //Get the size of the vector
  int array_length = word_list.size();
  std::cout << array_length << std::endl;
  
  std::cout << "Enter a number." << std::endl;
  std::cout << "If you wish to exit the program type exit." << std:: endl.

  //Have the user enter a number and the program will spit out the first word
  //in the array where the sum of its components match the value entered by
  //the user.


 bool user_isDone = false;
 int int_input;
  while(!user_isDone)
    {
  std::string input;
  std::cout << "Enter a number: ";
  std::cin >> input;
   
  
  // object from the class stringstream 
  //converts the string input into a integer
  std:: stringstream geek(input);  
  int int_input = 0; 
  geek >> int_input; 
  
 
  //std::cout << int_input << std::endl;
 
 if (input == "exit" )
    {
      user_isDone = true;
      continue;
    }

  //for each value user enter search the array for word whose letters add up to 
  //the number entered.
  char lower_alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char upper_alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  //check  each word in word list to see if a word matches the sum.
  int list_pos = 0;
  bool checked_array = false;
 while(!checked_array)
  
    {
      //didn't find any word that matches the inputed value
      if(list_pos == array_length)
	{
	  checked_array = true;
	  std::cout << "There is no word that matches the number entered." << std::endl;
	  break;
	}

      //searches throught the word_list to find a word that matches the value inputed
      std::string word_value  = word_list[list_pos];
      int sum = 0;
      int word_pos;
      //std::cout<< word_value << std::endl;
  for(word_pos = 0; word_pos < word_value.size(); word_pos++)
     {
	  for(int pos = 0; pos < 26; pos++)
	    {
	      if ( word_value[word_pos] == lower_alph[pos])
		{
		  sum = sum + (pos + 1);
		  
		}
	      if ( word_value[word_pos] == upper_alph[pos])
	        {
	          sum = sum + (pos + 1);
		}
	    }
      }
 

  //found a word that matches the inputed value.
 if(int_input == sum)
    {
      std::cout << "found a matching word is " << word_value << std::endl;
      checked_array = true;
      list_pos = 0;
      break;
    }
 list_pos++;
    }


}
}

    
