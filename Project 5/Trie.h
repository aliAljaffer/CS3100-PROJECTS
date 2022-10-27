#include <string>
#include <iostream>
#include <exception>
#include <vector>
#pragma once
#define ALPHABET_SIZE 26
using namespace std;
/*
 * Ali Aljaffer - CS3100 - UID: U01006515
 *          Project 4 - AVL Tree
 * A map implementation that uses int:string
 * and its functions are implemented according
 * to the given requirements of the provided PDF.
 */

class Trie
{
private:
   int count;
   int size;
   class TrieNode
   {
   public:
      TrieNode *alphabet[ALPHABET_SIZE];
      bool endOfWordNode;

      TrieNode()
      {
         for (int i = 0; i < ALPHABET_SIZE; i++)
         {
            alphabet[i] = nullptr;
         }
         endOfWordNode = 0;
      }

      ~TrieNode()
      {
         for (int i = ALPHABET_SIZE - 1; i >= 0; i--)
         {
            if (alphabet[i] != nullptr)
            {
               delete alphabet[i];
            }
         }
      }
   };
   TrieNode *root;

public:
   Trie();
   ~Trie();
   Trie(const Trie &);
   bool insert(string);
   int getCount();
   int getSize();
   int getBalance(TrieNode *);
   friend ostream &operator<<(ostream &, const Trie &);
   bool find(int, string &);
   ostream &inorderPrint(ostream &, TrieNode *, int) const;
   std::vector<string> findRange(int, int);
   void findRangeHelper(TrieNode *, int, int, vector<string> &);
   Trie &operator=(const Trie &);
   void copyHelper(TrieNode *, const Trie &);
   TrieNode *SingleRightRotation(TrieNode *);
   TrieNode *SingleLeftRotation(TrieNode *);
   void bulldozer(TrieNode *);
   void updateNodeHeight(TrieNode *);
   bool replaceChild(TrieNode *, TrieNode *, TrieNode *);
   bool setChild(TrieNode *, string, TrieNode *);
};