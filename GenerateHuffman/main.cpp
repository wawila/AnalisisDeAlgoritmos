#include "Test.h"
#include <iostream>
using namespace std;

class BinaryNode
{
public:
  BinaryNode* left;
  BinaryNode* right;
  char symbol;
  int frequency;

  BinaryNode(char symbol, int frequency)
  {
    this->symbol = symbol;
    this->frequency = frequency;
    left = NULL;
    right = NULL;
  }
};

void swap(vector<BinaryNode*>* heap, int father, int son)
{
  BinaryNode* temp = (*heap)[father];
  (*heap)[father] = (*heap)[son];
  (*heap)[son] = temp;
}

int get_father_pos(int son)
{
  if(son % 2 == 0)
    return (son - 2) / 2;
` return (son - 1) / 2;
}

//hijo_izq = pos*2 + 1 => padre = (hijo_izq-1) / 2
//hijo_der = pos*2 + 2 => padre = (hijo_der-2) / 2
void insert_min_heap(vector<BinaryNode*>* heap, BinaryNode* node)
{
  heap->push_back(node);
  int son = heap->size() - 1;
  int father = 0;

  while(son != 0)
  {
    father = get_father_pos(son);

    if((*heap)[son]->frequency > (*heap)[father]->frequency) break;
    swap(heap, father, son);
    son = father;
  }
}

void add_internal_node(vector<BinaryNode*>* heap, BinaryNode* left, BinaryNode* right)
{
  BinaryNode* internal_node = new BinaryNode('.', left->frequency + right->frequency);
  internal_node->left = left;
  internal_node->right = right;

  insert_min_heap(heap, internal_node);
}

void heapify(vector<BinaryNode*>* heap)
{
  int father_pos = 0;
  int left = father_pos*2 + 1;
  int right = father_pos*2 + 2;
  int lowest = 0;

  while(left < heap->size())
  {
    if(right < heap->size()) lowest = (*heap)[left]->frequency < (*heap)[right]->frequency ? left : right;
    else lowest = left;

    if((*heap)[father_pos]->frequency > (*heap)[lowest]->frequency) swap(heap, father_pos, lowest);
    else break;

    father_pos = lowest;
    left = father_pos*2 + 1;
    right = father_pos*2 + 2;
  }
}

BinaryNode* extract_from_top(vector<BinaryNode*>* heap)
{
  BinaryNode* node = (*heap)[0];
  (*heap)[0] = (*heap)[heap->size() - 1];
  heap->erase(heap->end() - 1);

  heapify(heap);
  return node;
}

void backtrack(map<char,string>* answer, BinaryNode* root, string code)
{
    if(!root) return;
    if(root->symbol != '.')
        (*answer)[root->symbol] = code;

    backtrack(answer, root->left, code + "0");
    backtrack(answer, root->right, code + "1");
}

map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
  vector<BinaryNode*> nodes;
  vector<BinaryNode*> min_heap;

  for(int i = 0; i < characters.size(); i++)
  {
    nodes.push_back(new BinaryNode(characters[i], frequencies[i]));
  }

  for(int i = 0; i < nodes.size(); i++)
  {
    insert_min_heap(&min_heap, nodes[i]);
  }

  while(min_heap.size() > 1)
  {
    BinaryNode* left = extract_from_top(&min_heap);
    BinaryNode* right = extract_from_top(&min_heap);
    add_internal_node(&min_heap, left, right);

    // for(int i = 0; i < min_heap.size(); i++)
    // {
    //   cout << min_heap[i]->frequency << endl;
    // }
    // cout << "============================================" << endl;
  }

  map<char,string> answer;
  backtrack(&answer, min_heap[0], "");
  return answer;
}

int main ()
{
    test();
    return 0;
}
