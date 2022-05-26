#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ < 2) {
      return;
    }
    Node* c = front_;
    Node* p = nullptr;
    while (c != nullptr) {
      Node* next = c->next;
      c->next = p;
      p = c;
      c = next;
    }
    std::swap(back_, front_);
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    std::swap(front_, back_);
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr != nullptr) {
      reverse_recursive_helper(curr->next, curr);
      curr->next = prev;
    }
  }

}  // namespace assignment