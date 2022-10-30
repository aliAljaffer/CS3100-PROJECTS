#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Trie.h"
#include <fstream>
void populateTrie(string, Trie *);
void memTest();
int main()
{
   Trie tr;
   ifstream infile("words.txt");
   string word;
   while (infile >> word)
   {
      tr.insert(word);
   }

   memTest();
   Trie tr2(tr);
   cout << tr.completeCount("a") << endl;
   cout << tr2.completeCount("a") << endl;
}

void populateTrie(string filename, Trie *myTrie)
{
   ifstream infile(filename);
   string word;
   while (infile >> word)
   {
      myTrie->insert(word);
   }
}

void memTest()
{
   Trie *tr = new Trie;
   populateTrie("words.txt", tr);
   system("pause");
}

// MAIN METHOD
// int main()
// {
//    Trie *tr = new Trie;
//    populateTrie("words.txt", tr);

//    vector<string> result;
//    while (1)
//    {
//       string userWord;
//       string userAnswer;
//       cout << "Enter a word you'd like to autocomplete (enter \"byebye\" to terminate)" << endl;
//       cin >> userWord;
//       if (userWord == "byebye")
//          return 0;
//       result = tr->complete(userWord);
//       int numWords = result.size();
//       if (numWords)
//       {
//          cout << "There are " << to_string(numWords) << " words that start with " << userWord << endl;
//          cout << "Would you like to display them?" << endl;
//          cin >> userAnswer;
//       }
//       else
//          cout << "There are no words that start with " << userWord << endl;
//       if (userAnswer == "byebye")
//          return 0;
//       if (userAnswer[0] == 'Y' || userAnswer[0] == 'y')
//       {
//          cout << "----------------" << endl;
//          for (auto x : result)
//          {
//             cout << "\t" + x << endl;
//          }
//       }
//    }

//    // Trie tr;
//    //  tr.insert("five");
//    //  tr.insert("fire");
//    //  tr.insert("free");
//    //  vector<string> result;
//    //  tr.autocomplete("x", result);
//    //  for (auto x : result)
//    //  {
//    //     cout << "\t" + x << endl;
//    //  }
// }
