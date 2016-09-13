// file NumberList.h
 
#include <cstddef>   // for NULL
using namespace std;

class NumberList
{ 
   private:
      struct ListNode      // the node data type
      {
         double value;     // data
         ListNode *next;   // ptr to next node
      };
      ListNode *head;      // the list head

   public:
      NumberList();        // creates an empty list
      ~NumberList();

      void appendNode(double);
      void insertNode(double);
      void deleteNode(double);
      void displayList();
};
