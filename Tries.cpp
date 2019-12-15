//
// Created by mrue on 12/15/19.
//

#include <iostream>

// define character size
#define CHAR_SIZE 128

// A Class representing a Trie node
class Trie
{
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];

    // Constructor
    Trie()
    {
        this->isLeaf = false;

        for (int i = 0; i < CHAR_SIZE; i++)
            this->character[i] = nullptr;
    }

    void insert(std::string);
    bool deletion(Trie*&, std::string);
    bool search(std::string);
    bool haveChildren(Trie const*);
};

// Iterative function to insert a key in the Trie
void Trie::insert(std::string key)
{
    // start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]] == nullptr)
            curr->character[key[i]] = new Trie();

        // go to next node
        curr = curr->character[key[i]];
    }

    // mark current node as leaf
    curr->isLeaf = true;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::search(std::string key)
{
    // return false if Trie is empty
    if (this == nullptr)
        return false;

    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // go to next node
        curr = curr->character[key[i]];

        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return false;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return true
    return curr->isLeaf;
}

// returns true if given node has any children
bool Trie::haveChildren(Trie const* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;	// child found

    return false;
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(Trie*& curr, std::string key)
{
    // return if Trie is empty
    if (curr == nullptr)
        return false;

    // if we have not reached the end of the key
    if (key.length())
    {
        // recur for the node corresponding to next character in the key
        // and if it returns true, delete current node (if it is non-leaf)

        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }

    // if we have reached the end of the key
    if (key.length() == 0 && curr->isLeaf)
    {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(curr))
        {
            // delete current node
            delete curr;
            curr = nullptr;

            // delete non-leaf parent nodes
            return true;
        }

            // if current node is a leaf node and have children
        else
        {
            // mark current node as non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;

            // don't delete its parent nodes
            return false;
        }
    }

    return false;
}

